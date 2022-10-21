#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"connection.h"
#include <QMessageBox>
#include "avion.h"
#include "bagage.h"
#include "client.h"
#include <QWebEngineView>
#include <QGraphicsItem>
#include <QtCharts>
#include <QBarSeries>
#include <QBarSet>
#include <QObject>
#include "vols.h"
#include "smtp.h"
#include "arduino.h"
#include "bagage.h"
#include <QLabel>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void stat_avion();
    ~MainWindow();

private slots:
    void on_Login_clicked();

    void on_Return_clicked();

    void on_loginbut_clicked();

    void on_Return_3_clicked();

    void on_b1_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_10_clicked();

    void on_b7_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_27_clicked();
    void notif(QString t,QString m);
    int loading();


    void on_b3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_45_clicked();

    void on_lineEdit_50_textEdited(const QString &arg1);

    void on_pushButton_39_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_40_clicked();
    void updateSTATAV();
    void on_Login_pressed();

    void on_RechercheB_textEdited(const QString &arg1);

    void on_lineEdit_55_textEdited(const QString &arg1);

    void on_pushButton_52_clicked();

    void on_pushButton_55_clicked();

    void on_pushButton_56_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_57_clicked();

    void on_b5_clicked();

    void on_b4_clicked();

    void on_pushButton_47_clicked();

private:
    Ui::MainWindow *ui;
    QWebEngineView *m_view;
    Avion tmpavion;
    VOLS tmpvol;
    BAGAGE tmpbagage;

};
#endif // MAINWINDOW_H
