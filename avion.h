#ifndef AVION_H
#define AVION_H

//#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
//#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QWebEngineView>
#include <QGraphicsItem>
#include <QtCharts>
#include <QBarSeries>
#include <QBarSet>

class AvionData;

class Avion
{
public:
    Avion();
    Avion(QString,QString,int);
    Avion(const Avion &);
    Avion &operator=(const Avion &);
    ~Avion();
    QString GetID(){return id;}
    QString GetModel(){return model;}
    int GetEtat(){return etat;}
    void SetID(QString val){id=val;}
    void SetModel(QString val){model=val;}
    void SetEtat(int val){etat=val;}
    bool ajouter();
    bool modifier(QString idd);
    bool supprimer(QString idd);
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri(int index1,int index2);
    QSqlQueryModel * recherche(int index,QString ch);
    QChartView *statsAvion (double value,double value2);
    double getAvionenpanne();

private:
    QSharedDataPointer<AvionData> data;
    QString id,model;
    int etat;
};

#endif // AVION_H
