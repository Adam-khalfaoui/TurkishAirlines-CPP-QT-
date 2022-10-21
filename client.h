#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>

class CLIENTData;

class CLIENT
{
public:
    CLIENT();
    CLIENT(QString,QString,QString,QString,QString,QString,QString,QString,int);
    CLIENT(const CLIENT &);
    CLIENT &operator=(const CLIENT &);
    ~CLIENT();
    int GetNMBRVOY(){return nmbrvoy;}
    void SetPASS(QString val){numpass=val;}
    void SetNOM(QString val){nom=val;}
    void SetPRENOM(QString val){prenom=val;}
    void SetADRESSE(QString val){adresse=val;}
    void SetTEL(QString val){tel=val;}
    void SetSEXE(QString val){sexe=val;}
    void SetEMAIL(QString val){email=val;}
    QString GetNOM(){return nom;}
    QString GetPRENOM(){return prenom;}
    QString GetPASS(){return numpass;}
    QString GetADRESSE(){return adresse;}
    QString GetTEL(){return tel;}
    QString GetSEXE(){return sexe;}
    QString GetEMAIL(){return email;}
    bool ajouter();
    bool modifier(QString nump);
    bool supprimer(QString nump);
    QSqlQueryModel * afficher();

private:
    QSharedDataPointer<CLIENTData> data;
    QString numpass,nom,prenom,adresse,tel,sexe,email,dn;
    int nmbrvoy;
};

#endif // CLIENT_H
