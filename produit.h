#ifndef PRODUIT_H
#define PRODUIT_H
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
class produit
{
public:
produit();
    produit(QString,QString,QString,int,int,int);
    QString get_nom_produit();
    QString get_date_expiration();
    QString get_type_produit();
    int get_quantite_produit();
    int get_num_resto();
    int get_num_produit();
    void set_nom(QString nom_produit1){nom_produit=nom_produit1;}
    void set_date(QString date_expiration1 ){date_expiration=date_expiration1;}
    void set_type(QString type_produit1 ){type_produit=type_produit1;}
    void set_quantite(int quantite_produit1){quantite_produit=quantite_produit1;}
    void set_num(int num_resto1 ){num_resto=num_resto1;}
    void set_num2(int num_produit1){num_produit=num_produit1;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int num_produit);
    QSqlQueryModel * tri(int);



private:
QString nom_produit;
QString date_expiration;
QString type_produit;
int quantite_produit;
int num_resto;
int num_produit;

};

#endif // PRODUIT_H
