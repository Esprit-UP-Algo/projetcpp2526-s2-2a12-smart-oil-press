# Arduino Fan Control with Command Selection - Implementation Guide

## What Has Been Done

### 1. **Database Schema Extension**
- Added `SEUL` column to COMMANDE table (automatically created if missing)
- Stores temperature threshold per command
- Default value: 25°C

### 2. **Backend Implementation**

#### New Methods in `Ccommande` class:
```cpp
// Read threshold from database for a command
static double getSeulByCommandeId(int idCommande, bool *ok = nullptr);

// Save threshold to database for a command
static bool setSeulByCommandeId(int idCommande, double seul);

// Get all command IDs for populating combobox
static QVector<int> getAllCommandeIds();
```

#### New Methods in `MainWindow` class:
```cpp
// Called when user selects a command from combobox
void onSelectCommandeForThreshold();

// Called when user clicks "Save" to store threshold in database
void onSaveThresholdToCommande();
```

### 3. **How It Works**

**Flow:**
1. User selects a command ID from a combobox
   ↓
2. `onSelectCommandeForThreshold()` loads that command's threshold from database
   ↓
3. If not set in database, defaults to 25°C
   ↓
4. UI updates to show the loaded threshold
   ↓
5. User can adjust the threshold using the spinbox
   ↓
6. User clicks "Save Threshold" button
   ↓
7. `onSaveThresholdToCommande()` stores it in database
   ↓
8. **Fan control automatically uses this threshold to turn ON/OFF**

## What You Need to Add to Your UI (.ui file)

You need to add these elements to your Arduino/Environment tab in Qt Designer:

### **Element 1: ComboBox for Command Selection**
```
Type: QComboBox
ObjectName: comboSelectCommande
Text: (leave empty, populated at runtime)
```

### **Element 2: Label to Show Current Command**
```
Type: QLabel
ObjectName: labelCommandeActuelle
Text: "-"
```

### **Element 3: Button to Save Threshold**
```
Type: QPushButton
ObjectName: btnSaveThresholdToCommande
Text: "Save Threshold to Command"
```

## Example UI Layout

```
┌─────────────────────────────────────────────┐
│ Arduino Environment Control                  │
├─────────────────────────────────────────────┤
│                                              │
│ Current Command: [labelCommandeActuelle] -   │
│                                              │
│ Select Command: [comboSelectCommande ▼]      │
│                                              │
│ Temperature Threshold: [spinSeuilTemp] °C    │
│                                              │
│ [Button: Save Threshold to Command]          │
│ [Button: Apply]                              │
│                                              │
│ Status: [labelSeuilActuel] C                 │
│                                              │
│ [History Table]                              │
│ Timestamp | Temp | Humidity | Fan Event | Alert
│                                              │
└─────────────────────────────────────────────┘
```

## Usage Example

1. **First Time Using a Command:**
   - Select command ID 5 from combobox
   - System loads threshold (defaults to 25°C if not set)
   - UI shows: "Current Command: 5" and threshold = 25°C
   - Fan will turn ON when temperature ≥ 25°C

2. **Changing the Threshold:**
   - Command 5 still selected
   - Adjust spinbox to 30°C
   - Click "Save Threshold to Command"
   - Message: "✓ Seuil de la commande 5 enregistre: 30.0°C"
   - **Fan now turns ON when temperature ≥ 30°C**

3. **Switching Commands:**
   - Select command ID 10 from combobox
   - System loads command 10's threshold (e.g., 22°C)
   - UI updates to show threshold = 22°C
   - Fan now uses command 10's threshold

## Database Changes (Automatic)

The system will automatically attempt to add the SEUL column if it doesn't exist:

```sql
ALTER TABLE COMMANDE ADD SEUL NUMBER(5,2) DEFAULT 25.0;
```

If you need to manually add it:
```sql
ALTER TABLE COMMANDE ADD SEUL NUMBER(5,2) DEFAULT 25.0;
```

## Key Features

✅ **Persistent Storage** - Thresholds saved in database, not lost on restart
✅ **Per-Command Thresholds** - Each command can have its own temperature threshold  
✅ **Easy Selection** - ComboBox populated with all available commands
✅ **Default Value** - Defaults to 25°C if not set
✅ **Auto-Column Creation** - SEUL column created automatically if missing
✅ **Real-time Control** - Fan immediately responds to the selected command's threshold

## Debugging

If commands don't appear in combobox:
- Check database connection
- Ensure COMMANDE table has data
- Check console for "[EnvArduino]" debug messages

If threshold not saving:
- Check database permissions
- Look for error messages in statusbar
- Check application console output

For more details, search for "[EnvArduino]" in the console output - all operations are logged.
