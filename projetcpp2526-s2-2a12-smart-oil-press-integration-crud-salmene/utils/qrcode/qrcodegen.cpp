#include "qrcodegen.hpp"

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
#include <cstring>

namespace qrcodegen {

/*---- QrSegment::Mode ----*/

int QrSegment::Mode::numCharCountBits(int ver) const {
    return numBitsCharCount[(ver + 7) / 17];
}

const QrSegment::Mode QrSegment::NUMERIC      (0x1, 10, 12, 14);
const QrSegment::Mode QrSegment::ALPHANUMERIC (0x2,  9, 11, 13);
const QrSegment::Mode QrSegment::BYTE         (0x4,  8, 16, 16);
const QrSegment::Mode QrSegment::KANJI        (0x8,  8, 10, 12);
const QrSegment::Mode QrSegment::ECI          (0x7,  0,  0,  0);


/*---- QrSegment ----*/

QrSegment::QrSegment(Mode md, int numCh, const std::vector<bool> &dt) :
    mode(md),
    numChars(numCh),
    data(dt) {}

QrSegment QrSegment::makeBytes(const std::vector<std::uint8_t> &data) {
    std::vector<bool> bb;
    for (std::uint8_t b : data) {
        for (int i = 7; i >= 0; i--)
            bb.push_back(((b >> i) & 1) != 0);
    }
    return QrSegment(BYTE, static_cast<int>(data.size()), bb);
}

QrSegment QrSegment::makeNumeric(const char *digits) {
    return QrSegment(NUMERIC, std::strlen(digits), makeNumericBits(digits));
}

QrSegment QrSegment::makeAlphanumeric(const char *text) {
    return QrSegment(ALPHANUMERIC, std::strlen(text), makeAlphanumericBits(text));
}

std::vector<QrSegment> QrSegment::makeSegments(const char *text) {
    if (*text == '\0')
        return {};
    else
        return { makeBytes(std::vector<std::uint8_t>(text, text + std::strlen(text))) };
}

int QrSegment::getTotalBits(const std::vector<QrSegment> &segs, int version) {
    long result = 0;
    for (const QrSegment &seg : segs) {
        int ccbits = seg.mode.numCharCountBits(version);
        if (seg.numChars >= (1 << ccbits))
            return -1;
        result += 4L + ccbits + static_cast<long>(seg.data.size());
        if (result > INT_MAX)
            return -1;
    }
    return static_cast<int>(result);
}

std::vector<bool> QrSegment::makeNumericBits(const char *digits) {
    std::vector<bool> result;
    int accumData = 0;
    int accumCount = 0;
    for (; *digits != '\0'; digits++) {
        if (*digits < '0' || *digits > '9')
            throw std::domain_error("String contains non-numeric characters");
        accumData = accumData * 10 + (*digits - '0');
        accumCount++;
        if (accumCount == 3) {
            for (int i = 9; i >= 0; i--)
                result.push_back(((accumData >> i) & 1) != 0);
            accumData = 0;
            accumCount = 0;
        }
    }
    if (accumCount > 0) {
        int bitCount = accumCount * 3 + 1;
        for (int i = bitCount - 1; i >= 0; i--)
            result.push_back(((accumData >> i) & 1) != 0);
    }
    return result;
}

std::vector<bool> QrSegment::makeAlphanumericBits(const char *text) {
    static const char *ALPHANUMERIC_CHARSET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";
    std::vector<bool> result;
    int accumData = 0;
    int accumCount = 0;
    for (; *text != '\0'; text++) {
        const char *temp = std::strchr(ALPHANUMERIC_CHARSET, *text);
        if (temp == nullptr)
            throw std::domain_error("String contains unencodable characters in alphanumeric mode");
        accumData = accumData * 45 + static_cast<int>(temp - ALPHANUMERIC_CHARSET);
        accumCount++;
        if (accumCount == 2) {
            for (int i = 10; i >= 0; i--)
                result.push_back(((accumData >> i) & 1) != 0);
            accumData = 0;
            accumCount = 0;
        }
    }
    if (accumCount > 0) {
        for (int i = 5; i >= 0; i--)
            result.push_back(((accumData >> i) & 1) != 0);
    }
    return result;
}


/*---- QrCode high-level factory functions ----*/

QrCode QrCode::encodeText(const char *text, Ecc ecl) {
    std::vector<QrSegment> segs = QrSegment::makeSegments(text);
    std::vector<bool> bb;
    for (const QrSegment &seg : segs) {
        for (int i = 3; i >= 0; i--)
            bb.push_back(((seg.mode.modeBits >> i) & 1) != 0);
        int ccbits = seg.mode.numCharCountBits(1);
        for (int i = ccbits - 1; i >= 0; i--)
            bb.push_back(((seg.numChars >> i) & 1) != 0);
        bb.insert(bb.end(), seg.data.begin(), seg.data.end());
    }

    int dataCapacityBits = getNumDataCodewords(1, ecl) * 8;
    for (int i = 0; i < 4 && static_cast<int>(bb.size()) < dataCapacityBits; i++)
        bb.push_back(false);
    while (bb.size() % 8 != 0)
        bb.push_back(false);

    std::vector<std::uint8_t> dataCodewords;
    for (std::size_t i = 0; i < bb.size(); i += 8) {
        std::uint8_t val = 0;
        for (int j = 0; j < 8; j++)
            val = static_cast<std::uint8_t>((val << 1) | (bb.at(i + j) ? 1 : 0));
        dataCodewords.push_back(val);
    }

    static const std::uint8_t padBytes[2] = {0xEC, 0x11};
    for (int i = 0; static_cast<int>(dataCodewords.size()) < getNumDataCodewords(1, ecl); i++)
        dataCodewords.push_back(padBytes[i & 1]);

    return QrCode(1, ecl, dataCodewords, -1);
}

QrCode QrCode::encodeBinary(const std::vector<std::uint8_t> &data, Ecc ecl) {
    return encodeText(reinterpret_cast<const char *>(data.data()), ecl);
}


/*---- QrCode accessors ----*/

int QrCode::getVersion() const {
    return version;
}

int QrCode::getSize() const {
    return size;
}

QrCode::Ecc QrCode::getErrorCorrectionLevel() const {
    return errorCorrectionLevel;
}

int QrCode::getMask() const {
    return mask;
}

bool QrCode::getModule(int x, int y) const {
    return 0 <= x && x < size && 0 <= y && y < size && modules[y][x];
}


/*---- QrCode constructor and helpers ----*/

QrCode::QrCode(int ver, Ecc ecl, const std::vector<std::uint8_t> &dataCodewords, int msk) :
    version(ver),
    size(ver * 4 + 17),
    errorCorrectionLevel(ecl),
    mask(msk),
    modules(size, std::vector<bool>(size)),
    isFunction(size, std::vector<bool>(size)) {

    if (ver < MIN_VERSION || ver > MAX_VERSION)
        throw std::domain_error("Version value out of range");
    if (msk < -1 || msk > 7)
        throw std::domain_error("Mask value out of range");

    drawFunctionPatterns();

    std::vector<std::uint8_t> allCodewords;
    addEccAndInterleave(dataCodewords, allCodewords);
    drawCodewords(allCodewords);

    if (msk == -1) {
        long minPenalty = LONG_MAX;
        for (int i = 0; i < 8; i++) {
            applyMask(i);
            drawFormatBits(i);
            long penalty = getPenaltyScore();
            if (penalty < minPenalty) {
                msk = i;
                minPenalty = penalty;
            }
            applyMask(i);
        }
    }
    assert(0 <= msk && msk <= 7);
    mask = msk;
    applyMask(mask);
    drawFormatBits(mask);
    isFunction.clear();
}

void QrCode::drawFunctionPatterns() {
    for (int i = 0; i < size; i++) {
        setFunctionModule(6, i, i % 2 == 0);
        setFunctionModule(i, 6, i % 2 == 0);
    }

    drawFinderPattern(3, 3);
    drawFinderPattern(size - 4, 3);
    drawFinderPattern(3, size - 4);

    std::vector<int> alignPatPos;
    int numAlign = getAlignmentPatternPositions(version, alignPatPos);
    for (int i = 0; i < numAlign; i++) {
        for (int j = 0; j < numAlign; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == numAlign - 1) || (i == numAlign - 1 && j == 0))
                continue;
            drawAlignmentPattern(alignPatPos[i], alignPatPos[j]);
        }
    }

    drawFormatBits(0);
    drawVersion();
}

