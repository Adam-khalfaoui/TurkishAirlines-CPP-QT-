#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QSystemTrayIcon>
#include <QIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->t1_4->setReadOnly(true);
    ui->idlog_3->setReadOnly(true);
    ui->t1_9->setReadOnly(true);
    ui->lineEdit_33->setReadOnly(true);
    QWebEngineView *view = new QWebEngineView(ui->graphicsView);
    view->load(QUrl("https://www.radarbox24.com/@36.33608,10.60567,z6"));
    view->resize(ui->graphicsView->size());
    view->show();
    ui->tableView->setModel(tmpavion.afficher());
    ui->tableView_5->setModel(tmpvol.afficher());
    ui->tableView_2->setModel(tmpbagage.afficher());
    MainWindow::updateSTATAV();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::stat_avion()
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

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);


}
void MainWindow::on_Login_clicked()
{
    if(MainWindow::loading())
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_Return_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_loginbut_clicked()
{
        QSqlQuery qry;
        QString id,password;
        id=ui->lineEdit->text();
        password=ui->lineEdit_2->text();


        if( ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() )
        {
                QMessageBox::warning(nullptr, QObject::tr("Attention"),
                            QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);

        }
        else
        {
            qry.prepare("select * from LOGIN where LOGIN='"+id+"' and PASSWORD='"+password+"' "); //and PASSWORD='"+password+"'"
            if(qry.exec())
            {
                int count=0;
                while(qry.next())
                {
                    count++;
                }
                if (count==1)
                {


                    ui->lineEdit->setText("");
                    ui->lineEdit_2->setText("");
                    ui->stackedWidget->setCurrentIndex(2);
                }
                if(count<1)
                {
                    QMessageBox::critical(nullptr, QObject::tr("Attention"),
                                QObject::tr("Veuillez verifier votre login et mot de passe.\n"), QMessageBox::Ok);
                }
            }



        }

}

void MainWindow::on_Return_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_b1_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_9_clicked()
{

        QString id,model;
        int etat;

        if( ui->idlog->text().isEmpty() || ui->lineEdit_11->text().isEmpty()  )
        {
            ui->tableView->setModel(tmpavion.afficher());//refresh
                QMessageBox::warning(nullptr, QObject::tr("Attention"),
                            QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
        }
        else
        {
        id=ui->idlog->text();
        model=ui->lineEdit_11->text();
        if (ui->comboBox_3->currentIndex()==0)
            etat=1;
        else {
            etat=0;
        }
        Avion av(id,model,etat);
        bool test=av.ajouter();
        if (test)
        {
            ui->tableView->setModel(tmpavion.afficher());
            MainWindow::updateSTATAV();
            MainWindow::notif("Avion","Ajout d'un avion est reussite");
            QMessageBox::information(nullptr, QObject::tr("Ajouter un AVION"),
                              QObject::tr("AVION ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un AVION"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        }

}

void MainWindow::on_pushButton_15_clicked()
{
    QString id,poid;
      int  categorie;
      MainWindow::notif("bagage","Ajout d'un bagage est reussite");
    id=ui->idlog_2->text();
    ui->lineEdit_13->setValidator( new QIntValidator(0, 100, this) );
    poid=ui->lineEdit_13->text();
    if (ui->radioButton_2->isChecked())
        categorie=1;
    else
         categorie=2;

    if( ui->idlog_2->text().isEmpty() || ui->lineEdit_13->text().isEmpty()  )
    {
       // w.show();
            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else {
        BAGAGE b(id,poid,categorie);
        bool test=b.ajouter();






                 if (test)
             {

                   QMessageBox::information(this,tr("Ajout Bagage"),tr("La nouveau Bagage est ajouté avec success"));
                   ui->tableView_2->setModel(tmpbagage.afficher());

                   // reinitialiser tt les champs a vide
                   ui->idlog_2->setText("");
                   ui->lineEdit_13->setText("");

                }
                 else
             {
                     QMessageBox::critical(nullptr, QObject::tr("Ajouter un bagage"),
                                       QObject::tr("Erreur !.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                 }
     }

}

void MainWindow::on_pushButton_14_clicked()
{
    ui->idlog_2->setText("");
    ui->lineEdit_13->setText("");
}

void MainWindow::on_pushButton_13_clicked()
{
    QString id = ui->lineEdit_18->text();
    Avion A;
    bool test=A.supprimer(id);
    if(test)
    {
        ui->tableView->setModel(tmpavion.afficher());
        MainWindow::updateSTATAV();
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Avion"),
                    QObject::tr("Avion supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    QString modele,id;
    int etat;
    QSqlQuery query;
        /*QMessageBox::information(nullptr, QObject::tr("Nouvelle connexion !"),
                                 "Envois de la requête");*/
        query.prepare(
            "SELECT MODEL,ETAT,ID FROM AVION WHERE ID=?");
        query.addBindValue(ui->lineEdit_14->text());

        /* Vérifie si la requête a bien été exécutée */
        if(!query.exec()) {
            QMessageBox::critical(this, tr("Erreur base de données"),
                tr("Erreur lors de l'exécution de la requête: %1")
                                  .arg(query.lastError().text()));
            return;
        }

        /* Vérifie s'il y a des résultats */
        if (!query.first()) {
            QMessageBox::warning(this, QObject::tr("Erreur !"),
                "ID inexistant");
            return;
        }

        /* Récupère les valeurs dans des variables. */
        modele = query.value(0).toString();
        etat=query.value(1).toInt();
        ui->lineEdit_15->setText(modele);
        if (etat==0)
            ui->comboBox_4->setCurrentIndex(1);
        else
            ui->comboBox_4->setCurrentIndex(0);
        id=query.value(2).toString();
        ui->t1_4->setText(id);



        
}

void MainWindow::on_b7_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_12_clicked()
{
    QString idd,modele;
    int etat;
    idd=ui->t1_4->text();
    modele=ui->lineEdit_15->text();
    if (ui->comboBox_4->currentIndex()==0)
        etat=1;
    else {
        etat=0;
    }
    Avion av(idd,modele,etat);
    bool test=av.modifier(idd);
    if (test)
    {
        ui->tableView->setModel(tmpavion.afficher());
        MainWindow::updateSTATAV();
        QMessageBox::information(nullptr, QObject::tr("Modifier un AVION"),
                          QObject::tr("AVION Modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un AVION"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_19_clicked()
{
    QString id = ui->lineEdit_19->text();
    bool test=tmpavion.supprimer(id);
    if(test)
    {
        ui->tableView_2->setModel(tmpbagage.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un BAGAGE"),
                    QObject::tr("BAGAGE supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_16_clicked()
{
    QString poids,id;
    int categ;
    QSqlQuery query;
        /*QMessageBox::information(nullptr, QObject::tr("Nouvelle connexion !"),
                                 "Envois de la requête");*/
        query.prepare(
            "SELECT IDBAGAGE,POIDS,CATEGORIE FROM BAGAGE WHERE IDBAGAGE=?");
        query.addBindValue(ui->lineEdit_16->text());

        /* Vérifie si la requête a bien été exécutée */
        if(!query.exec()) {
            QMessageBox::critical(this, tr("Erreur base de données"),
                tr("Erreur lors de l'exécution de la requête: %1")
                                  .arg(query.lastError().text()));
            return;
        }

        /* Vérifie s'il y a des résultats */
        if (!query.first()) {
            QMessageBox::warning(this, QObject::tr("Erreur !"),
                "ID inexistant");
            return;
        }

        /* Récupère les valeurs dans des variables. */
        id = query.value(0).toString();
        poids=query.value(1).toString();
        categ=query.value(2).toInt();
        ui->lineEdit_20->setText(poids);
        if (categ==1)
            ui->radioButton_3->setChecked(true);
        else
            ui->radioButton_4->setChecked(true);
        ui->idlog_3->setText(id);
}

void MainWindow::on_pushButton_18_clicked()
{
    QString idd,poids;
    int categ;
    idd=ui->idlog_3->text();
    poids=ui->lineEdit_20->text();
    if (ui->radioButton_3->isChecked())
        categ=1;
    else {
        categ=0;
    }
    BAGAGE b(idd,poids,categ);
    bool test=b.modifier(idd);
    if (test)
    {
        ui->tableView_2->setModel(tmpbagage.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier un BAGAGE"),
                          QObject::tr("BAGAGE Modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un BAGAGE"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_22_clicked()
{
    QWebEngineView *view = new QWebEngineView(ui->graphicsView);
    view->load(QUrl("https://www.radarbox24.com/@36.33608,10.60567,z6"));
    view->resize(ui->graphicsView->size());
    view->show();
}

void MainWindow::on_pushButton_29_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_24_clicked()
{
    QString pass,nom,prenom,tel,adresse,dn,sexe,email;
      int  nmbrvoy=0;
    pass=ui->t1_3->text();
    nom=ui->lineEdit_21->text();
    prenom=ui->lineEdit_22->text();
    tel=ui->lineEdit_23->text();
    adresse=ui->lineEdit_30->text();
    dn=ui->de_3->text();
    email=ui->lineEdit_29->text();

    if (ui->r1_2->isChecked())
        sexe="Homme";
    else
         sexe="Femme";

    if( ui->t1_3->text().isEmpty() || ui->lineEdit_21->text().isEmpty()|| ui->lineEdit_22->text().isEmpty()||ui->lineEdit_23->text().isEmpty()||ui->lineEdit_30->text().isEmpty()||ui->lineEdit_29->text().isEmpty() )
    {
       // w.show();
            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else {
        CLIENT C(pass,nom,prenom,adresse,tel,sexe,email,dn,nmbrvoy);
        bool test=C.ajouter();
                 if (test)
             {

                   QMessageBox::information(this,tr("Ajout CLIENT"),tr("Le nouveau CLIENT est ajouté avec success"));

                   // reinitialiser tt les champs a vide


                }
                 else
             {
                     QMessageBox::critical(nullptr, QObject::tr("Ajouter un CLIENT"),
                                       QObject::tr("Erreur !.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                 }
     }

}

void MainWindow::on_pushButton_30_clicked()
{
    CLIENT c;
    ui->tableView_3->setModel(c.afficher());
}

void MainWindow::on_pushButton_28_clicked()
{
    QString nump = ui->lineEdit_28->text();
    CLIENT c;
    bool test=c.supprimer(nump);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Client"),
                    QObject::tr("Client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_25_clicked()
{
    QString numpass,nom,prenom,adresse,tel,email;
    QSqlQuery query;
        /*QMessageBox::information(nullptr, QObject::tr("Nouvelle connexion !"),
                                 "Envois de la requête");*/
        query.prepare(
            "SELECT NOM,PRENOM,NUMPASSPORT,TEL,ADRESSE,EMAIL FROM CLIENT WHERE NUMPASSPORT=?");
        query.addBindValue(ui->lineEdit_24->text());

        /* Vérifie si la requête a bien été exécutée */
        if(!query.exec()) {
            QMessageBox::critical(this, tr("Erreur base de données"),
                tr("Erreur lors de l'exécution de la requête: %1")
                                  .arg(query.lastError().text()));
            return;
        }

        /* Vérifie s'il y a des résultats */
        if (!query.first()) {
            QMessageBox::warning(this, QObject::tr("Erreur !"),
                "ID inexistant");
            return;
        }

        /* Récupère les valeurs dans des variables. */
        nom = query.value(0).toString();
        prenom=query.value(1).toString();
        numpass=query.value(2).toString();
        tel=query.value(3).toString();
        adresse=query.value(4).toString();
        email=query.value(5).toString();

        ui->t1_5->setText(nom);
        ui->lineEdit_25->setText(prenom);
        ui->lineEdit_26->setText(adresse);
        ui->lineEdit_33->setText(numpass);
        ui->lineEdit_27->setText(tel);
        ui->lineEdit_31->setText(email);
}

void MainWindow::on_pushButton_27_clicked()
{
    QString numpass,nom,prenom,adresse,tel,email;
    nom=ui->t1_5->text();
    prenom=ui->lineEdit_25->text();
    adresse=ui->lineEdit_26->text();
    numpass=ui->lineEdit_33->text();
    tel=ui->lineEdit_27->text();
    email=ui->lineEdit_31->text();
    CLIENT c(numpass,nom,prenom,adresse,tel,"",email,"",0);
    bool test=c.modifier(numpass);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modifier un Client"),
                          QObject::tr("Client Modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un Client"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::notif(QString t,QString m)
{
    QPixmap p(32,32);
    p.load("://sources/LOGO.png");
    QIcon icon(p);
    QSystemTrayIcon n(icon);
    n.setVisible(true);
    n.showMessage(t,m,QSystemTrayIcon::Information,1000);

}

void MainWindow::on_b3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_45_clicked()
{
    if (ui->checkBox->isChecked())
    {
        ui->tableView->setModel(tmpavion.tri(ui->comboBox_7->currentIndex(),ui->comboBox_8->currentIndex()));
    }
}

void MainWindow::on_lineEdit_50_textEdited(const QString &arg1)
{
    if(ui->checkBox_2->isChecked())
    {
        ui->tableView->setModel(tmpavion.recherche(ui->comboBox_9->currentIndex(),ui->lineEdit_50->text()));
    }
}

void MainWindow::on_pushButton_39_clicked()
{
    QString nv,ida,ad,dd,aa,da;

    if( ui->t1_8->text().isEmpty() || ui->lineEdit_46->text().isEmpty() ||ui->lineEdit_48->text().isEmpty()||ui->lineEdit_49->text().isEmpty() )
    {
        ui->tableView->setModel(tmpavion.afficher());//refresh
            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else
    {
    nv=ui->t1_8->text();
    ida=ui->lineEdit_46->text();
    ad=ui->lineEdit_48->text();
    dd=ui->dateTimeEdit_5->text();
    aa=ui->lineEdit_49->text();
    da=ui->dateTimeEdit_6->text();

    VOLS v(nv,ida,ad,dd,aa,da);
    bool test=v.ajouter();
    if (test)
    {
        ui->tableView_5->setModel(tmpvol.afficher());
        MainWindow::notif("Vol","Ajout d'un vol est reussite");
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Vol"),
                          QObject::tr("Vol ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un Vol"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }
}

void MainWindow::on_pushButton_43_clicked()
{
    bool test=tmpvol.supprimer(ui->lineEdit_58->text());
    if(test)
    {
        MainWindow::notif("Vol","Supprimer d'un vol est reussite");
        ui->tableView_5->setModel(tmpvol.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Vol"),
                    QObject::tr("Client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_42_clicked()
{
    QString nv,ida,ad,dd,aa,da;
    nv=ui->lineEdit_52->text();
    ida=ui->lineEdit_56->text();
    ad= ui->lineEdit_53->text();
    dd=ui->dateTimeEdit_7->text();
    aa=ui->lineEdit_54->text();
    da=ui->dateTimeEdit_8->text();
    VOLS v(nv,ida,ad,dd,aa,da);
    bool test=v.modifier(ui->lineEdit_52->text());
    if (test)
    {
        MainWindow::notif("Vol","Modifier d'un vol est reussite");
        ui->tableView_5->setModel(tmpvol.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier un Vol"),
                          QObject::tr("Vol Modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un Vol"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

void MainWindow::on_pushButton_40_clicked()
{
    QString nv,ida,ad,aa;
    QDateTime dd,da;
    QSqlQuery query;
        /*QMessageBox::information(nullptr, QObject::tr("Nouvelle connexion !"),
                                 "Envois de la requête");*/
        query.prepare(
            "SELECT * FROM VOL WHERE ID_VOL=?");
        query.addBindValue(ui->lineEdit_52->text());

        /* Vérifie si la requête a bien été exécutée */
        if(!query.exec()) {
            QMessageBox::critical(this, tr("Erreur base de données"),
                tr("Erreur lors de l'exécution de la requête: %1")
                                  .arg(query.lastError().text()));
            return;
        }

        /* Vérifie s'il y a des résultats */
        if (!query.first()) {
            QMessageBox::warning(this, QObject::tr("Erreur !"),
                "ID inexistant");
            return;
        }

        /* Récupère les valeurs dans des variables. */
        nv = query.value(0).toString();
        ida=query.value(1).toString();
        ad=query.value(2).toString();
        dd=query.value(3).toDateTime();
        aa=query.value(4).toString();
        da=query.value(5).toDateTime();

        ui->t1_9->setText(nv);
        ui->lineEdit_56->setText(ida);
        ui->lineEdit_53->setText(ad);
        ui->dateTimeEdit_7->setDateTime(dd);
        ui->lineEdit_54->setText(aa);
        ui->dateTimeEdit_8->setDateTime(da);
}
void MainWindow::updateSTATAV()
{
    QChartView *chart=tmpavion.statsAvion(tmpavion.getAvionenpanne(),100-tmpavion.getAvionenpanne());
    ui->graphicsView_2->setChart(chart->chart());
}
int MainWindow::loading()
{
    QMovie* movie = new QMovie("://sources/animation.gif");
    QLabel* label = new QLabel(this);
    label->setMovie(movie);
    label->resize(200,200);
    QSize r=ui->page->size();
    label->setGeometry(r.width()/2,r.height()/2,200,200);
    movie->start();
    label->show();
    QTimer::singleShot(2500,label,SLOT(close()));
    return 1;
}

void MainWindow::on_Login_pressed()
{
    //MainWindow::loading();
}

void MainWindow::on_RechercheB_textEdited(const QString &arg1)
{
    if(ui->checkBox_4->isChecked())
    {
        ui->tableView_2->setModel(tmpbagage.rechercheB(ui->comboBox_12->currentIndex(),ui->RechercheB->text()));
    }

}

void MainWindow::on_lineEdit_55_textEdited(const QString &arg1)
{
    if(ui->checkBox_8->isChecked())
    {
        ui->tableView_5->setModel(tmpvol.rechercheV(ui->comboBox_18->currentIndex(),ui->lineEdit_55->text()));
    }
}

void MainWindow::on_pushButton_52_clicked()
{
    if(ui->checkBox_7->isChecked())
    {
        ui->tableView_5->setModel(tmpvol.tri(ui->comboBox_16->currentIndex(),ui->comboBox_17->currentIndex()));
    }
}

void MainWindow::on_pushButton_55_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_56_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_54_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_53_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_57_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_b5_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}

void MainWindow::on_b4_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_47_clicked()
{
    if(ui->checkBox_3->isChecked())
    {
        ui->tableView_2->setModel(tmpbagage.tri(ui->comboBox_10->currentIndex(),ui->comboBox_11->currentIndex()));
    }
}
