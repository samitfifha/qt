#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "restauration.h"
#include "produit.h"
 #include <QMessageBox>
#include <QDebug>
#include <QDate>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QTextStream>
#include <QPixmap>
#include "statsami.h"
#include "qcustomplot.h"
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("gestion");
    ui->tabrestaurant_2->setModel(tmp_restaurant.afficher());
    ui->tab_produit->setModel(tmp_produit.afficher());
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    int num_resto = ui->num->text().toInt();
    qDebug()<<num_resto;
    QString type_resto= ui->type_r->text();
    qDebug()<<type_resto;
    int nombre_personnel= ui->nombre->text().toInt();
    qDebug()<<nombre_personnel;
    QString cin=ui->cin1->text();
    qDebug()<<cin;
  restaurant R(num_resto,type_resto,nombre_personnel,cin);
  qDebug()<<"aaaa1";
  bool test=R.ajouter();
  qDebug()<<"aaaa2";
  if(test)
  {
      ui->tabrestaurant_2->setModel(tmp_restaurant.afficher());
      QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                        QObject::tr("client ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_supprimer_clicked()
{
    int id_ch = ui->reference_sup_e->text().toInt();
    bool test=tmp_restaurant.supprimer(id_ch);
    if(test)
    {ui->tabrestaurant_2->setModel(tmp_restaurant.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un restaurant"),
                    QObject::tr("restaurant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un restaurant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_modifier_employe_e2_clicked()
{
    int num_resto = ui->num->text().toInt();
    qDebug()<<num_resto;
    QString type_resto= ui->type_r->text();
    qDebug()<<type_resto;
    int nombre_personnel= ui->nombre->text().toInt();
    qDebug()<<nombre_personnel;
    QString cin=ui->cin1->text();
    qDebug()<<cin;
    restaurant R(num_resto,type_resto,nombre_personnel,cin);
    bool atout=R.modifier(num_resto);
    if(atout)
    {ui->tabrestaurant_2->setModel(tmp_restaurant.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier un restaurant"),
                                 QObject::tr("restaurant modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un restaurant"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_18_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tabrestaurant_2->model()->rowCount();
            const int columnCount = ui->tabrestaurant_2->model()->columnCount();
            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
            out <<"<html>\n"
                  "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                << "<title>ERP - COMmANDE LIST<title>\n "
                << "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<h1 style=\"text-align: center;\"><strong> *****LISTE DES Restaurant ***** "+TT+"</strong></h1>"
                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                  "</br> </br>";
            // headers
            out << "<thead><tr bgcolor=#d6e5ff>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tabrestaurant_2->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tabrestaurant_2->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabrestaurant_2->isColumnHidden(column)) {
                        QString data =ui->tabrestaurant_2->model()->data(ui->tabrestaurant_2->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *baba = new QPrintDialog(&printer, NULL);
            if (baba->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;
}

void MainWindow::on_pushButton_28_clicked()
{
    QString nom_produit = ui->nom_p->text();
    qDebug()<<nom_produit;
    QString date_expiration= ui->date_exp->text();
    qDebug()<<date_expiration;
    QString type_produit= ui->type_p->text();
    qDebug()<<type_produit;
    int quantite=ui->quantite_2->text().toInt();
    qDebug()<<quantite;
    int num_resto=ui->num_re->text().toInt();
    qDebug()<<num_resto;
    int num_produit=ui->num_p->text().toInt();
    qDebug()<<num_produit;
  produit P(nom_produit,date_expiration,type_produit,quantite,num_resto,num_produit);
  qDebug()<<"aaaa1";
  bool test=P.ajouter();
  qDebug()<<"aaaa2";
  if(test)
  {
      ui->tab_produit->setModel(tmp_produit.afficher());
      QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                        QObject::tr("produit ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_26_clicked()
{
    QString nom_produit = ui->nom_p->text();
    qDebug()<<nom_produit;
    QString date_expiration= ui->date_exp->text();
    qDebug()<<date_expiration;
    QString type_produit= ui->type_p->text();
    qDebug()<<type_produit;
    int quantite_produit=ui->quantite_2->text().toInt();
    qDebug()<<quantite_produit;
    int num_resto=ui->num_re->text().toInt();
    qDebug()<<num_resto;
    int num_produit=ui->num_p->text().toInt();
    qDebug()<<num_produit;
    produit P(nom_produit,date_expiration,type_produit,quantite_produit,num_resto,num_produit);
    bool atout=P.modifier(num_produit);
    if(atout)
    {ui->tab_produit->setModel(tmp_produit.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier un produit"),
                                 QObject::tr("produit modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un produit"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tabrestaurant_2_activated(const QModelIndex &index)
{
    ui->tabrestaurant_2->setModel(tmp_restaurant.afficher());

}

void MainWindow::on_tab_produit_activated(const QModelIndex &index)
{
    ui->tab_produit->setModel(tmp_produit.afficher());

}

void MainWindow::on_supprimer_paie_clicked()
{
    int id_ch = ui->reference_sup_e->text().toInt();
    bool test=tmp_produit.supprimer(id_ch);
    if(test)
    {ui->tab_produit->setModel(tmp_produit.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_29_clicked()
{
     ui->tabrestaurant_2->setModel(tmp_restaurant.tri(1));
}

void MainWindow::on_pushButton_30_clicked()
{
    ui->tabrestaurant_2->setModel(tmp_restaurant.tri(0));

}

void MainWindow::on_imprimer_paie_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tabrestaurant_2->model()->rowCount();
        const int columnCount = ui->tabrestaurant_2->model()->columnCount();
        QString TT = QDate::currentDate().toString("yyyy/MM/dd");
        out <<"<html>\n"
              "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            << "<title>ERP - COMmANDE LIST<title>\n "
            << "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<h1 style=\"text-align: center;\"><strong> ******LISTE DES Restos ****** "+TT+"</strong></h1>"
            "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
              "</br> </br>";
        // headers
        out << "<thead><tr bgcolor=#d6e5ff>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabrestaurant_2->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabrestaurant_2->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabrestaurant_2->isColumnHidden(column)) {
                    QString data =ui->tabrestaurant_2->model()->data(ui->tabrestaurant_2->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *baba = new QPrintDialog(&printer, NULL);
        if (baba->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

        delete document;

}

void MainWindow::on_pushButton_9_clicked()
{
ui->tabrestaurant_2->setModel(tmp_restaurant.tri(1));
}

void MainWindow::on_pushButton_17_clicked()
{
 ui->tabrestaurant_2->setModel(tmp_restaurant.tri(0));
}

void MainWindow::on_pushButton_21_clicked()
{
    qDebug()<<"tri";

        int num_resto = ui->chercher_r->text().toInt();
                ui->afficher_trie->setModel(tmp_restaurant.recherche_r(num_resto));
}

void MainWindow::on_statistiques_clicked()
{
    statsami *a=new statsami();
     a->setWindowModality(Qt::ApplicationModal);
    a->show();

}

void MainWindow::on_pushButton_clicked()
{

    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tabrestaurant_2->model()->rowCount();
        const int columnCount = ui->tabrestaurant_2->model()->columnCount();
        QString TT = QDate::currentDate().toString("yyyy/MM/dd");
        out <<"<html>\n"
              "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            << "<title>ERP - COMmANDE LIST<title>\n "
            << "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<h1 style=\"text-align: center;\"><strong> ******LISTE DES Restos ****** "+TT+"</strong></h1>"
            "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
              "</br> </br>";
        // headers
        out << "<thead><tr bgcolor=#d6e5ff>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabrestaurant_2->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabrestaurant_2->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabrestaurant_2->isColumnHidden(column)) {
                    QString data =ui->tabrestaurant_2->model()->data(ui->tabrestaurant_2->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *baba = new QPrintDialog(&printer, NULL);
        if (baba->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

        delete document;

}
