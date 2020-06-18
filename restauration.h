#ifndef RESTAURATION_H
#define RESTAURATION_H
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
class restaurant
{
    public:
 restaurant();
    restaurant(int,QString,int,QString);
    QString get_type();
    QString get_cin();
    int get_num_resto();
    int get_nombre_personnel();
     void set_type(QString type){type_resto=type;}
    void set_nom(QString cin1 ){cin=cin1;}
    void set_prenom(int num_resto1 ){num_resto=num_resto1;}
    void set_nombre(int nombre_personnel1){nombre_personnel=nombre_personnel1;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int num_resto);
    QSqlQueryModel * tri(int);
    QSqlQueryModel * recherche_r(int valeur);





    private :
    int num_resto;
    QString type_resto;
    int nombre_personnel;
    QString cin;
};

#endif // RESTAURATION_H
