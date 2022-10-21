#include "client.h"

class CLIENTData : public QSharedData
{
public:

};

CLIENT::CLIENT() : data(new CLIENTData)
{

}

CLIENT::CLIENT(const CLIENT &rhs) : data(rhs.data)
{

}

CLIENT &CLIENT::operator=(const CLIENT &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

CLIENT::~CLIENT()
{

}
CLIENT::CLIENT(QString a,QString b,QString c,QString d,QString e,QString f,QString g,QString x,int h)
{
    numpass=a;
    nom=b;
    prenom=c;
    adresse=d;
    tel=e;
    sexe=f;
    email=g;
    nmbrvoy=h;
    dn=x;
}
bool CLIENT::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(nmbrvoy);
    query.prepare("INSERT INTO CLIENT (NUMPASSPORT, NOM, PRENOM,DN,TEL,ADRESSE,EMAIL,SEXE,NBRVOLS) " "VALUES (:pass, :nom,:prenom ,:dn,:tel,:adresse,:email,:sexe,:nmbrvoy)");
    query.bindValue(":pass", numpass);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":dn",dn);
    query.bindValue(":tel",tel);
    query.bindValue(":adresse",adresse);
    query.bindValue(":email",email);
    query.bindValue(":sexe",sexe);
    query.bindValue(":nmbrvoy", res);
    return query.exec();
}
QSqlQueryModel * CLIENT::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUM PASSPORT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DE NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-MAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("NOMBRE DE VOLS"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("SEXE"));
    return model;
}
bool CLIENT::supprimer(QString nump)
{
    QSqlQuery query;
    query.prepare("Delete from CLIENT where NUMPASSPORT = :nump ");
    query.bindValue(":nump", nump);
    return query.exec();
}
bool CLIENT::modifier(QString nump)
{
    QSqlQuery query;
    QString res= QString::number(nmbrvoy);
    query.prepare("UPDATE CLIENT SET  NOM=:nom, PRENOM=:prenom,TEL=:tel,ADRESSE=:adresse,EMAIL=:email WHERE NUMPASSPORT=:pass");
    query.bindValue(":pass", nump);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":tel",tel);
    query.bindValue(":adresse",adresse);
    query.bindValue(":email",email);
    return query.exec();
}
