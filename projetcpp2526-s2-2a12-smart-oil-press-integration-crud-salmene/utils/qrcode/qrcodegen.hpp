#ifndef QRCODEGEN_HPP
#define QRCODEGEN_HPP

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace qrcodegen {

class QrCode final {

public:
    enum class Ecc {
        LOW = 0,
        MEDIUM,
        QUARTILE,
        HIGH,
    };

    enum class Mask {
        AUTO = -1,
        MASK_0 = 0,
        MASK_1,
        MASK_2,
        MASK_3,
        MASK_4,
        MASK_5,
        MASK_6,
        MASK_7,
    };

public:
    static QrCode encodeText(const char *text, Ecc ecl);
    static QrCode encodeBinary(const std::vector<std::uint8_t> &data, Ecc ecl);

public:
    int getVersion() const;
    int getSize() const;
    Ecc getErrorCorrectionLevel() const;
    int getMask() const;
    bool getModule(int x, int y) const;

private:
    int version;
    int size;
    Ecc errorCorrectionLevel;
    int mask;
    std::vector<std::vector<bool>> modules;
    std::vector<std::vector<bool>> isFunction;

private:
    QrCode(int ver, Ecc ecl, const std::vector<std::uint8_t> &dataCodewords, int msk);

    void drawFunctionPatterns();
    void drawFormatBits(int msk);
    void drawVersion();
    void drawFinderPattern(int x, int y);
    void drawAlignmentPattern(int x, int y);
    void setFunctionModule(int x, int y, bool isBlack);
    void addEccAndInterleave(const std::vector<std::uint8_t> &data, std::vector<std::uint8_t> &result) const;
    void drawCodewords(const std::vector<std::uint8_t> &data);
    void applyMask(int msk);
    long getPenaltyScore() const;

    static int getAlignmentPatternPositions(int ver, std::vector<int> &result);
    static int getNumRawDataModules(int ver);
    static int getNumDataCodewords(int ver, Ecc ecl);
    static int getNumBlocks(int ver, Ecc ecl);
    static int getEccCodewordsPerBlock(int ver, Ecc ecl);
    static std::vector<std::uint8_t> reedSolomonComputeDivisor(int degree);
    static std::vector<std::uint8_t> reedSolomonComputeRemainder(
        const std::vector<std::uint8_t> &data,
        const std::vector<std::uint8_t> &divisor);
    static std::uint8_t reedSolomonMultiply(std::uint8_t x, std::uint8_t y);

private:
    static const int MIN_VERSION = 1;
    static const int MAX_VERSION = 40;
    static const int PENALTY_N1 = 3;
    static const int PENALTY_N2 = 3;
    static const int PENALTY_N3 = 40;
    static const int PENALTY_N4 = 10;
};


class QrSegment final {

public:
    class Mode final {

    public:
        int modeBits;
        int numBitsCharCount[3];

    public:
        constexpr Mode(int mb, int cc0, int cc1, int cc2) :
            modeBits(mb),
            numBitsCharCount{cc0, cc1, cc2} {}

        int numCharCountBits(int ver) const;
    };

public:
    static const Mode NUMERIC;
    static const Mode ALPHANUMERIC;
    static const Mode BYTE;
    static const Mode KANJI;
    static const Mode ECI;

public:
    Mode mode;
    int numChars;
    std::vector<bool> data;

public:
    QrSegment(Mode md, int numCh, const std::vector<bool> &dt);

    static QrSegment makeBytes(const std::vector<std::uint8_t> &data);
    static QrSegment makeNumeric(const char *digits);
    static QrSegment makeAlphanumeric(const char *text);
    static std::vector<QrSegment> makeSegments(const char *text);

    static int getTotalBits(const std::vector<QrSegment> &segs, int version);

private:
    static std::vector<bool> makeNumericBits(const char *digits);
    static std::vector<bool> makeAlphanumericBits(const char *text);
};

} // namespace qrcodegen

#endif