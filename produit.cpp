#include "produit.h"
#include "restauration.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>
produit::produit()
{

        nom_produit="";
       quantite_produit=0;
       date_expiration="";
       type_produit="";
       num_resto=0;
       num_produit=0;
}
produit::produit(QString nom_produit,QString date_expiration,QString type_produit,int quantite_produit,int num_resto,int num_produit)
{
this->nom_produit=nom_produit;
this->quantite_produit=quantite_produit;
this->date_expiration=date_expiration;
this->type_produit=type_produit;
this->num_resto=num_resto;
this->num_produit=num_produit;
}
QString produit::get_nom_produit(){return nom_produit;}
QString produit::get_date_expiration(){return date_expiration;}
QString produit::get_type_produit(){return type_produit;}
int produit::get_quantite_produit(){return quantite_produit;}
int produit::get_num_resto(){return  num_resto;}
int produit::get_num_produit(){return num_produit;}

bool produit::ajouter()
{
    QSqlQuery query;
    qDebug()<<"aaaa";
    //QString res= QString::number(cin);

    query.prepare("INSERT INTO produit (NOM_produit,DATE_EXPIRATION,TYPE_produit,QUANTITE_produit,NUM_RESTO,NUM_produit) "
                  "VALUES (:nom_produit,:date_expiration,:type_produit,:quantite_produit,:num_resto,:num_produit)");
    qDebug()<<"aaaa4";

    query.bindValue(":nom_produit",nom_produit);
    query.bindValue(":date_expiration", date_expiration);
    query.bindValue(":type_produit", type_produit);
    query.bindValue(":quantite_produit", quantite_produit);
    query.bindValue(":num_resto", num_resto);
    query.bindValue(":num_produit", num_produit);
    qDebug()<<"aaaa5";

    return    query.exec();
    }
QSqlQueryModel * produit::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from produit");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom_produit"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("quantite_produit"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_expiration"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_produit"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_resto"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("num_produit"));

    return model;
}
bool produit::supprimer(int num_produit)
{
QSqlQuery query;

query.prepare("Delete from produit where NUM_PRODUIT=:num_produit ");
query.bindValue(":num_produit", num_produit);
return    query.exec();
}
bool produit::modifier(int nom_produit)
{
    QSqlQuery query ;

                query.prepare("update PRODUIT set NOM_PRODUIT=:nom_produit, DATE_EXPIRATION=:date_expiration, TYPE_PRODUIT=:type_produit, QUANTITE_PRODUIT=:quantite_produit, NUM_RESTO=:num_resto where num_produit=:num_produit");
                query.bindValue(":nom_produit",nom_produit);
                query.bindValue(":date_expiration",date_expiration);
                query.bindValue(":type_produit",type_produit);
                query.bindValue(":quantite_produit",quantite_produit);
                query.bindValue(":num_resto",num_resto);
                query.bindValue(":num_produit",num_produit);
            return  query.exec();

    }

