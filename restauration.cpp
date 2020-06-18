#include "restauration.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>
restaurant::restaurant()
{
    num_resto=0;
    type_resto="";
   nombre_personnel=0;
   cin="";


}
restaurant::restaurant(int num_resto,QString type_resto,int nombre_personnel,QString cin)
{
this->num_resto=num_resto;
this->type_resto=type_resto;
this->nombre_personnel=nombre_personnel;
this->cin=cin;


}
int restaurant::get_num_resto(){return num_resto;}
QString restaurant::get_type(){return type_resto;}
int restaurant::get_nombre_personnel(){return nombre_personnel;}
QString restaurant:: get_cin(){return cin;}

bool restaurant::ajouter()
{
    QSqlQuery query;
    qDebug()<<"aaaa";
    //QString res= QString::number(cin);

    query.prepare("INSERT INTO restauration (CIN,NUM_RESTO,NOMBRE_PERSONNEL,TYPE_RESTO) "
                  "VALUES (:cin,:num_resto,:nombre_personnel,:type_resto)");
    qDebug()<<"aaaa4";

    query.bindValue(":cin", cin);
    query.bindValue(":num_resto", num_resto);
    query.bindValue(":nombre_personnel", nombre_personnel);
    query.bindValue(":type_resto", type_resto);
    qDebug()<<"aaaa5";

    return    query.exec();
    }

QSqlQueryModel * restaurant::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from restauration");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("num_resto"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre_personnel"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_resto"));
    return model;
}

bool restaurant::supprimer(int num_resto)
{
QSqlQuery query;

query.prepare("Delete from restauration where NUM_RESTO=:num_resto ");
query.bindValue(":num_resto", num_resto);
return    query.exec();
}

bool restaurant::modifier(int num_resto)
{
    QSqlQuery query;
    //int res=num_resto;
   // query.prepare("update abonnepr set id=:id,h_entre=:h_entre,h_sortie=:h_sortie where EMAIL='"+res+"'");
    //query.prepare("UPDATE produit set nom=:nom ,type=:type ,pays=:pays , qt_stock=:quantite  where refproduit ='"+yep+"'");

    query.prepare("update RESTAURATION set CIN=:cin, NOMBRE_PERSONNEL=:nombre_personnel, TYPE_RESTO=:type_resto  where NUM_RESTO=:num_resto");
    query.bindValue(":cin",cin);
    query.bindValue(":nombre_personnel",nombre_personnel);
    query.bindValue(":type_resto",type_resto);
    query.bindValue(":num_resto",num_resto);
    return query.exec();
}

QSqlQueryModel * restaurant::tri(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
        if(index == 0)
        {
            model->setQuery("select *FROM restauration ORDER BY num_resto ASC");
        }
        else
        {
            model->setQuery("select *FROM  restauration ORDER BY num_resto DESC ");
        }


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero restaurant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type restaurant"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre de personnels"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
        return model;
}
QSqlQueryModel * restaurant::recherche_r(int valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    QString valeurch="%"+QString::number(valeur)+"%";

    query.prepare("SELECT * FROM restauration WHERE num_resto LIKE :valeur order by nombre_personnel ");
    query.bindValue(":valeur",valeurch);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("num_resto"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre_personnel"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_resto"));
    return model;
}