void QrCode::drawFormatBits(int msk) {
    int data = static_cast<int>(errorCorrectionLevel) << 3 | msk;
    int rem = data;
    for (int i = 0; i < 10; i++)
        rem = (rem << 1) ^ ((rem >> 9) * 0x537);
    int bits = (data << 10 | rem) ^ 0x5412;

    for (int i = 0; i <= 5; i++) setFunctionModule(8, i, ((bits >> i) & 1) != 0);
    setFunctionModule(8, 7, ((bits >> 6) & 1) != 0);
    setFunctionModule(8, 8, ((bits >> 7) & 1) != 0);
    setFunctionModule(7, 8, ((bits >> 8) & 1) != 0);
    for (int i = 9; i < 15; i++) setFunctionModule(14 - i, 8, ((bits >> i) & 1) != 0);

    for (int i = 0; i < 8; i++) setFunctionModule(size - 1 - i, 8, ((bits >> i) & 1) != 0);
    for (int i = 8; i < 15; i++) setFunctionModule(8, size - 15 + i, ((bits >> i) & 1) != 0);
    setFunctionModule(8, size - 8, true);
}

void QrCode::drawVersion() {
    if (version < 7)
        return;
}

void QrCode::drawFinderPattern(int x, int y) {
    for (int dy = -4; dy <= 4; dy++) {
        for (int dx = -4; dx <= 4; dx++) {
            int dist = std::max(std::abs(dx), std::abs(dy));
            int xx = x + dx, yy = y + dy;
            if (0 <= xx && xx < size && 0 <= yy && yy < size)
                setFunctionModule(xx, yy, dist != 2 && dist != 4);
        }
    }
}

