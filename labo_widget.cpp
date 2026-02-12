#include "labo_widget.h"
#include "ui_labo_widget.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>

namespace {

const char kDialogButtonStyle[] =
    "QPushButton { "
    "  background-color: #A2B29F; "
    "  color: #F8EDE3; "
    "  padding: 8px 20px; "
    "  border-radius: 4px; "
    "  font-weight: bold; "
    "  border: none; "
    "} "
    "QPushButton:hover { "
    "  background-color: #BDD2B6; "
    "  color: #798777; "
    "} "
    "QPushButton:pressed { "
    "  background-color: #A2B29F; "
    "}";

QString getStyledTextInput(QWidget* parent,
                          const QString& title,
                          const QString& label)
{
    QInputDialog dialog(parent);
    dialog.setInputMode(QInputDialog::TextInput);
    dialog.setWindowTitle(title);
    dialog.setLabelText(label);
    dialog.setTextEchoMode(QLineEdit::Normal);
    dialog.setOkButtonText("OK");
    dialog.setCancelButtonText("Annuler");
    dialog.setStyleSheet(
        "QDialog { background-color: #FFFFFF; } "
        "QLabel { color: #2C2C2C; } "
        "QLineEdit { background-color: #FFFEF9; border: 1px solid #D5D5D5; border-radius: 6px; padding: 8px 12px; } "
        "QLineEdit:focus { border: 2px solid #A2B29F; } "
        + QString::fromLatin1(kDialogButtonStyle)
    );

    if (dialog.exec() != QDialog::Accepted) {
        return {};
    }
    return dialog.textValue();
}

}

LaboWidget::LaboWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LaboWidget)
{
    ui->setupUi(this);
    
    // Connecter le bouton Supprimer
    connect(ui->btnDeleteLab, &QPushButton::clicked, this, &LaboWidget::onDeleteLabClicked);
    
    // Connecter le bouton Modifier
    connect(ui->btnEditLab, &QPushButton::clicked, this, &LaboWidget::onEditLabClicked);
}

LaboWidget::~LaboWidget()
{
    delete ui;
}

void LaboWidget::onDeleteLabClicked()
{
    // Demander l'ID à supprimer
    QString idText = getStyledTextInput(
        this,
        "Supprimer un laboratoire",
        "Entrez l'ID du laboratoire à supprimer :"
    );

    if (idText.trimmed().isEmpty()) {
        return; // Utilisateur a annulé
    }
    
    // Chercher la ligne correspondante dans le tableau
    QTableWidget* table = ui->tableLaboratoires;
    int rowToDelete = -1;
    
    for (int row = 0; row < table->rowCount(); ++row) {
        QTableWidgetItem* item = table->item(row, 0); // Colonne ID
        if (item && item->text() == idText) {
            rowToDelete = row;
            break;
        }
    }
    
    if (rowToDelete == -1) {
        QMessageBox warningBox(this);
        warningBox.setWindowTitle("Laboratoire non trouvé");
        warningBox.setText("Aucun laboratoire avec l'ID " + idText + " n'a été trouvé.");
        warningBox.setIcon(QMessageBox::Warning);
        warningBox.setStandardButtons(QMessageBox::Ok);
        QString buttonStyle = "QPushButton { background-color: #798777; color: white; padding: 8px 20px; border-radius: 4px; font-weight: bold; } QPushButton:hover { background-color: #6A7A66; }";
        warningBox.button(QMessageBox::Ok)->setStyleSheet(buttonStyle);
        warningBox.exec();
        return;
    }
    
    // Demander confirmation
    QTableWidgetItem* nameItem = table->item(rowToDelete, 1);
    QString labName = nameItem ? nameItem->text() : "(sans nom)";
    
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Confirmer la suppression");
    msgBox.setText(QString("Voulez-vous vraiment supprimer le laboratoire :\n\n"
                           "ID: %1\n"
                           "Nom: %2 ?").arg(idText, labName));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    
    // Appliquer le style vert aux boutons
    QString buttonStyle = "QPushButton { background-color: #798777; color: white; padding: 8px 20px; border-radius: 4px; font-weight: bold; } QPushButton:hover { background-color: #6A7A66; }";
    msgBox.button(QMessageBox::Yes)->setStyleSheet(buttonStyle);
    msgBox.button(QMessageBox::No)->setStyleSheet(buttonStyle);
    
    QMessageBox::StandardButton reply = (QMessageBox::StandardButton)msgBox.exec();
    
    if (reply == QMessageBox::Yes) {
        // Supprimer la ligne
        table->removeRow(rowToDelete);
        
        QMessageBox successBox(this);
        successBox.setWindowTitle("Suppression réussie");
        successBox.setText("Le laboratoire a été supprimé avec succès.");
        successBox.setIcon(QMessageBox::Information);
        successBox.setStandardButtons(QMessageBox::Ok);
        successBox.button(QMessageBox::Ok)->setStyleSheet(buttonStyle);
        successBox.exec();
    }
}

