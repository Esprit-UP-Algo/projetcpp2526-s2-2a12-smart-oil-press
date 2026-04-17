#ifndef TUNISIA_MAP_DATA_H
#define TUNISIA_MAP_DATA_H

#include <QString>
#include <QPointF>
#include <QList>
#include <QColor>

struct GovernorateInfo {
    QString name;
    QString region;  // North, Center, South
    double latitude;
    double longitude;
    int screenX;     // Pixel X on map image
    int screenY;     // Pixel Y on map image
    QColor color;
};

class TunisiaMapData {
public:
    static QList<GovernorateInfo> getGovernoratesData() {
        return QList<GovernorateInfo> {
            // ===== NORTH REGION =====
            { "Tunis", "North", 36.8065, 10.1815, 535, 110, QColor(70, 130, 180) },           // Steel Blue
            { "Ariana", "North", 36.8500, 10.1900, 545, 95, QColor(100, 149, 237) },         // Cornflower
            { "Ben Arous", "North", 36.7500, 10.2300, 555, 125, QColor(135, 206, 250) },     // Light Sky Blue
            { "Manouba", "North", 36.8000, 10.0500, 520, 105, QColor(176, 196, 222) },       // Light Steel Blue
            { "Bizerte", "North", 37.2742, 9.8739, 505, 70, QColor(65, 105, 225) },          // Royal Blue
            { "Béja", "North", 36.7242, 9.1839, 450, 130, QColor(25, 25, 112) },             // Midnight Blue
            { "Jendouba", "North", 36.5000, 8.7839, 420, 160, QColor(30, 144, 255) },        // Dodger Blue
            { "Kef", "North", 36.1764, 8.7114, 415, 200, QColor(0, 0, 205) },                // Medium Blue
            { "Siliana", "North", 36.0000, 9.3839, 460, 240, QColor(0, 51, 102) },           // Dark Blue
            { "Zaghouan", "North", 36.4000, 9.9300, 540, 170, QColor(72, 118, 255) },        // Light Navy
            { "Nabeul", "North", 36.4553, 10.7369, 580, 150, QColor(75, 0, 130) },           // Indigo
            
            // ===== CENTER REGION =====
            { "Sousse", "Center", 35.8256, 10.6369, 565, 240, QColor(255, 215, 0) },         // Gold
            { "Monastir", "Center", 35.7769, 10.8167, 575, 260, QColor(255, 200, 0) },       // Dark Gold
            { "Mahdia", "Center", 35.5031, 11.0597, 590, 290, QColor(255, 165, 0) },         // Orange
            { "Kairouan", "Center", 35.6771, 9.9197, 510, 300, QColor(255, 140, 0) },        // Dark Orange
            { "Kasserine", "Center", 35.1675, 8.8342, 430, 340, QColor(255, 99, 71) },       // Tomato
            { "Sidi Bouzid", "Center", 35.0369, 9.4969, 475, 360, QColor(240, 128, 128) },   // Light Coral
            
            // ===== SOUTH REGION =====
            { "Sfax", "South", 34.7406, 10.7603, 560, 380, QColor(220, 20, 60) },            // Crimson
            { "Gabès", "South", 33.8869, 10.0963, 525, 430, QColor(178, 34, 34) },           // Firebrick
            { "Medenine", "South", 33.3614, 11.0328, 570, 560, QColor(139, 0, 0) },          // Dark Red
            { "Tataouine", "South", 32.9289, 10.4514, 515, 750, QColor(128, 0, 0) },         // Maroon
            { "Gafsa", "South", 34.4258, 8.7839, 415, 450, QColor(205, 92, 92) },            // Indian Red
            { "Tozeur", "South", 33.9197, 8.1342, 350, 500, QColor(165, 42, 42) },           // Brown
            { "Kebili", "South", 33.7061, 8.9703, 395, 600, QColor(184, 134, 11) },          // Dark Goldenrod
        };
    }

    // Tunisia boundaries (approximate)
    static QPointF getTunisiaNorthWest() { return QPointF(8.0, 37.5); }
    static QPointF getTunisiaSouthEast() { return QPointF(11.5, 32.5); }

    static QString getRegionDescription(const QString &region) {
        if (region == "North") return "🟢 North (الشمال)";
        if (region == "Center") return "🟡 Center (الوسط)";
        if (region == "South") return "🔴 South (الجنوب)";
        return region;
    }
};

#endif // TUNISIA_MAP_DATA_H
