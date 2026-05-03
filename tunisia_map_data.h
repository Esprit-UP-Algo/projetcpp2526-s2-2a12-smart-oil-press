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
            { "Tunis", "North", 36.8065, 10.1815, 315, 55, QColor(70, 130, 180) },          
            { "Ariana", "North", 36.8500, 10.1900, 315, 45, QColor(100, 149, 237) },        
            { "Ben Arous", "North", 36.7500, 10.2300, 320, 65, QColor(135, 206, 250) },    
            { "Manouba", "North", 36.8000, 10.0500, 305, 55, QColor(176, 196, 222) },      
            { "Bizerte", "North", 37.2742, 9.8739, 285, 30, QColor(65, 105, 225) },          
            { "Béja", "North", 36.7242, 9.1839, 275, 55, QColor(25, 25, 112) },            
            { "Jendouba", "North", 36.5000, 8.7839, 240, 60, QColor(30, 144, 255) },        
            { "Kef", "North", 36.1764, 8.7114, 240, 100, QColor(0, 0, 205) },                
            { "Siliana", "North", 36.0000, 9.3839, 280, 100, QColor(0, 51, 102) },          
            { "Zaghouan", "North", 36.4000, 9.9300, 315, 85, QColor(72, 118, 255) },        
            { "Nabeul", "North", 36.4553, 10.7369, 345, 55, QColor(75, 0, 130) },          
            
            // ===== CENTER REGION =====
            { "Sousse", "Center", 35.8256, 10.6369, 330, 100, QColor(255, 215, 0) },        
            { "Monastir", "Center", 35.7769, 10.8167, 350, 120, QColor(255, 200, 0) },      
            { "Mahdia", "Center", 35.5031, 11.0597, 350, 135, QColor(255, 165, 0) },        
            { "Kairouan", "Center", 35.6771, 9.9197, 310, 125, QColor(255, 140, 0) },        
            { "Kasserine", "Center", 35.1675, 8.8342, 250, 135, QColor(255, 99, 71) },      
            { "Sidi Bouzid", "Center", 35.0369, 9.4969, 290, 155, QColor(240, 128, 128) },  
            
            // ===== SOUTH REGION =====
            { "Sfax", "South", 34.7406, 10.7603, 320, 170, QColor(220, 20, 60) },            
            { "Gabès", "South", 33.8869, 10.0963, 310, 220, QColor(178, 34, 34) },          
            { "Medenine", "South", 33.3614, 11.0328, 355, 245, QColor(139, 0, 0) },          
            { "Tataouine", "South", 32.9289, 10.4514, 310, 300, QColor(128, 0, 0) },        
            { "Gafsa", "South", 34.4258, 8.7839, 245, 185, QColor(205, 92, 92) },            
            { "Tozeur", "South", 33.9197, 8.1342, 225, 210, QColor(165, 42, 42) },          
            { "Kebili", "South", 33.7061, 8.9703, 250, 245, QColor(184, 134, 11) },
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