void LaboWidget::onEditLabClicked()
{
    // Demander l'ID à modifier
    QString idText = getStyledTextInput(
        this,
        "Modifier un laboratoire",
        "Entrez l'ID du laboratoire à modifier :"
    );

    if (idText.trimmed().isEmpty()) {
        return; // Utilisateur a annulé
    }
    
    // Chercher la ligne correspondante dans le tableau
    QTableWidget* table = ui->tableLaboratoires;
    int currentRow = -1;
    
    for (int row = 0; row < table->rowCount(); ++row) {
        QTableWidgetItem* item = table->item(row, 0); // Colonne ID
        if (item && item->text() == idText) {
            currentRow = row;
            break;
        }
    }
    
    // Récupérer les valeurs actuelles (ou vides si non trouvé)
    QString id = idText;
    QString nom = "";
    QString type = "";
    QString adresse = "";
    QString review = "";
    QString espace = "";
    QString reste = "";
    
    if (currentRow >= 0) {
        nom = table->item(currentRow, 1) ? table->item(currentRow, 1)->text() : "";
        type = table->item(currentRow, 2) ? table->item(currentRow, 2)->text() : "";
        adresse = table->item(currentRow, 3) ? table->item(currentRow, 3)->text() : "";
        review = table->item(currentRow, 4) ? table->item(currentRow, 4)->text() : "";
        espace = table->item(currentRow, 5) ? table->item(currentRow, 5)->text() : "";
        reste = table->item(currentRow, 6) ? table->item(currentRow, 6)->text() : "";
    }
    
    // Créer la boîte de dialogue
    QDialog dialog(this);
    dialog.setWindowTitle("Modifier le laboratoire");
    dialog.setMinimumWidth(500);
    
    // Appliquer le style vert au dialogue
    dialog.setStyleSheet(
        "QDialog { background-color: #FFFFFF; } "
        + QString::fromLatin1(kDialogButtonStyle)
    );
    
    QFormLayout* formLayout = new QFormLayout(&dialog);
    
    // ID (lecture seule)
    QLineEdit* idEdit = new QLineEdit(id);
    idEdit->setReadOnly(true);
    idEdit->setStyleSheet("background-color: #F5F5F5;");
    formLayout->addRow("ID Laboratoire:", idEdit);
    
    // Nom
    QLineEdit* nomEdit = new QLineEdit(nom);
    formLayout->addRow("Nom:", nomEdit);
    
    // Type
    QComboBox* typeCombo = new QComboBox();
    typeCombo->addItem("Laboratoire Huile d'Olive");
    typeCombo->addItem("Laboratoire Huile d'Amande");
    typeCombo->addItem("Laboratoire Huile de Sésame");
    typeCombo->addItem("Laboratoire Huile de Nigelle");
    typeCombo->addItem("Laboratoire Huile de Tournesol");
    if (!type.isEmpty()) {
        typeCombo->setCurrentText(type);
    }
    formLayout->addRow("Type:", typeCombo);
    
    // Adresse
    QLineEdit* adresseEdit = new QLineEdit(adresse);
    formLayout->addRow("Adresse / Site:", adresseEdit);
    
    // Review
    QComboBox* reviewCombo = new QComboBox();
    reviewCombo->addItem("⭐");
    reviewCombo->addItem("⭐⭐");
    reviewCombo->addItem("⭐⭐⭐");
    reviewCombo->addItem("⭐⭐⭐⭐");
    reviewCombo->addItem("⭐⭐⭐⭐⭐");
    if (!review.isEmpty()) {
        reviewCombo->setCurrentText(review);
    }
    formLayout->addRow("Review (5):", reviewCombo);
    
    // Espace
    QLineEdit* espaceEdit = new QLineEdit(espace);
    formLayout->addRow("Espace (m²):", espaceEdit);
    
    // Reste
    QLineEdit* resteEdit = new QLineEdit(reste);
    formLayout->addRow("Reste (m²):", resteEdit);
    
    // Boutons OK/Annuler
    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (QPushButton* okButton = buttonBox->button(QDialogButtonBox::Ok)) {
        okButton->setStyleSheet(QString::fromLatin1(kDialogButtonStyle));
    }
    if (QPushButton* cancelButton = buttonBox->button(QDialogButtonBox::Cancel)) {
        cancelButton->setStyleSheet(QString::fromLatin1(kDialogButtonStyle));
    }
    
    formLayout->addRow(buttonBox);
    
    // Afficher la boîte de dialogue
    if (dialog.exec() == QDialog::Accepted) {
        if (currentRow >= 0) {
            // Mettre à jour les valeurs dans le tableau
            table->item(currentRow, 1)->setText(nomEdit->text());
            table->item(currentRow, 2)->setText(typeCombo->currentText());
            table->item(currentRow, 3)->setText(adresseEdit->text());
            table->item(currentRow, 4)->setText(reviewCombo->currentText());
            table->item(currentRow, 5)->setText(espaceEdit->text());
            table->item(currentRow, 6)->setText(resteEdit->text());
            
            QMessageBox successBox(this);
            successBox.setWindowTitle("Modification réussie");
            successBox.setText("Le laboratoire a été modifié avec succès.");
            successBox.setIcon(QMessageBox::Information);
            successBox.setStandardButtons(QMessageBox::Ok);
            QString msgBoxStyle = "QPushButton { background-color: #798777; color: white; padding: 8px 20px; border-radius: 4px; font-weight: bold; } QPushButton:hover { background-color: #6A7A66; }";
            successBox.button(QMessageBox::Ok)->setStyleSheet(msgBoxStyle);
            successBox.exec();
        } else {
            QMessageBox infoBox(this);
            infoBox.setWindowTitle("Laboratoire non trouvé");
            infoBox.setText("L'ID " + idText + " n'existe pas dans la liste.\nLes données n'ont pas été sauvegardées.");
            infoBox.setIcon(QMessageBox::Information);
            infoBox.setStandardButtons(QMessageBox::Ok);
            QString msgBoxStyle = "QPushButton { background-color: #798777; color: white; padding: 8px 20px; border-radius: 4px; font-weight: bold; } QPushButton:hover { background-color: #6A7A66; }";
            infoBox.button(QMessageBox::Ok)->setStyleSheet(msgBoxStyle);
            infoBox.exec();
        }
    }
}