/*****************************************************************************
 *   Copyright (C) 2020 by Bayram KARAHAN                                    *
 *   <bayramk@gmail.com>                                                     *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 3 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .          *
 *****************************************************************************/
void MainWindow::sudoYetkiKontolSlot()
{
    /*******************sudo yetki kontrol**************************/
   user=QDir::homePath().split("/")[2];
    QStringList arguments1;
            arguments1 << "-c" << QString("id "+user+"|grep 'sudo'");
            QProcess process1;
            process1.start("/bin/bash",arguments1);
             if(process1.waitForFinished())
    {
        sudoyetki = process1.readAll();
        if (sudoyetki=="") sudoyetki="0";else sudoyetki="1";
       //   result.chop(3);
    }
             //qDebug()<<"sudoyetki:"<<sudoyetki;
}

void MainWindow::passwordKontrolSlot()
{
    /***************password kontrol***************************/
QString result="";


    QString kmt0="sudo -k|echo "+localPassword->text()+"|sudo -S su -c 'touch ~/ebaeba'";
    qDebug()<<"komut "<<kmt0;
    system(kmt0.toStdString().c_str());
    /****************************/
     QStringList arguments3;
             arguments3 << "-c";
             QString kmt="sudo -k|echo "+localPassword->text()+"|sudo -S su -c 'ls /root/ebaeba|wc -l'";
             arguments3 <<kmt;
             QProcess process3;
             process3.start("/bin/bash",arguments3);
              if(process3.waitForFinished())
     {
        result=process3.readAll();
         }
              result.chop(1);
            //  qDebug()<<"sonuç:"<<result;
    /**************************************/


    system("sleep 1");
               if(result=="1")
                 {
                  passwordstatus="1";

                  //qDebug()<<"Şifre: doğru "<<passwordstatus;

                 }else
                 {
                     passwordstatus="0";
                    // qDebug()<<"Şifre: yanlış "<<passwordstatus;
                 }
               QString kmt2="echo "+localPassword->text()+" |sudo -S su -c 'rm -rf /root/ebaeba'";
               system(kmt2.toStdString().c_str());


             //}
       //  qDebug()<<"Şifre:"<<passwordstatus;

}

void MainWindow::versionKontrolSlot()
{
    /*********************version kontrol*****************************/
    QString result="";
    QStringList arguments;
            arguments << "-c" << QString("uname -a|awk '{print $3}'");
            QProcess process;
            process.start("/bin/bash",arguments);
             if(process.waitForFinished())
    {
        version = process.readAll();
       //   result.chop(3);
    }

version=version.left(1);
//qDebug()<<"version:"<<version;
}

void MainWindow::init()
{
user=QDir::homePath().split("/")[2];


/*****************************************************/
    setWindowTitle("Canlı Ders");
            this->resize(en*5,boy*btsayisi);
            setFixedHeight(boy*btsayisi);
            setFixedWidth(en*5);
         //   Qt::WindowFlags flags = 0;
           //flags |= Qt::Window;
         //  flags |= Qt::Tool;
          // flags |= Qt::CustomizeWindowHint;
          // this->setWindowFlags(flags);


    auto *lineWidget=new QWidget(this);
    lineWidget->resize(en*5,boy*btsayisi);
    lineWidget->move(0,0);
    lineWidget->setStyleSheet("background-color: #acacac");

    /****************Yerel Kullanıcı****************************************************/

    QLabel *localuserLabel=new QLabel(lineWidget);
    localuserLabel->setText("Kullanıcı Adı");
    localuserLabel->setStyleSheet("background-color: #acacac");

    localUsername=new QLineEdit(lineWidget);
    localUsername->setFixedSize(en*5,boy);
    localUsername->setText("etapadmin");
    localUsername->setStyleSheet("background-color: #ffffff");

    QLabel *localpasswordLabel=new QLabel(lineWidget);
    localpasswordLabel->setText("sudo Yetkili "+QDir::homePath()+" Şifresi");
    localpasswordLabel->setStyleSheet("background-color: #acacac");

    localPassword=new QLineEdit(lineWidget);
    localPassword->setFixedSize(en*5,boy);
    localPassword->setEchoMode(QLineEdit::Password);
    localPassword->setStyleSheet("background-color: #ffffff");

//localPassword->setText("1");
/*******************************************************/

    kurButton= new QPushButton(lineWidget);
    kurButton->setFixedSize(en*5, boy);
    kurButton->setIconSize(QSize(en*5,boy));
    kurButton->setText("Eba Canlı Ders Kur");
    kurButton->setStyleSheet("Text-align:left");
    connect(kurButton, SIGNAL(clicked()),this, SLOT(kurButtonClickSlot()));

    removeButton= new QPushButton(lineWidget);
    removeButton->setFixedSize(en*5, boy);
    removeButton->setIconSize(QSize(en*5,boy));
    removeButton->setText("Eba Canlı Ders Kaldır");
    removeButton->setStyleSheet("Text-align:left");
    connect(removeButton, SIGNAL(clicked()),this, SLOT(removeButtonClickSlot()));

    chromeeklentiButton= new QPushButton(lineWidget);
    chromeeklentiButton->setFixedSize(en*5, boy);
    chromeeklentiButton->setIconSize(QSize(en*5,boy));
    chromeeklentiButton->setText("Chrome Eklentisini Yükle");
    chromeeklentiButton->setStyleSheet("Text-align:left");
    //connect(listePcButton, SIGNAL(clicked()),this, SLOT(listePcSlot()));

    linkButton= new QPushButton(lineWidget);
    linkButton->setFixedSize(en*5, 50);
    linkButton->setIconSize(QSize(en*5,50));
    linkButton->setText("Masaüstü Kısayol Oluştur");
    linkButton->setStyleSheet("Text-align:left");

    chromeButton= new QPushButton(lineWidget);
    chromeButton->setFixedSize(en*5, 50);
    chromeButton->setIconSize(QSize(en*5,50));
    chromeButton->setText("Chrome Kur");
    chromeButton->setStyleSheet("Text-align:left");

    zoomButton= new QPushButton(lineWidget);
    zoomButton->setFixedSize(en*5, 50);
    zoomButton->setIconSize(QSize(en*5,50));
    zoomButton->setText("Zoom Kur");
    zoomButton->setStyleSheet("Text-align:left");

    closeButton= new QPushButton(lineWidget);
    closeButton->setFixedSize(en*5, 50);
    closeButton->setIconSize(QSize(en*5,50));
    closeButton->setText("Çık");
    closeButton->setStyleSheet("Text-align:center");

    connect(closeButton, &QPushButton::clicked, [=]() {

        exit(0);
});
    /**************************************************************/
        // auto widget = new QWidget(this);
      auto layout = new QGridLayout(lineWidget);
      layout->setContentsMargins(0, 0, 0,0);
      layout->setVerticalSpacing(0);
    //  layout->setColumnMinimumWidth(0, 37);
     /* localuserLabel
              localusername

               localpasswordLabel
              localpassword*/


   // layout->addWidget(localUsername, 1,0,1,2);
    layout->addWidget(localpasswordLabel, 1,0,1,2);
    layout->addWidget(localPassword, 2,0,1,2);
    layout->addWidget(kurButton, 3,0,1,2);

    layout->addWidget(removeButton, 4,0,1,2);

     layout->addWidget(chromeeklentiButton, 6,0,1,2);
    layout->addWidget(linkButton, 7,0,1,2);
    layout->addWidget(chromeButton, 8,0,1,2);
    layout->addWidget(zoomButton, 9,0,1,2);
    layout->addWidget(closeButton, 10,0,1,2);



}
