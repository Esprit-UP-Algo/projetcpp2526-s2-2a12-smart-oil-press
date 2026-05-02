#include "tunisia_map_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QMouseEvent>
#include <QDebug>
#include <QRegularExpression>
#include <cmath>

TunisiaMapWidget::TunisiaMapWidget(QWidget *parent)
    : QWidget(parent)
    , m_hasMapImage(false)
    , m_governorates(TunisiaMapData::getGovernoratesData())
{
    setMinimumSize(320, 400);
    setStyleSheet("background-color: white;");
    
    // Initialize labo grouping by region
    updateLabosByRegion();
}

bool TunisiaMapWidget::loadMapImage(const QString &imagePath)
{
    qDebug() << "Attempting to load map image from:" << imagePath;
    if (m_mapImage.load(imagePath)) {
        m_hasMapImage = true;
        qDebug() << "Map image loaded successfully";
        update();
        return true;
    } else {
        m_hasMapImage = false;
        qDebug() << "Could not load map image";
        update();
        return false;
    }
}

void TunisiaMapWidget::drawTunisiaMap()
{
    update();
}

void TunisiaMapWidget::setSelectedGovernorate(const QString &govName)
{
    m_selectedGovernorate = govName;
    update();
}

void TunisiaMapWidget::setLabosData(const QList<LaboData> &labos)
{
    m_labos = labos;
    updateLabosByRegion();
    update();
}

void TunisiaMapWidget::updateLabosByRegion()
{
    m_labosByRegion.clear();
    
    for (const auto &labo : m_labos) {
        QString region = getRegionFromGovernorate(getGovernorateFromAddress(labo.adresse));
        if (!region.isEmpty()) {
            if (!m_labosByRegion.contains(region)) {
                m_labosByRegion[region] = QList<LaboData>();
            }
            m_labosByRegion[region].append(labo);
        }
    }
}

QString TunisiaMapWidget::getGovernorateFromAddress(const QString &address)
{
    // Extract governorate name from address
    if (address.isEmpty()) return QString();
    
    // Normalize the address (trim and lowercase for comparison)
    QString normalizedAddr = address.trimmed();
    
    // Try exact match first
    for (const auto &gov : m_governorates) {
        if (normalizedAddr.compare(gov.name, Qt::CaseInsensitive) == 0) {
            return gov.name;
        }
    }
    
    // Try to match where address contains the governorate name
    for (const auto &gov : m_governorates) {
        if (normalizedAddr.contains(gov.name, Qt::CaseInsensitive)) {
            return gov.name;
        }
    }
    
    // Try to match by first part (before dash or space)
    QStringList parts = normalizedAddr.split(QRegularExpression("[\\-,;]"), Qt::SkipEmptyParts);
    if (!parts.isEmpty()) {
        QString firstPart = parts[0].trimmed();
        for (const auto &gov : m_governorates) {
            if (firstPart.compare(gov.name, Qt::CaseInsensitive) == 0) {
                return gov.name;
            }
        }
    }
    
    return QString();
}

QString TunisiaMapWidget::getRegionFromGovernorate(const QString &governorate)
{
    for (const auto &gov : m_governorates) {
        if (gov.name == governorate) {
            return gov.region;
        }
    }
    return QString();
}

TunisiaMapWidget::MapPoint TunisiaMapWidget::latLonToScreen(double lat, double lon, int mapX, int mapY, int mapWidth, int mapHeight)
{
    MapPoint result;
    
    // Get the original image dimensions to use for coordinate scaling
    int originalMapWidth = m_mapImage.width();
    int originalMapHeight = m_mapImage.height();
    
    // The governorate coordinates are already in screen space (pixel coordinates on the original image)
    // We just need to scale them to the current display size
    
    // The input lat/lon are actually already screen X/Y from the data structure
    // So we just scale them based on the map display size
    double scaleX = (double)mapWidth / originalMapWidth;
    double scaleY = (double)mapHeight / originalMapHeight;
    
    result.screenX = mapX + (int)(lon * scaleX);  // lon is actually screenX
    result.screenY = mapY + (int)(lat * scaleY);   // lat is actually screenY
    result.lat = lat;
    result.lon = lon;
    
    return result;
}

