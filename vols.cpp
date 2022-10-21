#include "vols.h"

VOLS::VOLS()
{

}
VOLS::VOLS(QString a,QString b,QString c,QString d,QString e,QString f)
{
    numvol=a;
    idavion=b;
    ad=c;
    dd=d;
    aa=e;
    da=f;
}
bool VOLS::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO VOL (ID_VOL, ID_AVION,AERO_DEP,DATE_DEP,AERO_ARR,DATE_ARR) " "VALUES (:nv,:ida,:ad,:dd,:aa,:da)");
    query.bindValue(":nv",numvol);
    query.bindValue(":ida",idavion);
    query.bindValue(":ad", ad);
    query.bindValue(":dd", dd);
    query.bindValue(":aa", aa);
    query.bindValue(":da", da);
    return query.exec();
}
bool VOLS::supprimer(QString idd)
{
    QSqlQuery query;
    query.prepare("Delete from VOL where ID_VOL =:id");
    query.bindValue(":id",idd);
    return query.exec();
}
QSqlQueryModel * VOLS::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from VOL order by DATE_DEP asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    return model;
}
bool VOLS::modifier(QString idd)
{
    QSqlQuery query;
    query.prepare("update VOL set ID_AVION=:ida,AERO_DEP=:ad,DATE_DEP=:dd,AERO_ARR=:aa,DATE_ARR=:da where ID_VOL=:nv" );
    query.bindValue(":nv",idd);
    query.bindValue(":ida",idavion);
    query.bindValue(":ad",ad);
    query.bindValue(":dd",dd);
    query.bindValue(":aa",aa);
    query.bindValue(":da",da);
    return query.exec();
}
QSqlQueryModel * VOLS::rechercheV(int index,QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    switch (index) {
    case 0:{
        model->setQuery("select * from VOL where ID_VOL like '%"+ch+"%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }break;
     case 1:{
        model->setQuery("select * from VOL where ID_AVION like '%"+ch+"%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }break;
     case 2:{
        model->setQuery("select * from VOL where AERO_DEP like '%"+ch+"%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }break;
    case 3:{
       model->setQuery("select * from VOL where AERO_ARR like '%"+ch+"%'");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
   }break;
    case 4:{
       model->setQuery("select * from VOL where DATE_DEP like '%"+ch+"%'");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
   }break;
    case 5:{
       model->setQuery("select * from VOL where DATE_ARR like '%"+ch+"%'");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
   }break;
    }
    return model;

}
QSqlQueryModel * VOLS::tri(int index1,int index2)
{
    QSqlQueryModel * model= new QSqlQueryModel();
switch (index1)
{
case 0:{
    if(index2==0)
    {
        model->setQuery("select * from VOL order by ID_VOL desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }
    else
    {
        model->setQuery("select * from VOL order by ID_VOL asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }
    break;
}
case 1:{
    if(index2==0)
    {
        model->setQuery("select * from VOL order by ID_AVION desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }
    else
    {
        model->setQuery("select * from VOL order by ID_AVION asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }
    break;
}
case 2:{
    if(index2==0)
    {
        model->setQuery("select * from VOL order by AERO_DEP desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }
    else
    {
        model->setQuery("select * from VOL order by AERO_DEP asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }
    break;
}
case 3:{
    if(index2==0)
    {
        model->setQuery("select * from VOL order by AERO_ARR desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }
    else
    {
        model->setQuery("select * from VOL order by AERO_ARR asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }
    break;
}
case 4:{
    if(index2==0)
    {
        model->setQuery("select * from VOL order by DATE_DEP desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }
    else
    {
        model->setQuery("select * from VOL order by DATE_DEP asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }
    break;
}
case 5:{
    if(index2==0)
    {
        model->setQuery("select * from VOL order by DATE_ARR desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }
    else
    {
        model->setQuery("select * from VOL order by DATE_ARR asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num VOl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Avion "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Aeroport Depart"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Depart"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Aeroport Arrivée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Arrivée"));
    }
    break;
}
}
    return model;
}
