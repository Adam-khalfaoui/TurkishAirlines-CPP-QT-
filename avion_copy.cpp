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

    model->setQuery("select * from AVION");
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
void Avion::stat_grs()
{
    QPieSeries *series = new QPieSeries();
    series->append("Jane", 1);
    series->append("Joe", 2);
    series->append("Andy", 3);
    series->append("Barbara", 4);
    series->append("Axel", 5);

    QPieSlice *slice = series->slices().at(1);
    slice->setExploded();
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple piechart example");
    chart->legend()->hide();

    QChartView *chartView = new QChartView();
    chartView->setRenderHint(QPainter::Antialiasing);
}
