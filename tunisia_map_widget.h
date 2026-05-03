#ifndef TUNISIA_MAP_WIDGET_H
#define TUNISIA_MAP_WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QList>
#include <QPointF>
#include <QMap>
#include "tunisia_map_data.h"
#include "labo.h"

class TunisiaMapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TunisiaMapWidget(QWidget *parent = nullptr);
    
    bool loadMapImage(const QString &imagePath);
    void drawTunisiaMap();
    void setSelectedGovernorate(const QString &govName);
    void setLabosData(const QList<LaboData> &labos);
    void updateLabosByRegion();
    
signals:
    void governorateClicked(const QString &governorate);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    struct MapPoint {
        double lat, lon;
        int screenX, screenY;
    };

    QPixmap m_mapImage;
    bool m_hasMapImage;
    QString m_selectedGovernorate;
    QList<GovernorateInfo> m_governorates;
    QList<LaboData> m_labos;
    QMap<QString, QList<LaboData>> m_labosByRegion;  // Region -> List of labs
    
    // Map bounds (approximate for Tunisia)
    double m_minLat = 32.5;
    double m_maxLat = 37.5;
    double m_minLon = 8.0;
    double m_maxLon = 11.5;
    
    MapPoint latLonToScreen(double lat, double lon, int mapX, int mapY, int mapWidth, int mapHeight);
    QString findGovernorateAtPoint(int x, int y, int mapX, int mapY, int mapWidth, int mapHeight);
    QString getGovernorateFromAddress(const QString &address);
    QString getRegionFromGovernorate(const QString &governorate);
    void drawGovernorateMarkers(QPainter &painter, int mapX, int mapY, int mapWidth, int mapHeight);
    void drawRegionLabels(QPainter &painter, int mapX, int mapY, int mapWidth, int mapHeight);
    void drawLabInfo(QPainter &painter, int mapX, int mapY, int mapWidth, int mapHeight);
    void drawLegend(QPainter &painter);
};

#endif // TUNISIA_MAP_WIDGET_H
