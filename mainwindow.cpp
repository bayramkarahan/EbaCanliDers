#include "mainwindow.h"
#include<QProcess>
#include<init.h>
#include<QTimer>
#include<QSize>
#include<QApplication>
#include<QScreen>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(zamanlama()));
    timer->start(1000);

    this->setWindowFlags(Qt::Window|
                       //  Qt::FramelessWindowHint |
                       //Qt::WindowStaysOnTopHint);
                        Qt::X11BypassWindowManagerHint);
    QSize screenSize = qApp->screens()[0]->size();

this->move(screenSize.width()/2,screenSize.height()/2-this->height()/2);

init();
chromeeklentiButtonSlot();
linkButtonSlot();
chromeButtonSlot();
zoomButtonSlot();



}
void MainWindow::zamanlama()
{

this->activateWindow();
//klavyeButtonClick();
    localPassword->setFocus();

}


void MainWindow::kurButtonClickSlot()
{

    kontrol();
    if (status==false) return;
    kurInitSlot();

    QMessageBox::information(this,"Eba Canlı Ders Kurulumu",
                             "\n"
                             "Kurulum tamamlanınca alta bulunan butonlar yeşil olacak ve pasifleşecektir..."
                             "Lütfen bekleyiniz.."

                             "\n"
                             "\n\t         Bayram KARAHAN"
                             "\n\tBilişim Teknolojileri Öğretmeni"
                             "\n"
                             "\n"
                             "İstek ve önerileriniz için;"
                             "\nE-Posta: bayramk@gmail.com"
                             "\nwww.bayramkarahan.blogspot.com"
                             "\n");
     chromeeklentiButtonClickSlot(); chromeeklentiButtonSlot();
    linkButtonClickSlot();          linkButtonSlot();
    chromeButtonClickSlot();        chromeButtonSlot();
    zoomButtonClickSlot();          zoomButtonSlot();
    QMessageBox::information(this,"Eba Canlı Ders Kurulumu",
                             "\n"
                             "\nKurulum Tamamlandı.."
                             "\n");


}
void MainWindow::removeButtonClickSlot()
{

    kontrol();
if (status==false) return;
    QMessageBox::information(this,"Eba Canlı Ders Kurulum Kaldırma",
                             "\n"
                             "Eklentilerin KAldırılması tamamlanınca alta bulunan butonlar kırmızı olacak ve aktifleşecektir..."
                             "Lütfen bekleyiniz.."

                             "\n"
                             "\n\t         Bayram KARAHAN"
                             "\n\tBilişim Teknolojileri Öğretmeni"
                             "\n"
                             "\n"
                             "İstek ve önerileriniz için;"
                             "\nE-Posta: bayramk@gmail.com"
                             "\nwww.bayramkarahan.blogspot.com"
                             "\n");
    QString kmt="echo "+localPassword->text()+" |sudo -S rm -rf /EbaDers ";
    system(kmt.toStdString().c_str());
    system("sleep 1");
    chromeeklentiButtonSlot();

    QString kmt1="echo "+localPassword->text()+" |sudo -S rm -rf /etc/xdg/EbaDersautostart.desktop";
    system(kmt1.toStdString().c_str());
    system("sleep 1");



    //qDebug()<<"komu"<<kmt11;
    system("sleep 1");
    if(version=="3")
    {
        qDebug()<<"Etap 5.2 ve öncesi";
        QString kmt11="echo "+localPassword->text()+" |sudo -S rm -rf "+QDir::homePath()+"/Masaüstü/EbaDers.desktop";
        system(kmt11.toStdString().c_str());

    }
    else if(version=="4")
    {
        QString kmt111="echo "+localPassword->text()+" |sudo -S rm -rf "+QDir::homePath()+"/Masaüstü/EbaDers19.desktop";
        system(kmt111.toStdString().c_str());

    }
    linkButtonSlot();

    QString kmt2="echo "+localPassword->text()+" |sudo -S dpkg -r google-chrome-stable";
    system(kmt2.toStdString().c_str());
    system("sleep 1");
    chromeButtonSlot();

    QString kmt3="echo "+localPassword->text()+" |sudo -S dpkg -r zoom";
    system(kmt3.toStdString().c_str());
    system("sleep 1");

    zoomButtonSlot();
    QMessageBox::information(this,"Eba Canlı Ders Kurulum Kaldırma",
                             "\n"
                             "\nEklentiler Kaldırıldı.."
                             "\n");
}
void MainWindow::chromeeklentiButtonSlot()
{

    if(QDir(yol+"chromeeklenti").exists()==true)
    {
       // qDebug()<<"bb";
        chromeeklentiButton->setEnabled(false);
        chromeeklentiButton->setStyleSheet("background-color: #00ee00");
    }
    else
    {
       // qDebug()<<"cc";
        chromeeklentiButton->setEnabled(true);
        chromeeklentiButton->setStyleSheet("background-color: #ee0000");
    }


        connect(chromeeklentiButton, &QPushButton::clicked, [=]() {

            kontrol();
            if (status==false) return;
            chromeeklentiButtonClickSlot();

     });

}

