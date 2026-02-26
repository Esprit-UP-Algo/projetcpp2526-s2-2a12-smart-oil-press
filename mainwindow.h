#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setAuthenticated(bool authenticated);

signals:
    void addRequested();
    void deleteRequested();
    void updateRequested();
    void exportListeRequested();
    void exportRapportRHRequested();
    void exportFicheRequested();
    // Authentication / password reset signals (UI-only)
    void loginRequested(const QString &username, const QString &password);
    void forgotSendCodeRequested(const QString &userOrEmail);
    void resetPasswordRequested(const QString &code, const QString &newPassword);
    void backToLoginRequested();
    void authenticatedChanged(bool authenticated);

private slots:
    // CRUD Operations
    void ajouterEmploye();
    void afficherEmployes();
    void supprimerEmploye();
    void modifierEmploye();
    void chargerEmployePourModification();
    void onTableRowClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    void styleSpinboxesAndComboboxes();
    void setupCrudConnections();
    void clearAjouterForm();
    void clearModifierForm();
    bool validateAjouterForm();
    bool validateModifierForm();
};

#endif // MAINWINDOW_H