void QrCode::drawAlignmentPattern(int x, int y) {
    for (int dy = -2; dy <= 2; dy++) {
        for (int dx = -2; dx <= 2; dx++)
            setFunctionModule(x + dx, y + dy, std::max(std::abs(dx), std::abs(dy)) != 1);
    }
}

void QrCode::setFunctionModule(int x, int y, bool isBlack) {
    modules[y][x] = isBlack;
    isFunction[y][x] = true;
}

void QrCode::addEccAndInterleave(const std::vector<std::uint8_t> &data, std::vector<std::uint8_t> &result) const {
    result = data;
    int blockEccLen = getEccCodewordsPerBlock(version, errorCorrectionLevel);
    std::vector<std::uint8_t> rsDiv = reedSolomonComputeDivisor(blockEccLen);
    std::vector<std::uint8_t> ecc = reedSolomonComputeRemainder(data, rsDiv);
    result.insert(result.end(), ecc.begin(), ecc.end());
}

void QrCode::drawCodewords(const std::vector<std::uint8_t> &data) {
    int i = 0;
    for (int right = size - 1; right >= 1; right -= 2) {
        if (right == 6)
            right = 5;
        for (int vert = 0; vert < size; vert++) {
            for (int j = 0; j < 2; j++) {
                int x = right - j;
                bool upward = ((right + 1) & 2) == 0;
                int y = upward ? size - 1 - vert : vert;
                if (!isFunction[y][x] && i < static_cast<int>(data.size()) * 8) {
                    modules[y][x] = ((data[i >> 3] >> (7 - (i & 7))) & 1) != 0;
                    i++;
                }
            }
        }
    }
}

void QrCode::applyMask(int msk) {
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            bool invert;
            switch (msk) {
                case 0: invert = (x + y) % 2 == 0; break;
                case 1: invert = y % 2 == 0; break;
                case 2: invert = x % 3 == 0; break;
                case 3: invert = (x + y) % 3 == 0; break;
                case 4: invert = (x / 3 + y / 2) % 2 == 0; break;
                case 5: invert = x * y % 2 + x * y % 3 == 0; break;
                case 6: invert = (x * y % 2 + x * y % 3) % 2 == 0; break;
                case 7: invert = ((x + y) % 2 + x * y % 3) % 2 == 0; break;
                default: throw std::logic_error("Unreachable");
            }
            if (!isFunction[y][x] && invert)
                modules[y][x] = !modules[y][x];
        }
    }
}