void MainWindow::linkButtonSlot()
{
   // qDebug()<<"link:"<<yol+"EbaDers.desktop";
     if(QFileInfo::exists(yol+"EbaDers.desktop"))
     {
         linkButton->setEnabled(false);
         linkButton->setStyleSheet("background-color: #00ee00");
     }
     else
     {
         linkButton->setEnabled(true);
         linkButton->setStyleSheet("background-color: #ee0000");
     }
     connect(linkButton, &QPushButton::clicked, [=]() {
        kontrol();
        if (status==false) return;
         linkButtonClickSlot();

  });


}

void MainWindow::chromeButtonSlot()
{
    if(QFileInfo::exists("/usr/bin/google-chrome"))
  {
      chromeButton->setEnabled(false);
      chromeButton->setStyleSheet("background-color: #00ee00");
  }
  else
  {
      chromeButton->setEnabled(true);
      chromeButton->setStyleSheet("background-color: #ee0000");
  }
  connect(chromeButton, &QPushButton::clicked, [=]() {
    kontrol();
    if (status==false) return;
     chromeButtonClickSlot();
});
}

void MainWindow::zoomButtonSlot()
{
    if(QFileInfo::exists("/usr/bin/zoom"))
     {
         zoomButton->setEnabled(false);
         zoomButton->setStyleSheet("background-color: #00ee00");
     }
     else
     {
         zoomButton->setEnabled(true);
         zoomButton->setStyleSheet("background-color: #ee0000");
     }
     connect(zoomButton, &QPushButton::clicked, [=]() {
        kontrol();
        if (status==false) return;
        zoomButtonClickSlot();

  });
}

