#include "equipe_widget.h"

#include <QTabWidget>
#include <QStackedWidget>

EquipeWidget::EquipeWidget(QWidget *parent)
    : QWidget(parent)
    , m_topNavTabs(nullptr)
    , m_stackedWidget(nullptr)
{
    // Créez les widgets manuellement
    m_topNavTabs = new QTabWidget(this);
    m_stackedWidget = new QStackedWidget(this);
    
    // Setup manuel des tabs
    m_topNavTabs->addTab("Ajouter");
    m_topNavTabs->addTab("Gestion");
    m_topNavTabs->addTab("Supprimer");
    m_topNavTabs->addTab("Modifier");
    m_topNavTabs->addTab("Statistique");
    m_topNavTabs->addTab("Suggestion");
    m_topNavTabs->addTab("Planification");
    
    // Connecter le signal
    connect(m_topNavTabs, &QTabWidget::currentChanged, 
            this, &EquipeWidget::on_topNavTabs_currentChanged);
    
    // Layout simple
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_topNavTabs);
    layout->addWidget(m_stackedWidget);
    setLayout(layout);
    
    // Initialiser à la première page
    on_topNavTabs_currentChanged(0);
}

EquipeWidget::~EquipeWidget()
{
    // Pas besoin de delete ui
}

void EquipeWidget::on_topNavTabs_currentChanged(int index)
{
    switch (index) {
    case 0: // Ajouter
        m_stackedWidget->setCurrentIndex(0);
        break;
    case 1: // Gestion
        m_stackedWidget->setCurrentIndex(1);
        break;
    case 2: // Supprimer
        m_stackedWidget->setCurrentIndex(2);
        break;
    case 3: // Modifier
        m_stackedWidget->setCurrentIndex(3);
        break;
    case 4: // Statistique
        m_stackedWidget->setCurrentIndex(4);
        break;
    case 5: // Suggestion
        m_stackedWidget->setCurrentIndex(5);
        break;
    case 6: // Planification
        m_stackedWidget->setCurrentIndex(6);
        break;
    default:
        break;
    }
}
