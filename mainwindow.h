#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "restauration.h"
#include "produit.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_employe_e2_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_26_clicked();

    void on_tabrestaurant_2_activated(const QModelIndex &index);

    void on_tab_produit_activated(const QModelIndex &index);

    void on_supprimer_paie_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_imprimer_paie_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_21_clicked();

    void on_statistiques_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    restaurant tmp_restaurant;
    produit tmp_produit;
};
#endif // MAINWINDOW_H