long QrCode::getPenaltyScore() const {
    long result = 0;

    for (int y = 0; y < size; y++) {
        bool runColor = false;
        int runX = 0;
        std::array<int, 7> runHistory{};
        for (int x = 0; x < size; x++) {
            if (modules[y][x] == runColor) {
                runX++;
                if (runX == 5)
                    result += PENALTY_N1;
                else if (runX > 5)
                    result++;
            } else {
                runColor = modules[y][x];
                runX = 1;
            }
        }
    }

    for (int x = 0; x < size; x++) {
        bool runColor = false;
        int runY = 0;
        for (int y = 0; y < size; y++) {
            if (modules[y][x] == runColor) {
                runY++;
                if (runY == 5)
                    result += PENALTY_N1;
                else if (runY > 5)
                    result++;
            } else {
                runColor = modules[y][x];
                runY = 1;
            }
        }
    }

    for (int y = 0; y < size - 1; y++) {
        for (int x = 0; x < size - 1; x++) {
            bool color = modules[y][x];
            if (color == modules[y][x + 1] &&
                color == modules[y + 1][x] &&
                color == modules[y + 1][x + 1])
                result += PENALTY_N2;
        }
    }

    int black = 0;
    for (const auto &row : modules) {
        for (bool color : row) {
            if (color) black++;
        }
    }
    int total = size * size;
    int k = std::abs(black * 20 - total * 10) / total;
    result += k * PENALTY_N4;

    return result;
}

int QrCode::getAlignmentPatternPositions(int ver, std::vector<int> &result) {
    if (ver == 1)
        return 0;
    int numAlign = ver / 7 + 2;
    int step = (ver == 32) ? 26 : (ver * 4 + numAlign * 2 + 1) / (numAlign * 2 - 2) * 2;
    result.resize(numAlign);
    result[0] = 6;
    for (int i = numAlign - 1, pos = ver * 4 + 10; i >= 1; i--, pos -= step)
        result[i] = pos;
    return numAlign;
}

int QrCode::getNumRawDataModules(int ver) {
    int result = (16 * ver + 128) * ver + 64;
    if (ver >= 2) {
        int numAlign = ver / 7 + 2;
        result -= (25 * numAlign - 10) * numAlign - 55;
        if (ver >= 7)
            result -= 36;
    }
    return result;
}

int QrCode::getNumDataCodewords(int ver, Ecc ecl) {
    return getNumRawDataModules(ver) / 8 - getEccCodewordsPerBlock(ver, ecl) * getNumBlocks(ver, ecl);
}

int QrCode::getNumBlocks(int, Ecc ecl) {
    switch (ecl) {
        case Ecc::LOW:      return 1;
        case Ecc::MEDIUM:   return 1;
        case Ecc::QUARTILE: return 1;
        case Ecc::HIGH:     return 1;
        default:            return 1;
    }
}

int QrCode::getEccCodewordsPerBlock(int, Ecc ecl) {
    switch (ecl) {
        case Ecc::LOW:      return 7;
        case Ecc::MEDIUM:   return 10;
        case Ecc::QUARTILE: return 13;
        case Ecc::HIGH:     return 17;
        default:            return 7;
    }
}

std::vector<std::uint8_t> QrCode::reedSolomonComputeDivisor(int degree) {
    std::vector<std::uint8_t> result(degree);
    result[degree - 1] = 1;
    std::uint8_t root = 1;
    for (int i = 0; i < degree; i++) {
        for (int j = 0; j < degree; j++) {
            result[j] = reedSolomonMultiply(result[j], root);
            if (j + 1 < degree)
                result[j] ^= result[j + 1];
        }
        root = reedSolomonMultiply(root, 0x02);
    }
    return result;
}

std::vector<std::uint8_t> QrCode::reedSolomonComputeRemainder(
        const std::vector<std::uint8_t> &data,
        const std::vector<std::uint8_t> &divisor) {
    std::vector<std::uint8_t> result(divisor.size());
    for (std::uint8_t b : data) {
        std::uint8_t factor = b ^ result.at(0);
        result.erase(result.begin());
        result.push_back(0);
        for (std::size_t i = 0; i < result.size(); i++)
            result[i] ^= reedSolomonMultiply(divisor[i], factor);
    }
    return result;
}

std::uint8_t QrCode::reedSolomonMultiply(std::uint8_t x, std::uint8_t y) {
    int z = 0;
    for (int i = 7; i >= 0; i--) {
        z = (z << 1) ^ ((z >> 7) * 0x11D);
        if (((y >> i) & 1) != 0)
            z ^= x;
    }
    return static_cast<std::uint8_t>(z);
}

} // namespace qrcodegen