QString TunisiaMapWidget::findGovernorateAtPoint(int x, int y, int mapX, int mapY, int mapWidth, int mapHeight)
{
    const int CLICK_RADIUS = 12;
    
    // Calculate scale factors based on original image size
    int originalMapWidth = m_mapImage.width();
    int originalMapHeight = m_mapImage.height();
    
    double scaleX = (double)mapWidth / originalMapWidth;
    double scaleY = (double)mapHeight / originalMapHeight;
    
    for (const auto &gov : m_governorates) {
        // Scale the screen coordinates from the original image to the current display size
        int scaledScreenX = mapX + (int)(gov.screenX * scaleX);
        int scaledScreenY = mapY + (int)(gov.screenY * scaleY);
        
        int dx = x - scaledScreenX;
        int dy = y - scaledScreenY;
        int distance = (int)std::sqrt(dx * dx + dy * dy);
        
        if (distance <= CLICK_RADIUS) {
            return gov.name;
        }
    }
    return QString();
}

void TunisiaMapWidget::drawGovernorateMarkers(QPainter &painter, int mapX, int mapY, int mapWidth, int mapHeight)
{
    painter.setRenderHint(QPainter::Antialiasing);
    
    // Calculate scale factors based on original image size
    int originalMapWidth = m_mapImage.width();
    int originalMapHeight = m_mapImage.height();
    
    double scaleX = (double)mapWidth / originalMapWidth;
    double scaleY = (double)mapHeight / originalMapHeight;
    
    for (const auto &gov : m_governorates) {
        // Scale the screen coordinates from the original image to the current display size
        int scaledScreenX = mapX + (int)(gov.screenX * scaleX);
        int scaledScreenY = mapY + (int)(gov.screenY * scaleY);
        
        int markerRadius = 6;  // Original size
        if (gov.name == m_selectedGovernorate) {
            markerRadius = 9;   // Original selected size
        }
        
        // Draw shadow for depth
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(0, 0, 0, 60));
        painter.drawEllipse(scaledScreenX - markerRadius + 1, 
                           scaledScreenY - markerRadius + 1,
                           markerRadius * 2, 
                           markerRadius * 2);
        
        // Draw marker circle
        painter.setPen(QPen(Qt::black, 1));
        painter.setBrush(gov.color);
        painter.drawEllipse(scaledScreenX - markerRadius, 
                           scaledScreenY - markerRadius,
                           markerRadius * 2, 
                           markerRadius * 2);
        
        // Draw center dot
        painter.setBrush(Qt::white);
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(scaledScreenX - markerRadius/2, 
                           scaledScreenY - markerRadius/2,
                           markerRadius, 
                           markerRadius);
    }
}

void TunisiaMapWidget::drawLegend(QPainter &painter)
{
    int legendX = width() - 130;
    int legendY = 30;
    
    QFont legendFont("Arial", 8);
    painter.setFont(legendFont);
    
    // Draw legend box
    painter.setPen(QPen(Qt::black, 1));
    painter.setBrush(QColor(255, 255, 255, 245));
    painter.drawRect(legendX - 15, legendY - 15, 140, 95);
    
    // Draw legend title
    QFont titleFont("Arial", 9, QFont::Bold);
    painter.setFont(titleFont);
    painter.setPen(Qt::black);
    painter.drawText(legendX - 10, legendY, "Regions:");
    
    painter.setFont(legendFont);
    
    // Draw legend items
    int y = legendY + 18;
    
    // North
    painter.setBrush(QColor(70, 130, 180));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(legendX - 10, y - 4, 8, 8);
    painter.setPen(Qt::black);
    painter.drawText(legendX + 2, y + 3, "North");
    y += 15;
    
    // Center
    painter.setBrush(QColor(255, 215, 0));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(legendX - 10, y - 4, 8, 8);
    painter.setPen(Qt::black);
    painter.drawText(legendX + 2, y + 3, "Center");
    y += 15;
    
    // South
    painter.setBrush(QColor(220, 20, 60));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(legendX - 10, y - 4, 8, 8);
    painter.setPen(Qt::black);
    painter.drawText(legendX + 2, y + 3, "South");
}

