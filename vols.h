#ifndef VOLS_H
#define VOLS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class VOLS
{
public:
    VOLS();
    VOLS(QString,QString,QString,QString,QString,QString);
    QString Getnumvol(){return numvol;}
    QString Getidavion(){return idavion;}
    QString Getad(){return ad;}
    QString Getdd(){return dd;}
    QString Getaa(){return ad;}
    QString Getda(){return dd;}
    bool ajouter();
    bool modifier(QString idd);
    bool supprimer(QString idd);
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri(int index1,int index2);
    QSqlQueryModel * rechercheV(int index,QString ch);
private:
    QString numvol,idavion,ad,dd,aa,da;
};

#endif // VOLS_H