void MainWindow::chromeeklentiButtonClickSlot()
{
    qDebug()<<"chrome eklenti kuruluyor";
    if(QDir(yol).exists()==false)
    {
        qDebug()<<"Klasör Yok Oluşturuluyor..";
    QString kmt="echo "+localPassword->text()+" |sudo -S mkdir "+yol;
    system(kmt.toStdString().c_str());
    system("sleep 1");
    }

    QString kmt="echo "+localPassword->text()+" |sudo -S unzip "+QDir::currentPath()+"/chromeeklenti.zip -d "+yol+"chromeeklenti";
    system(kmt.toStdString().c_str());
   /* system("sleep 1");
    chromeeklentiButton->setEnabled(false);
    chromeeklentiButton->setStyleSheet("background-color: #00ee00");
*/
chromeeklentiButtonSlot();
}
void MainWindow::linkButtonClickSlot()
{
    if(QDir(yol).exists()==false)
    {
     //   qDebug()<<"Klasör Yok Oluşturuluyor..";
    QString kmt="echo "+localPassword->text()+" |sudo -S mkdir "+yol;
    system(kmt.toStdString().c_str());
    system("sleep 1");
    }

    if(version=="3")
    {
        QString kmt0="echo "+localPassword->text()+" |sudo -S cp "+QDir::currentPath()+"/EbaDers.desktop "+QDir::homePath()+"/Masaüstü/";
        system(kmt0.toStdString().c_str());
        system("sleep 1");

        QString kmt="echo "+localPassword->text()+" |sudo -S cp "+QDir::currentPath()+"/EbaDers.desktop "+yol;
        system(kmt.toStdString().c_str());
        system("sleep 1");

        QString kmt1="echo "+localPassword->text()+" |sudo -S cp "+QDir::currentPath()+"/EbaDers.ico "+yol;
        system(kmt1.toStdString().c_str());
        system("sleep 1");


    }
    else if(version=="4")
    {
        QString kmt0="echo "+localPassword->text()+" |sudo -S cp "+QDir::currentPath()+"/EbaDers19.desktop "+QDir::homePath()+"/Masaüstü/EbaDers.desktop";
        system(kmt0.toStdString().c_str());
        system("sleep 1");

        QString kmt="echo "+localPassword->text()+" |sudo -S cp "+QDir::currentPath()+"/EbaDers19.desktop "+yol+"EbaDers.desktop";
        system(kmt.toStdString().c_str());
        system("sleep 1");

        QString kmt1="echo "+localPassword->text()+" |sudo -S cp "+QDir::currentPath()+"/EbaDers.png "+yol;
        system(kmt1.toStdString().c_str());
        system("sleep 1");

    }
    else
    {
        QMessageBox::information(this,"Eba Canlı Ders Kurulumu",
                                 "\n"
                                 "\nUygun Pardus Sürümü Değil..");

    }


    QString kmt2="echo "+localPassword->text()+" |sudo -S cp "+QDir::currentPath()+"/EbaDersautostart.desktop "+"/etc/xdg/autostart/";
    system(kmt2.toStdString().c_str());
    system("sleep 1");

    QString kmt3="echo "+localPassword->text()+" |sudo -S cp "+QDir::currentPath()+"/EbaDersLink.sh "+yol;
    system(kmt3.toStdString().c_str());
    /*system("sleep 1");

    linkButton->setEnabled(false);
    linkButton->setStyleSheet("background-color: #00ee00");*/
linkButtonSlot();
}
void MainWindow::chromeButtonClickSlot()
{
    if(version=="3")
    {
        QString kmt="echo "+localPassword->text()+" |sudo -S gdebi -n "+QDir::currentPath()+"/chrome.deb";
        system(kmt.toStdString().c_str());
    }
    else if(version=="4")
    {
        QString kmt="echo "+localPassword->text()+" |sudo -S gdebi -n "+QDir::currentPath()+"/chrome19.deb";
        system(kmt.toStdString().c_str());
    }
    else
    {
        QMessageBox::information(this,"Eba Canlı Ders Kurulumu",
                                 "\n"
                                 "\nUygun Pardus Sürümü Değil..");

    }

  chromeButtonSlot();
}
void MainWindow::zoomButtonClickSlot()
{
    if(version=="3")
    {
        QString kmt0="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install -f -y'";
        system(kmt0.toStdString().c_str());

        QString kmt="echo "+localPassword->text()+" |sudo -S gdebi -n "+QDir::currentPath()+"/zoom.deb";
        system(kmt.toStdString().c_str());

        QString kmt7="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install -f -y'";
        system(kmt7.toStdString().c_str());

    }
    else if(version=="4")
    {
        QString kmt0="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install -f -y'";
        system(kmt0.toStdString().c_str());

        QString kmt="echo "+localPassword->text()+" |sudo -S gdebi -n "+QDir::currentPath()+"/zoom19.deb";
        system(kmt.toStdString().c_str());

        QString kmt7="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install -f -y'";
        system(kmt7.toStdString().c_str());


    }else
    {
        QMessageBox::information(this,"Eba Canlı Ders Kurulumu",
                                 "\n"
                                 "\nUygun Pardus Sürümü Değil..");

    }

zoomButtonSlot();
}
void MainWindow::kurInitSlot()
{


    if(version=="3")
    {
        qDebug()<<"Etap 5.2 ve öncesi";
        /****************repo key edit********************/
          QString kmt05="echo "+localPassword->text()+" |sudo -S dpkg -i "+QDir::currentPath()+"/parduskey.deb";
          system(kmt05.toStdString().c_str());
          /****************repo adres güncellemeleri********************/
          QString kmt04="echo "+localPassword->text()+" |sudo -S su -c 'echo deb http://depo.pardus.org.tr/etap stable main non-free contrib > /etc/apt/sources.list'";
          system(kmt04.toStdString().c_str());

          QString kmt03="echo "+localPassword->text()+" |sudo -S su -c 'echo deb http://depo.pardus.org.tr/etap-guvenlik stable main non-free contrib >> /etc/apt/sources.list'";
          system(kmt03.toStdString().c_str());

          /*************sudo apt-get clean***********************/
          QString kmt02="echo "+localPassword->text()+" |sudo -S su -c 'rm -rf /etc/apt/sources.list.d/*'";
          system(kmt02.toStdString().c_str());
          /*************sudo apt-get autoclean***********************/
          QString kmt01="echo "+localPassword->text()+" |sudo -S su -c 'rm -rf /etc/apt/sources.list.d/*'";
          system(kmt01.toStdString().c_str());

          /*************repo ayarlarını sil***********************/
          QString kmt00="echo "+localPassword->text()+" |sudo -S su -c 'rm -rf /etc/apt/sources.list.d/*'";
          system(kmt00.toStdString().c_str());

          /*********************sudo apt-get update**************/
          QString kmt2="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install -f -y'";
          system(kmt2.toStdString().c_str());

          QString kmt3="echo "+localPassword->text()+" |sudo -S su -c 'apt-get update'";
          system(kmt3.toStdString().c_str());

          QString kmt4="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install gdebi -y'";
          system(kmt4.toStdString().c_str());
          QString kmt5="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install -f -y'";
          system(kmt5.toStdString().c_str());

        QString kmt6="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install -y ttf-mscorefonts-installer'";
        system(kmt6.toStdString().c_str());

        QString kmt7="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install -f -y'";
        system(kmt7.toStdString().c_str());


    }
    else if(version=="4")
    {
        qDebug()<<"Etap 5.2 Sonrası";


         /*********************sudo apt-get update**************/
          QString kmt2="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install -f -y'";
          system(kmt2.toStdString().c_str());

          QString kmt3="echo "+localPassword->text()+" |sudo -S su -c 'apt-get update'";
          system(kmt3.toStdString().c_str());

          QString kmt4="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install gdebi -y'";
          system(kmt4.toStdString().c_str());
          QString kmt5="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install -f -y'";
          system(kmt5.toStdString().c_str());

        QString kmt6="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install -y ttf-mscorefonts-installer ttf-dejavu ttf-xfree86-nonfre'";
        system(kmt6.toStdString().c_str());

        QString kmt7="echo "+localPassword->text()+" |sudo -S su -c 'apt-get install -f -y'";
        system(kmt7.toStdString().c_str());

    }
    else
    {
        QMessageBox::information(this,"Eba Canlı Ders Kurulumu",
                                 "\n"
                                 "\nUygun Pardus Sürümü Değil..");

    }


}

void MainWindow::kontrol()
{
    status=true;
    versionKontrolSlot();
    /********************password null text kontrol********************************/

     if(localPassword->text()=="")
    {
        QMessageBox::information(this,"Eba Canlı Ders Kurulumu","Lütfen Şifre Giriniz..");
        status=false;
        return;
    }
    /*********************sudo yetki kontrol*************************/
   sudoYetkiKontolSlot();
     if(sudoyetki=="0")
    {
        QMessageBox::information(this,"Eba Canlı Ders Kurulumu","Lütfen Yetkili Bir Kullanıcı ile Kurulum Yapınız..");
        status=false;
        return;
    }

    /*************************şifre kontrol***********************/
   passwordKontrolSlot();
   if(passwordstatus=="0")
    {
        QMessageBox::information(this,"Eba Canlı Ders Kurulumu","Lütfen Şifrenizi Doğru Giriniz..");
        status=false;
        return;
    }


}
MainWindow::~MainWindow()
{

}
