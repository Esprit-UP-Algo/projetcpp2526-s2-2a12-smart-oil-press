# Ccommande - Temperature Threshold (Seul) Integration Guide

## Overview
The `Ccommande` class now includes a temperature threshold parameter (`seulTemperature`) that controls when the ventilator activates. This threshold is set to **25°C by default** and can be customized per command/order.

## New Features Added

### 1. Member Variable
```cpp
double m_seulTemperature;  // Temperature threshold (default: 25°C)
```

### 2. Getter Method
```cpp
double getSeulTemperature() const;
```
Returns the current temperature threshold for the command.

**Example:**
```cpp
Ccommande cmd = Ccommande::getById(5);
double threshold = cmd.getSeulTemperature();  // Returns 25.0 (or custom value)
qDebug() << "Fan activation temperature:" << threshold << "°C";
```

### 3. Setter Method
```cpp
void setSeulTemperature(double seul);
```
Sets a new temperature threshold. Validates that the value is >= 0.0.

**Example:**
```cpp
Ccommande cmd = Ccommande::getById(5);
cmd.setSeulTemperature(30.0);  // Set threshold to 30°C
qDebug() << "New threshold:" << cmd.getSeulTemperature();
```

### 4. Default Value
All new `Ccommande` instances have `m_seulTemperature = 25.0` (°C)

```cpp
Ccommande cmd;  // m_seulTemperature = 25.0 by default
```

## Integration with Arduino Environment

### Workflow
```
Database (COMMANDE.SEUL)
        ↓
Ccommande instance
        ↓
getSeulTemperature()
        ↓
ArduinoEnvironment::setCommandeInfo()
        ↓
ArduinoEnvironment::controlFanByTemperature()
        ↓
Fan activation/deactivation based on threshold
```

### Complete Example

```cpp
#include "commande.h"
#include "arduino_environment.h"
#include <QDebug>

int main() {
    // 1. Create command instance (default threshold = 25°C)
    Ccommande cmd = Ccommande::getById(5);
    
    qDebug() << "Command ID:" << cmd.getIdCommande();
    qDebug() << "Fan threshold:" << cmd.getSeulTemperature() << "°C";
    
    // 2. Optionally customize the threshold
    if (cmd.getSeulTemperature() < 28.0) {
        cmd.setSeulTemperature(28.0);  // Raise threshold to 28°C
        qDebug() << "Updated threshold:" << cmd.getSeulTemperature() << "°C";
    }
    
    // 3. Connect to Arduino
    ArduinoEnvironment arduino;
    if (arduino.connect() != 0) {
        qDebug() << "Failed to connect to Arduino";
        return -1;
    }
    
    // 4. Configure Arduino with command info
    arduino.setCommandeInfo(
        cmd.getIdCommande(),           // Command ID
        cmd.getSeulTemperature(),      // Temperature threshold
        cmd.getLibelle()               // Command name
    );
    
    // 5. Main control loop
    while (true) {
        EnvSensorData sensor;
        QString error;
        
        if (arduino.readSensorData(&sensor, &error)) {
            qDebug() << "Temp:" << sensor.temperature << "°C";
            
            // Control fan based on command threshold
            arduino.controlFanByTemperature(sensor.temperature, &error);
            
            // Fan is automatically activated if:
            // - Current temp >= threshold
            // Fan is automatically deactivated if:
            // - Current temp < (threshold - 5°C)  [hysteresis]
            
        } else {
            qDebug() << "Sensor error:" << error;
        }
        
        QThread::msleep(5000);  // Read every 5 seconds
    }
    
    arduino.disconnect();
    return 0;
}
```

## Fan Control Logic

### Activation Rules
```
Current Temperature >= Threshold  →  FAN ON (AUTO MODE)
Current Temperature < (Threshold - 5)  →  FAN OFF
Between threshold ± 5  →  NO CHANGE (hysteresis)
```

### Example: Threshold = 30°C
```
Temp ≥ 30°C  →  FAN ACTIVATES
Temp < 25°C  →  FAN DEACTIVATES
25°C ≤ Temp < 30°C  →  FAN UNCHANGED (stays in current state)
```

## Usage in UI (Example: QSpinBox)

### Display & Edit Threshold in UI
```cpp
// In MainWindow constructor or init function:
QSpinBox *spinThreshold = new QSpinBox(this);
spinThreshold->setMinimum(0);
spinThreshold->setMaximum(100);
spinThreshold->setSuffix("°C");

Ccommande cmd = Ccommande::getById(5);
spinThreshold->setValue(static_cast<int>(cmd.getSeulTemperature()));

// When user changes value:
connect(spinThreshold, QOverload<int>::of(&QSpinBox::valueChanged),
        [&cmd](int value) {
            cmd.setSeulTemperature(static_cast<double>(value));
            qDebug() << "Threshold changed to" << cmd.getSeulTemperature() << "°C";
        });
```

## Saving to Database

To persist the temperature threshold to the database:

```cpp
// Update COMMANDE table with new threshold
QSqlQuery query;
query.prepare("UPDATE COMMANDE SET SEUL = :seul WHERE ID = :id");
query.bindValue(":seul", cmd.getSeulTemperature());
query.bindValue(":id", cmd.getIdCommande());

if (!query.exec()) {
    qDebug() << "Failed to update threshold:" << query.lastError().text();
} else {
    qDebug() << "Threshold saved:" << cmd.getSeulTemperature() << "°C";
}
```

## Database Schema Update (Recommended)

### SQL: Add SEUL column to COMMANDE table
```sql
ALTER TABLE COMMANDE ADD (SEUL NUMBER(5,2) DEFAULT 25.0 NOT NULL);
```

### Verify
```sql
SELECT ID, LIBELLE, SEUL FROM COMMANDE;
```

## Default Behavior

| Scenario | Result |
|----------|--------|
| New command created | Threshold = 25°C |
| Read from DB (no SEUL) | Threshold = 25°C |
| Read from DB (with SEUL) | Threshold = DB value |
| Negative value set | Rejected, keeps previous value |
| Zero or positive | Accepted |

## Logging & Debugging

All threshold changes are logged:
```
[Ccommande] Temperature threshold set to 28°C
[Ccommande] Invalid temperature threshold -5, keeping default 25°C
```

To view logs, enable debug output:
```cpp
qDebug() << cmd.getSeulTemperature();  // Prints to console/debug view
```

## Validation

The setter validates input:
- ✅ Accepts: 0, 1.5, 25.0, 100.5
- ❌ Rejects: -1, -10.5 (keeps previous value)

## Related Classes

- **ArduinoEnvironment**: Uses `setCommandeInfo(id, threshold, name)` to configure fan control
- **Ccommande**: Stores and manages the temperature threshold parameter
- **HIS_COMMANDE**: Logs all fan control commands and current temperature

## Files Modified

1. **commande.h**: Added getter/setter declarations
2. **commande.cpp**: Implemented getter/setter and updated constructors
3. **arduino_environment.h/cpp**: Already supports temperature-based control (created previously)
