# 📋 Structure du Projet - Gestion de Commande

## 📁 Organisation des Fichiers

```
gestion_de_commande/
│
├── 📄 CMakeLists.txt                 # Configuration CMake
├── 📄 main.cpp                       # Point d'entrée principal
├── 📄 mainwindow.h/cpp               # Fenêtre principale
├── 📄 mainwindow.ui                  # UI fenêtre principale
│
├── 📄 employe_widget.h/cpp           # Widget Gestion des Employés
├── 📄 employe_widget.ui              # UI Widget Employés
│
├── 📄 commande_widget.h/cpp          # Widget Gestion des Commandes
├── 📄 commande_widget.ui             # UI Widget Commandes
│
├── 📄 stylesheet.qss                 # Styles globaux (thème)
├── 📄 resources.qrc                  # Ressources (images, fichiers)
│
├── 📁 widgets/                       # Dossier contenant les widgets
│   ├── 📁 employe/                   # Employé - structure modulaire
│   │   ├── employe_widget.h
│   │   ├── employe_widget.cpp
│   │   └── employe_widget.ui
│   │
│   └── 📁 commande/                  # Commande - structure modulaire
│       ├── commande_widget.h
│       ├── commande_widget.cpp
│       └── commande_widget.ui
│
├── 📁 assets/                        # Dossier des ressources (images, icônes)
│   ├── logo.png
│   ├── up-arrow.svg
│   ├── down-arrow.svg
│   └── icons/
│
└── 📁 build/                         # Dossier de compilation (généré)
    └── Desktop_Qt_6_7_3_MinGW_64_bit-Debug/
```

---

## 🎨 Design & Style

- **Stylesheet Global**: `stylesheet.qss` → Palette de couleurs cohérente
- **Couleurs Principales**:
  - Beige clair (#F8EDE3): fond principal
  - Vert clair (#BDD2B6): éléments de sélection
  - Vert muted (#A2B29F): panneaux secondaires
  - Gris-vert (#798777): textes et éléments foncés

---

## 👤 Gestion des Employés (EmployeWidget)

### Onglets:
1. **Connexion** - Authentification utilisateur
2. **Mot de passe oublié** - Récupération d'accès
3. **Ajouter un employé** - Création de nouvel employé
4. **Liste des employés** - Affichage et filtrage
5. **Supprimer un employé** - Suppression
6. **Modifier un employé** - Mise à jour de données
7. **Statistiques** - KPI et analyses
8. **Export PDF** - Génération de rapports

### Structures:
- Salaire, poste, email, date d'embauche
- Filtrage par statut (actif/inactif)
- Exports: Liste complète, Rapport RH, Fiche employé

---

## 📦 Gestion des Commandes (CommandeWidget)

### Onglets:
1. **Connexion** - Authentification utilisateur
2. **Ajouter une commande** - Création de commande
3. **Liste des commandes** - Affichage et filtrage
4. **Supprimer une commande** - Suppression
5. **Modifier une commande** - Mise à jour de statut/quantité
6. **Statistiques** - Analyse des ventes
7. **Export PDF** - Génération de factures/rapports

### Structures:
- Numéro, client, produit, quantité, prix
- Statuts: En attente, Confirmée, Expédiée, Livrée
- Filtrage par statut
- Exports: Liste complète, Rapport, Fiche commande

---

## 🔧 Architecture Technique

### Classe MainWindow
- Centre de contrôle principal
- Gère la navigation entre widgets
- Charge les styles globaux
- Affiche la barre latérale après authentification

### Classe EmployeWidget (héritage QWidget)
- Widget complet pour gestion des employés
- Signaux pour actions (add, delete, update, export)
- Gestion des onglets visibles selon authentification
- Onglet "Mot de passe oublié" caché mais accessible

### Classe CommandeWidget (héritage QWidget)
- Widget complet pour gestion des commandes
- Signaux pour actions (add, delete, update, export)
- Gestion des onglets visibles selon authentification
- Interface similaire à EmployeWidget pour cohérence UX

---

## 📊 Flux de Navigation

```
Démarrage
    ↓
  MainWindow
    ├─→ [Non authentifié]
    │    ├─→ Barre latérale CACHÉE
    │    └─→ EmployeWidget affichée
    │         └─→ Onglet "Connexion" seul visible
    │
    └─→ [Authentifié après login]
         ├─→ Barre latérale VISIBLE
         ├─→ Tous onglets accessibles
         ├─→ Bouton Employé → EmployeWidget
         ├─→ Bouton Commande → CommandeWidget
         ├─→ Bouton Équipe → Page réservée
         ├─→ Bouton Client → Page réservée
         ├─→ Bouton Laboratoire → Page réservée
         └─→ Bouton Machine → Page réservée
```

---

## 🚀 Comment Étendre le Projet

1. **Ajouter un nouveau widget**:
   - Créer `nouvelle_widget.h/cpp/ui`
   - Créer dossier `widgets/nouvelle/`
   - Copier la structure d'EmployeWidget ou CommandeWidget

2. **Ajouter un nouvel onglet**:
   - Éditer le fichier `.ui` du widget
   - Ajouter `<widget class="QWidget" name="tabNouveau">`
   - Implémenter la logique en C++

3. **Modifier les styles**:
   - Éditer `stylesheet.qss`
   - Les changements s'appliquent globalement

---

## 📝 Notes Importantes

- Les widgets sont **UI-only** pour le moment (pas de logique métier)
- Les signaux sont définis mais pas connectés à des slots d'action réelle
- À chaque authentification, la barre latérale devient visible
- Le système de connexion est simplement UI (pas de vérification réelle)
- Les exports PDF ne font que simuler l'action (À implémenter)

---

**Dernière mise à jour**: 18 février 2026
**Version**: 1.0