void TunisiaMapWidget::drawRegionLabels(QPainter &painter, int mapX, int mapY, int mapWidth, int mapHeight)
{
    painter.setRenderHint(QPainter::Antialiasing);
    
    // Calculate scale factors based on original image size
    int originalMapWidth = m_mapImage.width();
    int originalMapHeight = m_mapImage.height();
    
    double scaleX = (double)mapWidth / originalMapWidth;
    double scaleY = (double)mapHeight / originalMapHeight;
    
    // Define fixed positions for region labels to align with map regions
    QMap<QString, QPair<int, int>> regionLabelPos;
    regionLabelPos["North"] = QPair<int, int>(500, 80);   // Top-right area
    regionLabelPos["Center"] = QPair<int, int>(500, 140);  // Middle-right area
    regionLabelPos["South"] = QPair<int, int>(500, 320);   // Bottom-right area
    
    // Draw region labels with background boxes
    QFont regionFont("Arial", 11, QFont::Bold);
    painter.setFont(regionFont);
    
    for (auto it = regionLabelPos.begin(); it != regionLabelPos.end(); ++it) {
        QString region = it.key();
        
        // Scale the position to match the current map display size
        int labelX = mapX + (int)(it.value().first * scaleX);
        int labelY = mapY + (int)(it.value().second * scaleY);
        
        // Get color and lab count based on region
        QColor regionColor;
        int labCount = 0;
        
        if (region == "North") {
            regionColor = QColor(70, 130, 180);
            if (m_labosByRegion.contains("North")) {
                labCount = m_labosByRegion["North"].size();
            }
        }
        else if (region == "Center") {
            regionColor = QColor(255, 215, 0);
            if (m_labosByRegion.contains("Center")) {
                labCount = m_labosByRegion["Center"].size();
            }
        }
        else if (region == "South") {
            regionColor = QColor(220, 20, 60);
            if (m_labosByRegion.contains("South")) {
                labCount = m_labosByRegion["South"].size();
            }
        }
        
        // Create label text with region name and lab count
        QString labelText = QString("%1 (%2)").arg(region).arg(labCount);
        
        // Calculate box size
        QFontMetrics fm(regionFont);
        int textWidth = fm.horizontalAdvance(labelText) + 12;
        int textHeight = fm.height() + 6;
        
        // Draw semi-transparent background box
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(255, 255, 255, 220));
        painter.drawRect(labelX - textWidth/2, labelY - textHeight/2, textWidth, textHeight);
        
        // Draw colored border
        painter.setPen(QPen(regionColor.darker(150), 2));
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(labelX - textWidth/2, labelY - textHeight/2, textWidth, textHeight);
        
        // Draw text with region color
        painter.setPen(regionColor.darker(200));
        painter.setFont(regionFont);
        painter.drawText(labelX - textWidth/2, labelY - textHeight/2, textWidth, textHeight, 
                        Qt::AlignCenter, labelText);
    }
}

void TunisiaMapWidget::drawLabInfo(QPainter &painter, int mapX, int mapY, int mapWidth, int mapHeight)
{
    // Lab information is now displayed within the region panels on the right side
    // This function is kept for backward compatibility but does nothing
    // All lab info is drawn in drawRegionLabels()
}

void TunisiaMapWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    
    // Fill background
    painter.fillRect(rect(), QColor(240, 248, 255));
    
    if (m_hasMapImage && !m_mapImage.isNull()) {
        // Calculate available space for the map
        int marginLeft = 20;
        int marginTop = 20;
        int marginRight = 20;
        int marginBottom = 20;
        
        int availableWidth = width() - marginLeft - marginRight;
        int availableHeight = height() - marginTop - marginBottom;
        
        // Calculate scaling to fit in available space while maintaining aspect ratio
        double imageAspect = (double)m_mapImage.width() / m_mapImage.height();
        double availableAspect = (double)availableWidth / availableHeight;
        
        int scaledWidth, scaledHeight;
        int mapX, mapY;
        
        if (imageAspect > availableAspect) {
            // Image is wider, scale by width
            scaledWidth = availableWidth;
            scaledHeight = (int)(scaledWidth / imageAspect);
        } else {
            // Image is taller, scale by height
            scaledHeight = availableHeight;
            scaledWidth = (int)(scaledHeight * imageAspect);
        }
        
        // Center the image
        mapX = marginLeft + (availableWidth - scaledWidth) / 2;
        mapY = marginTop + (availableHeight - scaledHeight) / 2;
        
        // Draw the scaled map image
        QPixmap scaledMap = m_mapImage.scaled(scaledWidth, scaledHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        painter.drawPixmap(mapX, mapY, scaledMap);
        
        // Draw border
        painter.setPen(QPen(Qt::darkGray, 2));
        painter.drawRect(mapX, mapY, scaledWidth, scaledHeight);
        
        // Draw governorate markers on top of map
        drawGovernorateMarkers(painter, mapX, mapY, scaledWidth, scaledHeight);
        
        // Draw region labels on map
        drawRegionLabels(painter, mapX, mapY, scaledWidth, scaledHeight);
        
        // Draw lab information on map
        drawLabInfo(painter, mapX, mapY, scaledWidth, scaledHeight);
        
        // Draw legend
        drawLegend(painter);
    } else {
        // Simple fallback - just show a message
        painter.setPen(Qt::black);
        QFont font("Arial", 14);
        painter.setFont(font);
        
        // Draw title
        painter.drawText(rect(), Qt::AlignTop | Qt::AlignHCenter, "Tunisia - Governorates Map\n\n");
        
        // Draw fallback message
        QFont smallFont("Arial", 10);
        painter.setFont(smallFont);
        painter.setPen(Qt::darkGray);
        
        QString message = "Map image not loaded.\n\nPlace tunisia_map.png in the images/ folder\nto display the map.";
        painter.drawText(rect().adjusted(20, 80, -20, -20), Qt::AlignCenter | Qt::TextWordWrap, message);
        
        // Draw a simple placeholder rectangle
        painter.setPen(QPen(Qt::lightGray, 1, Qt::DashLine));
        painter.drawRect(50, 150, width() - 100, height() - 200);
    }
}

void TunisiaMapWidget::mousePressEvent(QMouseEvent *event)
{
    // Calculate map position (same as in paintEvent)
    int marginLeft = 20;
    int marginTop = 20;
    int marginRight = 20;
    int marginBottom = 20;
    
    int availableWidth = width() - marginLeft - marginRight;
    int availableHeight = height() - marginTop - marginBottom;
    
    double imageAspect = (double)m_mapImage.width() / m_mapImage.height();
    double availableAspect = (double)availableWidth / availableHeight;
    
    int scaledWidth, scaledHeight;
    int mapX, mapY;
    
    if (imageAspect > availableAspect) {
        scaledWidth = availableWidth;
        scaledHeight = (int)(scaledWidth / imageAspect);
    } else {
        scaledHeight = availableHeight;
        scaledWidth = (int)(scaledHeight * imageAspect);
    }
    
    mapX = marginLeft + (availableWidth - scaledWidth) / 2;
    mapY = marginTop + (availableHeight - scaledHeight) / 2;
    
    QString gov = findGovernorateAtPoint(qRound(event->position().x()), qRound(event->position().y()), 
                                         mapX, mapY, scaledWidth, scaledHeight);
    if (!gov.isEmpty()) {
        setSelectedGovernorate(gov);
        emit governorateClicked(gov);
        qDebug() << "Clicked governorate:" << gov;
    }
    
    QWidget::mousePressEvent(event);
}

void TunisiaMapWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    update();
}
