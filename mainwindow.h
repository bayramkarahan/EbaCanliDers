#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QDebug>
#include<QDir>
#include<QWidget>
#include<QGridLayout>
#include<QLineEdit>
#include<QLabel>
#include<QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void init();
    void chromeeklentiButtonSlot();
    void linkButtonSlot();
    void chromeButtonSlot();
    void zoomButtonSlot();
    void chromeeklentiButtonClickSlot();
    void linkButtonClickSlot();
    void chromeButtonClickSlot();
    void zoomButtonClickSlot();
    void kurButtonClickSlot();
    void removeButtonClickSlot();
    void kurInitSlot();
    void kontrol();
    void sudoYetkiKontolSlot();
    void passwordKontrolSlot();
    void versionKontrolSlot();
    void zamanlama();
private:
    QString yol="/EbaDers/";
    int boy=60;
    int en=60;
    int btsayisi=9;
    QString version;
    QString sudoyetki="";
    QString user;
    QString passwordstatus;
    bool status;
    QLineEdit *localPassword;
    QLineEdit *localUsername;
    QPushButton *chromeeklentiButton;
    QPushButton *linkButton;
    QPushButton *chromeButton;
    QPushButton *zoomButton;
    QPushButton *kurButton;
    QPushButton *removeButton;
    QPushButton *closeButton;

};

#endif // MAINWINDOW_H
