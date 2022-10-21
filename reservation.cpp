#include "reservation.h"

reservation::reservation()
{

}
reservation::reservation(QString a,QString b,QString c,QString d,QString f)
{
    numres=a;
    idclient=b;
    numvola=c;
    numvolr=d;
    classe=f;
}
bool reservation::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO AVION (ID, MODEL, ETAT) " "VALUES (:numres,:idclient,:numvola,:numvolr,:classe)");
    query.bindValue(":numres", numres);
    query.bindValue(":idclient", idclient);
    query.bindValue(":numvola", numvola);
    query.bindValue(":numvolr", numvolr);
    query.bindValue(":classe", classe);
    return query.exec();
}
bool reservation::supprimer(QString idd)
{
    QSqlQuery query;
    query.prepare("Delete * from RESERVATION where NUM_RESERVATION= :id ");
    query.bindValue(":id", idd);
    return query.exec();
}
