#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

class ProductsPage;
class OrdersPage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupInterface();
    void createConnections();

    QWidget       *m_sidebar        = nullptr;
    QStackedWidget *m_stackedWidget = nullptr;

    ProductsPage  *m_productsPage   = nullptr;  // ← type exact
    OrdersPage    *m_ordersPage     = nullptr;  // ← type exact
};

class Sidebar : public QWidget
{
    Q_OBJECT
public:
    explicit Sidebar(QWidget *parent = nullptr);
};

class ProductsPage : public QWidget
{
    Q_OBJECT
public:
    explicit ProductsPage(QWidget *parent = nullptr);
private:
    void setupUI();

signals:
    void goToOrders();
};

class OrdersPage : public QWidget
{
    Q_OBJECT
public:
    explicit OrdersPage(QWidget *parent = nullptr);
private:
    void setupUI();

signals:
    void goBackToProducts();
};

#endif // MAINWINDOW_H
