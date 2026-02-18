# 🎯 Gestion de Commande - Application Qt 6

Application de gestion complète avec gestion des employés et gestion des commandes, utilisant Qt 6.7.3 avec design cohérent.

## ✨ Fonctionnalités

### 👤 Gestion des Employés
- ✅ **Authentification** avec système de récupération de mot de passe
- ✅ **CRUD complet**: Ajouter, éditer, supprimer, consulter
- ✅ **Listage** avec filtrage (Tous, Actifs, Inactifs)
- ✅ **Statistiques**: Effectifs, finances, performance
- ✅ **Export PDF**: Liste complète, Rapport RH, Fiche employé
- ✅ **Interface moderne** avec tabs et formulaires intuitifs

### 📦 Gestion des Commandes
- ✅ **CRUD complet**: Ajouter, éditer, supprimer, consulter
- ✅ **Listage** avec filtrage par statut (En attente, Confirmée, Expédiée, Livrée)
- ✅ **Statistiques**: Nombre de commandes, revenus totaux
- ✅ **Export PDF**: Liste complète, Rapport, Fiche commande
- ✅ **Gestion des statuts** de commande
- ✅ **Interface identique** aux employés pour cohérence

### 🎨 Design
- 🎨 **Thème moderne** avec palette couleur cohérente
- 🎨 **Responsive** et adapté aux différentes résolutions
- 🎨 **Stylesheet global** pour uniformité visuelle
- 🎨 **Navigation intuitive** depuis la barre latérale

---

## 📁 Structure du Projet

```
gestion_de_commande/
│
├── 📄 main.cpp                          ← Point d'entrée
├── 📄 mainwindow.h / mainwindow.cpp     ← Fenêtre principale
├── 📄 mainwindow.ui                     ← Layout fenêtre principale
│
├── 📄 employe_widget.h / .cpp / .ui     ← Widget Gestion des Employés
├── 📄 commande_widget.h / .cpp / .ui    ← Widget Gestion des Commandes
│
├── 📄 stylesheet.qss                    ← Styles globaux
├── 📄 resources.qrc                     ← Ressources (images, icons)
│
├── 📁 widgets/
│   ├── 📁 employe/                      ← Dossier employé (futur)
│   └── 📁 commande/                     ← Dossier commande (futur)
│
├── 📁 assets/                           ← Images et ressources
├── 📁 build/                            ← Compilation (généré)
│
├── CMakeLists.txt                       ← Configuration build
└── STRUCTURE.md                         ← Documentation architecture
```

---

## 🚀 Démarrage

### Prérequis
- **Qt Creator** 6.7.3 ou supérieur
- **Qt Framework** 6.0+
- **CMake** 3.16+
- **MinGW 64-bit** (ou compilateur compatible)

### Compilation
```bash
# Depuis Qt Creator
1. Fichier → Ouvrir le fichier ou le projet
2. Sélectionnez CMakeLists.txt
3. Configurez avec votre kit Qt 6.7.3
4. Cliquez sur "Compiler" (Ctrl+B)
5. Cliquez sur "Exécuter" (Ctrl+R)
```

Ou via terminal:
```bash
mkdir build && cd build
cmake ..
cmake --build .
./gestion_de_commande
```

---

## 📖 Utilisation

### 1️⃣ Authentification
- L'application démarre sur l'écran de connexion
- Onglet "Connexion" du widget Employé
- Possibilité de réinitialiser le mot de passe (UI-only)

### 2️⃣ Navigation
Une fois connecté:
- Barre latérale devient visible
- Boutons pour naviguer entre sections:
  - 👤 **EMPLOYÉ** → Gestion des employés
  - 📦 **COMMANDE** → Gestion des commandes
  - 👥 **ÉQUIPE** (réservé)
  - 👨‍💼 **CLIENT** (réservé)
  - 🧪 **LABORATOIRE** (réservé)
  - ⚙️ **MACHINE** (réservé)

### 3️⃣ Gestion des Employés
- **Onglet "Ajouter"**: Formulaire pour création (Nom, Prénom, Email, Poste, Salaire, Date)
- **Onglet "Liste"**: Tableau avec filtres (Tous/Actifs/Inactifs)
- **Onglet "Supprimer"**: Suppression par ID avec confirmation
- **Onglet "Modifier"**: Mise à jour des données
- **Onglet "Statistiques"**: KPI (Total, Actifs, Masse salariale, Salaire moyen)
- **Onglet "Export PDF"**: Génération de rapports

### 4️⃣ Gestion des Commandes
- **Onglet "Ajouter"**: Création de commande (Client, Produit, Quantité, Prix, Statut)
- **Onglet "Liste"**: Tableau avec filtrage par statut
- **Onglet "Supprimer"**: Suppression de commande
- **Onglet "Modifier"**: Changement de statut/quantité
- **Onglet "Statistiques"**: Nombre de commandes, revenus
- **Onglet "Export PDF"**: Factures et rapports

---

## 🎨 Personnalisation

