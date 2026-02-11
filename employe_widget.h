#ifndef EMPLOYE_WIDGET_H
#define EMPLOYE_WIDGET_H

#include <QWidget>
#include <QString>

namespace Ui { class EmployeWidget; }

class EmployeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeWidget(QWidget *parent = nullptr);
    ~EmployeWidget();

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

private:
    Ui::EmployeWidget *ui;
    void styleSpinboxesAndComboboxes();
};

#endif // EMPLOYE_WIDGET_H
