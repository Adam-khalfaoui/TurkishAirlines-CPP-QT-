#include "avion.h"

class AvionData : public QSharedData
{
public:

};
Avion::Avion(QString a,QString b,int c)
{
    id=a;
    model=b;
    etat=c;
}

Avion::Avion() : data(new AvionData)
{

}

Avion::Avion(const Avion &rhs) : data(rhs.data)
{

}

Avion &Avion::operator=(const Avion &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Avion::~Avion()
{

}
bool Avion::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(etat);
    query.prepare("INSERT INTO AVION (ID, MODEL, ETAT) " "VALUES (:id, :model, :etat)");
    query.bindValue(":id", id);
    query.bindValue(":model", model);
    query.bindValue(":etat", res);
    return query.exec();
}
bool Avion::supprimer(QString idd)
{
    QSqlQuery query;
    query.prepare("Delete from AVION where ID = :id ");
    query.bindValue(":id", idd);
    return query.exec();
}
QSqlQueryModel * Avion::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from AVION ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MODEL "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}
bool Avion::modifier(QString idd)
{
    QSqlQuery query;
    QString res= QString::number(etat);
    query.prepare("UPDATE AVION SET MODEL=:model,ETAT=:etat WHERE ID=:id" );
    query.bindValue(":id", idd);
    query.bindValue(":model", model);
    query.bindValue(":etat", res);
    return query.exec();
}
QSqlQueryModel * Avion::tri(int index1,int index2)
{
    QSqlQueryModel * model= new QSqlQueryModel();
switch (index1)
{
case 0:{
    if(index2==0)
    {
        model->setQuery("select * from AVION order by MODEL desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MODEL "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    }
    else
    {
        model->setQuery("select * from AVION order by MODEL asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MODEL "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    }
    break;
}
case 1:{
    if(index2==0)
    {
        model->setQuery("select * from AVION order by ID desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MODEL "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    }
    else
    {
        model->setQuery("select * from AVION order by ID asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MODEL "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    }
    break;
}
case 2:{
    if(index2==0)
    {
        model->setQuery("select * from AVION order by ETAT desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MODEL "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    }
    else
    {
        model->setQuery("select * from AVION order by ETAT asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MODEL "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    }
    break;
}
}
    return model;
}
QSqlQueryModel * Avion::recherche(int index,QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    switch (index) {
    case 0:{
        model->setQuery("select * from AVION where MODEL like '%"+ch+"%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MODEL "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    }break;
     case 1:{
        model->setQuery("select * from AVION where ID like '%"+ch+"%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MODEL "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    }break;
     case 2:{
        model->setQuery("select * from AVION where ETAT like '%"+ch+"%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MODEL "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    }
    }
    return model;
}
QChartView * Avion::statsAvion (double value,double value2)
{
    //![1]
        QPieSeries *series = new QPieSeries();
        series->setHoleSize(0.35);
        //series->append("Protein 4.2%", 4.2);
        QPieSlice *slice = series->append("Avion En Panne", value);
        slice->setExploded();
        slice->setLabelVisible();
        //series->append("Other 23.8%", 23.8);
        series->append("Avion En Marche ", value2);
    //![1]

    //![2]
        QChartView *chartView = new QChartView();
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->chart()->setTitle("AVION STATS");
        chartView->chart()->addSeries(series);
        chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
        chartView->chart()->setTheme(QChart::ChartThemeDark);
        chartView->chart()->legend()->setFont(QFont("Cairo", 7));
    //![2]
        return chartView;
}
double Avion::getAvionenpanne()
{
   QSqlQuery requete1;
   QSqlQuery requete2;
   requete1.prepare("select count(*) from AVION");

   requete2.prepare("select count(*)from AVION WHERE ETAT='0'");
   requete2.exec();

   requete1.exec();

   requete2.next();
   requete1.next();

   double s=0;
   int k=requete1.value(0).toInt();
   int b=requete2.value(0).toInt();
   s=(b*100)/k;
   return s;
}