### Modifier les couleurs
Éditer `stylesheet.qss`:
```qss
/* Couleurs principales */
#F8EDE3 → Beige clair (fond)
#BDD2B6 → Vert clair (sélections)
#A2B29F → Vert moyen (boutons)
#798777 → Gris-vert (textes sombres)
```

### Ajouter un nouvel onglet
1. Ouvrir le fichier `.ui` du widget dans Qt Designer
2. Ajouter un nouveau tab au TabWidget
3. Designer l'interface
4. Implémenter la logique en C++

### Ajouter un nouveau widget
1. Copier `employe_widget.h/cpp/ui`
2. Renommer en `nouvelle_widget.h/cpp/ui`
3. Mettre à jour les noms de classe
4. Inclure dans mainwindow.cpp
5. Ajouter les variables globales au CMakeLists.txt

---

## 📊 Architecture des Widgets

### EmployeWidget (QWidget)

```cpp
class EmployeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EmployeWidget(QWidget *parent = nullptr);
    void setAuthenticated(bool authenticated);
    
signals:
    void addRequested();
    void deleteRequested();
    void updateRequested();
    void exportListeRequested();
    void exportRapportRHRequested();
    void exportFicheRequested();
    void loginRequested(const QString &user, const QString &pass);
    void authenticatedChanged(bool authenticated);
};
```

### CommandeWidget (QWidget)

```cpp
class CommandeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CommandeWidget(QWidget *parent = nullptr);
    void setAuthenticated(bool authenticated);
    
signals:
    void addRequested();
    void deleteRequested();
    void updateRequested();
    void exportListeRequested();
    void exportRapportRequested();
    void exportFicheRequested();
    void loginRequested(const QString &user, const QString &pass);
    void authenticatedChanged(bool authenticated);
};
```

---

## 🔧 Points d'Extension

Actuellement les widgets sont **UI-only**. Pour implémenter la logique métier:

### 1. Connecter les signaux
```cpp
// Dans mainwindow.cpp
connect(employe, &EmployeWidget::addRequested, this, &MainWindow::onAddEmploye);
connect(commande, &CommandeWidget::addRequested, this, &MainWindow::onAddCommande);
```

### 2. Implémenter les slots
```cpp
void MainWindow::onAddEmploye() {
    QString nom = employe->getSelectedNom();
    // Logique de persistence...
}
```

### 3. Ajouter une couche données
```cpp
class EmployeManager {
    QVector<Employe> m_employes;
    bool add(const Employe &emp);
    bool update(const Employe &emp);
    bool remove(int id);
    QVector<Employe> getAll();
};
```

### 4. Intégrer une base de données
- Utiliser QSqlDatabase pour SQLite, MySQL, PostgreSQL
- Wrapper les requêtes dans EmployeManager et CommandeManager
- Émettre les signaux après opération réussie

---

## 🐛 Dépannage

### "Erreur: ui_employewidget.h/ui_commandewidget.h non trouvé"
- CMakeLists.txt manque les fichiers `.ui`
- Solution: Ajouter à PROJECT_SOURCES:
  ```cmake
  employe_widget.ui
  commande_widget.ui
  ```

### "Bouton reste grisé après connexion"
- Vérifier le signal `loginRequested` est connecté
- Vérifier appel à `setAuthenticated(true)` après login

### "Tableau vide dans Liste"
- Les données sont UI-only (simulation)
- À implémenter: charger depuis une source de données

### Style QSS ne s'applique pas
- Vérifier le chemin dans `resources.qrc`
- Vérifier le fichier doit être recompilé après modification

---

## 📝 Fichiers Modifiés/Créés

✅ **Créés:**
- `employe_widget.h/cpp/ui` - Widget gestion des employés
- `commande_widget.h/cpp/ui` - Widget gestion des commandes
- `widgets/employe/` - Dossier d'organisation employé
- `widgets/commande/` - Dossier d'organisation commande
- `STRUCTURE.md` - Documentation architecture

✅ **Modifiés:**
- `mainwindow.cpp` - Intégration des 2 widgets
- `CMakeLists.txt` - Ajout des nouveaux fichiers

---

## 🎯 Prochaines Étapes

1. **Implémentation de la logique**
   - Créer managers/services pour gestion des données
   - Connecter les signaux aux slots
   - Implémenter la persistance (BD ou fichiers)

2. **Amélioration UI**
   - Ajouter des icônes aux boutons
   - Implémenter le thème sombre
   - Améliorer les animations

3. **Autres modules**
   - Widget pour Équipe
   - Widget pour Clients
   - Widget pour Laboratoire
   - Widget pour Machines

4. **Export/Import**
   - Générer PDF réels
   - Import/export CSV/Excel
   - Emails automatiques

---

## 📄 Licence & Droits

Ne pas utiliser pour usage commercial sans permission.

---

**Dernière mise à jour**: 18 février 2026  
**Auteur**: Hassen  
**Version**: 1.0.0  
**État**: ✅ Structure complète, UI-only

