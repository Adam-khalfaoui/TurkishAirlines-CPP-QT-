#ifndef RESERVATION_H
#define RESERVATION_H

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


class reservation
{
public:
    reservation();
    reservation(QString,QString,QString,QString,QString);
    bool ajouter();
    bool modifier(QString idd);
    bool supprimer(QString idd);

private:
    QString numres,idclient,numvola,numvolr,classe;

};

#endif // RESERVATION_H
