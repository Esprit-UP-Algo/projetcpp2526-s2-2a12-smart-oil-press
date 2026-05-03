# 🌡️ Guide de Configuration Arduino Environment

## ✅ Flux Actuellement Implémenté

### Input - Seuil de Température
- `ui->spinSeuilTemp` → Spinbox pour définir le seuil
- `ui->btnAppliquerSeuil` → Bouton pour appliquer le seuil
- Appel: `onApplyArduinoThreshold()` → Met à jour `m_fanTempThreshold`

### Processing
1. **Timer (5 secondes)** → Appelle `readEnvironmentSensor()`
2. **readEnvironmentSensor()** → Lit les données du capteur Arduino
3. **onEnvSensorDataReceived()** → Traite les données reçues
   - Calcule l'alerte (NORMAL, WARNING, CRITICAL)
   - Contrôle auto du ventilateur
   - Met à jour les labels UI
   - Ajoute une ligne à l'historique

### Output - Tableau d'Historique
- `ui->tableArduinoHistory` → Affiche l'historique des lectures
- Colonnes: Timestamp | Temp | Humidity | Fan Event | Alert
- Nouvelles lignes en haut (plus récent en premier)
- Max 200 lignes

---

## 🔴 Problèmes Possibles

### 1. Seuil de Température Non Initialisé
**Symptôme**: Le spinSeuilTemp n'a pas de valeur par défaut
**Solution**: Ajouter une valeur par défaut dans setupEnvironmentArduino()

### 2. Boutons Non Connectés
**Symptôme**: Cliquer sur boutons ne fait rien
**Solution**: Vérifier que les noms de widgets correspondent exactement

### 3. Labels N'Existent Pas
**Symptôme**: Les données ne s'affichent pas dans la UI
**Solution**: Les labels doivent exister dans le .ui file

### 4. Arduino Pas Connecté
**Symptôme**: readSensorData() retourne false
**Solution**: Vérifier la connexion USB et le port COM

---

## 📋 Widgets Requis

| Widget Name | Type | Purpose |
|---|---|---|
| spinSeuilTemp | QSpinBox | Input: Seuil temp |
| btnAppliquerSeuil | QPushButton | Apply threshold |
| btnStopFan | QPushButton | Stop fan manually |
| btnResumeAutoFan | QPushButton | Resume auto mode |
| btnClearArduinoHistory | QPushButton | Clear history |
| labelTemp | QLabel | Display: Temperature |
| labelHum | QLabel | Display: Humidity |
| labelFan | QLabel | Display: Fan status |
| labelAlerteArduino | QLabel | Display: Alert level |
| labelSeuilActuel | QLabel | Display: Current threshold |
| tableArduinoHistory | QTableWidget | Output: History |
| statusbar1 | QStatusBar | Status messages |

---

## 🔧 Points de Vérification

1. **setupEnvironmentArduino()** appelé dans le constructeur ✓
2. **Tous les connect()** pour les boutons valides ✓
3. **startEnvironmentMonitoring()** démarre le timer ✓
4. **readEnvironmentSensor()** est appelé toutes les 5 secondes ✓
5. **addArduinoHistoryRow()** ajoute les données au tableau ✓
