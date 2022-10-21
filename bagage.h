#ifndef BAGAGE_H
#define BAGAGE_H

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

class BAGAGEData;

class BAGAGE
{
public:
    BAGAGE();
    BAGAGE(QString,QString,int);
    BAGAGE(const BAGAGE &);
    BAGAGE &operator=(const BAGAGE &);
    ~BAGAGE();
    QString GetIDBAGAGE(){return idbagage;}
    QString GetPOIDS(){return poids;}
    int GetCATEG(){return categ;}
    void SetIDBAGAGE(QString val){idbagage=val;}
    void SetPOIDS(QString val){poids=val;}
    void SetCATEG(int val){categ=val;}
    bool ajouter();
    bool modifier(QString idd);
    bool supprimer(QString idd);
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercheB(int index,QString ch);
    QSqlQueryModel * tri(int index1,int index2);

private:
    QSharedDataPointer<BAGAGEData> data;
    QString idbagage,poids;
    int categ;
};

#endif // BAGAGE_H
