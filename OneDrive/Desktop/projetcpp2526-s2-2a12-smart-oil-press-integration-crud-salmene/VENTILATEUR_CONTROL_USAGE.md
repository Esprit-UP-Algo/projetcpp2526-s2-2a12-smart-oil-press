# Ventilateur Control - Utilisation

## Overview
Ce système permet de contrôler le ventilateur Arduino en fonction d'un seuil de température basé sur l'ID de la commande.

## Composants Ajoutés

### 1. Structure: `CommandeTemperature`
```cpp
struct CommandeTemperature {
    int seul;                   // ID de la commande (COMMANDE.SEUL)
    float targetTemp;           // Température seuil (COMMANDE.TEMPERATURE_STORAGE)
    QString nomCommande;        // Nom de la commande
};
```

### 2. Structure: `EnvSensorData`
```cpp
struct EnvSensorData {
    float temperature;          // Température en °C
    float humidity;             // Humidité en %
    int fanRPM;                 // Vitesse du ventilateur
    bool fanRunning;            // État du ventilateur
    QString fanMode;            // "AUTO", "MANUAL", "OFF"
    QString status;             // Message de statut
    QString timestamp;          // Horodatage
    bool isValid;               // Données valides ?
};
```

## Méthodes Implémentées

### 1. `setCommandeInfo()`
Configure l'ID de commande et la température seuil.

**Signature:**
```cpp
void setCommandeInfo(int seul, float targetTemp, const QString &nomCommande);
```

**Paramètres:**
- `seul`: ID de la commande (depuis COMMANDE.SEUL)
- `targetTemp`: Température seuil en °C (depuis COMMANDE.TEMPERATURE_STORAGE)
- `nomCommande`: Nom de la commande (pour logs)

**Exemple:**
```cpp
ArduinoEnvironment arduino;
arduino.connect();
arduino.setCommandeInfo(5, 30.0f, "Commande Ventilation");
```

### 2. `controlFanByTemperature()`
Contrôle le ventilateur basé sur la température actuelle et le seuil.

**Signature:**
```cpp
bool controlFanByTemperature(float currentTemp, QString *errorMessage = nullptr);
```

**Logique:**
- Si `currentTemp >= targetTemp` → **Activer** ventilateur en mode AUTO
- Si `currentTemp < (targetTemp - 5)` → **Arrêter** ventilateur (hystérésis)
- Entre les deux → **Pas d'action**

**Paramètres:**
- `currentTemp`: Température actuelle lue du capteur
- `errorMessage`: Pointeur pour message d'erreur (optionnel)

**Exemple:**
```cpp
QString error;
if (!arduino.controlFanByTemperature(25.5f, &error)) {
    qDebug() << "Erreur:" << error;
}
```

### 3. `logCommandToDatabase()`
Enregistre les commandes du ventilateur en base de données (HIS_COMMANDE).

**Signature:**
```cpp
void logCommandToDatabase(const QString &typeCommande, 
                          const QString &parametres, 
                          bool success, 
                          const QString &resultat,
                          float tempActuelle = -1.0f,
                          float tempCible = -1.0f);
```

**Paramètres:**
- `typeCommande`: Type de commande (ex: "VENTILATEUR_AUTO", "VENTILATEUR_ARRET")
- `parametres`: Paramètres associés
- `success`: Résultat de l'opération
- `resultat`: Description du résultat
- `tempActuelle`: Température actuelle (optionnel)
- `tempCible`: Température cible/seuil (optionnel)

## Utilisation Complète - Boucle Principale

```cpp
#include "arduino_environment.h"

int main() {
    ArduinoEnvironment arduino;
    
    // 1. Connexion Arduino
    if (arduino.connect() != 0) {
        qDebug() << "Erreur connexion Arduino";
        return -1;
    }
    
    // 2. Configuration avec ID commande et seuil température
    // (Récupérer du base de données: SELECT SEUL, TEMPERATURE_STORAGE FROM COMMANDE WHERE ID = ?)
    arduino.setCommandeInfo(5, 30.0f, "Ventilation Salle Serveur");
    
    // 3. Boucle de lecture et contrôle
    while (true) {
        EnvSensorData sensorData;
        QString error;
        
        // Lire les données du capteur
        if (arduino.readSensorData(&sensorData, &error)) {
            qDebug() << "Temp:" << sensorData.temperature 
                     << "°C | Humidité:" << sensorData.humidity << "%";
            
            // Contrôler le ventilateur basé sur la température
            arduino.controlFanByTemperature(sensorData.temperature, &error);
            
            // Les logs sont automatiquement enregistrés dans HIS_COMMANDE
        } else {
            qDebug() << "Erreur lecture capteur:" << error;
        }
        
        QThread::msleep(5000); // Attendre 5 secondes
    }
    
    arduino.disconnect();
    return 0;
}
```

## Flux de Données

```
Base de Données (COMMANDE)
        ↓
   [SEUL, TEMPERATURE_STORAGE]
        ↓
setCommandeInfo()
        ↓
readSensorData()
        ↓
controlFanByTemperature()
        ↓
Arduino (Envoi commandes S/R)
        ↓
logCommandToDatabase() → HIS_COMMANDE
```

## Schéma Hystérésis

```
Température (°C)
        ↑
        |           
    30  |----●──── Seuil supérieur (targetTemp)
        |    ↑
        |    └── ACTION: Activer ventilateur
        |
        |
    25  |----●──── Seuil inférieur (targetTemp - 5)
        |    ↓
        |    └── ACTION: Arrêter ventilateur
        |
        |
    20  |
        └──────────→ Temps
```

## TODO: Implémentation Base de Données

La méthode `logCommandToDatabase()` doit être complétée avec:

```sql
INSERT INTO HIS_COMMANDE 
(ID_COMMANDE, TYPE_COMMANDE, DATE_EXECUTION, PARAMETRES, SUCCESS, RESULTAT, TEMPERATURE_ACTUELLE, TEMPERATURE_CIBLE)
VALUES (?, ?, NOW(), ?, ?, ?, ?, ?)
```

## Configuration Recommandée

Pour une installation optimale, ajouter à la base de données:

**Table COMMANDE:**
- `SEUL`: INT (PRIMARY KEY)
- `TEMPERATURE_STORAGE`: FLOAT (seuil du ventilateur)
- `LIBELLE`: VARCHAR
- ...autres champs existants

**Table HIS_COMMANDE:**
- `ID_COMMANDE`: INT (FK → COMMANDE.SEUL)
- `TYPE_COMMANDE`: VARCHAR (ex: "VENTILATEUR_AUTO", "VENTILATEUR_ARRET")
- `DATE_EXECUTION`: DATETIME
- `PARAMETRES`: TEXT
- `SUCCESS`: BOOLEAN
- `RESULTAT`: VARCHAR
- `TEMPERATURE_ACTUELLE`: FLOAT
- `TEMPERATURE_CIBLE`: FLOAT

## Debug & Logs

Pour activer les logs détaillés:

```cpp
// Les logs sont automatiquement affichés via qDebug()
// Chercher les préfixes: "[ArduinoEnv]"

// Exemple de sortie:
// [ArduinoEnv] Command info set: | ID (seul):5 | Target Temp:30°C | Name:Ventilation Salle
// [ArduinoEnv] Checking temperature threshold: | Current:28.5°C | Threshold:30°C | Command ID:5
// [ArduinoEnv] Temp in hysteresis zone, NO ACTION
```
