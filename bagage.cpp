#include "bagage.h"

class BAGAGEData : public QSharedData
{
public:

};

BAGAGE::BAGAGE() : data(new BAGAGEData)
{

}

BAGAGE::BAGAGE(const BAGAGE &rhs) : data(rhs.data)
{

}

BAGAGE &BAGAGE::operator=(const BAGAGE &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

BAGAGE::~BAGAGE()
{

}
BAGAGE::BAGAGE(QString a,QString b,int c)
{
    idbagage=a;
    poids=b;
    categ=c;
}
bool BAGAGE::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(categ);
    query.prepare("INSERT INTO BAGAGE (IDBAGAGE,POIDS,CATEGORIE) " "VALUES (:idbagage, :poids, :categ)");
    query.bindValue(":idbagage", idbagage);
    query.bindValue(":poids", poids);
    query.bindValue(":categ", res);
    return query.exec();
}
bool BAGAGE::modifier(QString idd)
{
    QSqlQuery query;
    QString res= QString::number(categ);
    query.prepare("UPDATE BAGAGE SET POIDS=:poids,CATEGORIE=:categ  WHERE IDBAGAGE=:id");
    query.bindValue(":id", idd);
    query.bindValue(":poids", poids);
    query.bindValue(":categ", res);
    return query.exec();
}
bool BAGAGE::supprimer(QString idd)
{
    QSqlQuery query;
    query.prepare("Delete from BAGAGE where IDBAGAGE = :id ");
    query.bindValue(":id", idd);
    return query.exec();
}
QSqlQueryModel * BAGAGE::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from BAGAGE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDBABAGE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    return model;
}
QSqlQueryModel * BAGAGE::rechercheB(int index,QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    switch (index) {
    case 0:{
        model->setQuery("select * from BAGAGE where CATEGORIE like '%"+ch+"%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    }break;
     case 1:{
        model->setQuery("select * from BAGAGE where IDBAGAGE like '%"+ch+"%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    }break;
     case 2:{
        model->setQuery("select * from BAGAGE where POIDS like '%"+ch+"%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    }
    }
    return model;
}
QSqlQueryModel * BAGAGE::tri(int index1,int index2)
{
    QSqlQueryModel * model= new QSqlQueryModel();
switch (index1)
{
case 0:{
    if(index2==0)
    {
        model->setQuery("select * from BAGAGE order by CATEGORIE desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    }
    else
    {
        model->setQuery("select * from BAGAGE order by CATEGORIE asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    }
    break;
}
case 1:{
    if(index2==0)
    {
        model->setQuery("select * from BAGAGE order by IDBAGAGE desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    }
    else
    {
        model->setQuery("select * from BAGAGE order by IDBAGAGE asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    }
    break;
}
case 2:{
    if(index2==0)
    {
        model->setQuery("select * from BAGAGE order by POIDS desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    }
    else
    {
        model->setQuery("select * from BAGAGE order by POIDS asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    }
    break;
}
}
    return model;
}
