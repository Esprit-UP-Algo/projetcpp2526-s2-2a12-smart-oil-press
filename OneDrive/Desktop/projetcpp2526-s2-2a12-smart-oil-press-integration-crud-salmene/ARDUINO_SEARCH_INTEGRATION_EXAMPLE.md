# Arduino Environment - Exemple d'Intégration UI avec Recherche par ID

## 📋 Vue d'ensemble

Cette documentation montre comment intégrer le nouveau système de recherche par ID commande avec enregistrement de données.

---

## 🎯 Fonctionnalités Ajoutées

### 1. **Recherche par ID Commande**
```cpp
bool ArduinoEnvironment::searchCommandeById(int idCommande, QString *errorMessage)
```

- Récupère la commande de la base de données
- Charge le seuil de température (par défaut 28°C)
- Stocke le nom de la commande

### 2. **Enregistrement des Données Capteur**
```cpp
bool ArduinoEnvironment::recordSensorData(int idCommande, const EnvSensorData &data, QString *errorMessage)
```

- Enregistre température en °C
- Enregistre humidité en %
- Enregistre vitesse ventilateur (RPM)
- Log dans la BD avec horodatage

---

## 🖼️ Exemple d'Interface UI Recommandée

```
┌─────────────────────────────────────────────────┐
│  🔍 RECHERCHE COMMANDE ARDUINO                 │
├─────────────────────────────────────────────────┤
│                                                  │
│  ID Commande: [    123    ] [🔍 Rechercher]    │
│                                                  │
│  ✅ Commande Trouvée                            │
│  ├─ Libellé: Commande Chauffage Lab            │
│  ├─ Seuil Température: 28.0°C                  │
│  ├─ État: En cours                            │
│  └─ ID Client: 5                               │
│                                                  │
├─────────────────────────────────────────────────┤
│  📊 DONNÉES CAPTEUR (AUTO-REFRESH 2s)          │
├─────────────────────────────────────────────────┤
│                                                  │
│  Température:    25.3°C    ████░░░░░░ [↓]     │
│  Humidité:       65.2%     ███░░░░░░░ [↓]     │
│  Vitesse Ventilo: 450 RPM   ███████░░░ [↑]     │
│  Mode Ventilo:   AUTO                         │
│                                                  │
│  Horodatage: 2026-04-29 14:30:25              │
│                                                  │
│  [💾 Enregistrer Données] [❌ Arrêter] [⏹ Fan]│
│                                                  │
└─────────────────────────────────────────────────┘
```

---

## 💻 Pseudo-code d'Intégration

```cpp
class FanControlWidget : public QWidget {
private:
    ArduinoEnvironment* m_arduino;
    QLineEdit* m_commandeIdInput;
    QLabel* m_commandeInfoLabel;
    QLabel* m_tempLabel;
    QLabel* m_humidityLabel;
    QLabel* m_rpmLabel;
    QPushButton* m_searchBtn;
    QPushButton* m_recordBtn;
    QTimer* m_readTimer;

public:
    FanControlWidget() {
        // Setup UI
        setupUI();
        
        // Connect signals
        connect(m_searchBtn, &QPushButton::clicked, this, &FanControlWidget::onSearchCommande);
        connect(m_recordBtn, &QPushButton::clicked, this, &FanControlWidget::onRecordData);
        
        // Timer pour lecture auto
        m_readTimer = new QTimer(this);
        connect(m_readTimer, &QTimer::timeout, this, &FanControlWidget::onReadSensorData);
        m_readTimer->setInterval(2000);  // 2 secondes
    }

private slots:
    void onSearchCommande() {
        int idCommande = m_commandeIdInput->text().toInt();
        QString error;
        
        if (!m_arduino->searchCommandeById(idCommande, &error)) {
            QMessageBox::warning(this, "Erreur", error);
            return;
        }
        
        // Afficher infos commande
        QString info = QString(
            "✅ Commande Trouvée\n"
            "Libellé: %1\n"
            "Seuil: %2°C"
        ).arg(m_arduino->getCommandeNom())
         .arg(m_arduino->getTargetTemperature());
        
        m_commandeInfoLabel->setText(info);
        
        // Démarrer lecture automatique
        m_readTimer->start();
    }
    
    void onReadSensorData() {
        EnvSensorData data;
        QString error;
        
        if (!m_arduino->readSensorData(&data, &error)) {
            qWarning() << "Erreur lecture:" << error;
            return;
        }
        
        // Afficher données
        m_tempLabel->setText(QString("Temperature: %1°C").arg(data.temperature, 0, 'f', 1));
        m_humidityLabel->setText(QString("Humidité: %1%").arg(data.humidity, 0, 'f', 1));
        m_rpmLabel->setText(QString("Ventilo: %1 RPM (%2)").arg(data.fanRPM).arg(data.fanMode));
    }
    
    void onRecordData() {
        EnvSensorData data;
        QString error;
        
        // Lire données
        if (!m_arduino->readSensorData(&data, &error)) {
            QMessageBox::critical(this, "Erreur", error);
            return;
        }
        
        // Enregistrer données pour la commande
        int commandeId = m_arduino->getCurrentCommandeId();
        if (!m_arduino->recordSensorData(commandeId, data, &error)) {
            QMessageBox::critical(this, "Erreur", error);
            return;
        }
        
        // Message succès
        QMessageBox::information(this, "Succès", 
            QString("Données enregistrées pour la commande %1\n"
                    "Temp: %2°C | Humidité: %3% | RPM: %4")
            .arg(commandeId)
            .arg(data.temperature, 0, 'f', 1)
            .arg(data.humidity, 0, 'f', 1)
            .arg(data.fanRPM)
        );
    }
};
```

---

## 📝 Données Enregistrées dans la BD

Chaque enregistrement comporte:
- **ID_COMMANDE**: ID de la commande
- **TYPE_COMMANDE**: "SENSOR_DATA"
- **DATE_EXECUTION**: Horodatage actuel
- **PARAMETRES**: "Temperature: X°C, Humidité: Y%"
- **TEMPERATURE_ACTUELLE**: Température lue
- **TEMPERATURE_CIBLE**: Seuil configuré (28°C)
- **FAN_RPM**: Vitesse du ventilateur
- **FAN_MODE**: Mode (AUTO, MANUAL, OFF)

---

## ✅ Points Clés à Retenir

1. **Seuil de 28°C** - Codé en dur dans Arduino et chargé par défaut en C++
2. **Recherche Automatique** - La méthode `searchCommandeById()` charge tous les paramètres
3. **Enregistrement Automatique** - Les données sont horodatées et loggées dans la BD
4. **Auto-Reconnexion** - Le système se reconnecte automatiquement si déconnecté

---

## 🔌 Arduino Code Recall

```cpp
// Seuil temperature: 28°C
if (temperatureC >= 28.0) {
    digitalWrite(FANPIN, HIGH);   // Fan ON
    Serial.println("Fan: ON  (auto)");
} else {
    digitalWrite(FANPIN, LOW);  // Fan OFF
    Serial.println("Fan: OFF (auto)");
}
```

Correspond exactement au `m_targetTemperature = 28.0f` dans C++!

---

## 🚀 Prochaines Étapes

1. Créer le widget UI avec les éléments listés ci-dessus
2. Connecter les signaux/slots aux méthodes Arduino
3. Intégrer dans `mainwindow.cpp`
4. Tester la recherche par ID et l'enregistrement
