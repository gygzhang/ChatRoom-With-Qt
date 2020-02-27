#pragma once
#include "widget.h"
#include "ui_widget.h"
//#include <QDebug>
#include    <iostream>
#include<stdio.h>
#include<QFile>
#include<windows.h>
#include<QThreadPool>
#include<QTime>
#include<QPixmap>
#include<QBuffer>
#include<QImageReader>
#include<chat_face.h>
#include <thread>
#include <mutex>


std::mutex mtx;


QString imgPath;
QString _name;
QString prevStr=NULL;
QFile file("C:\\Users\\asus\\Desktop\\chatLog.txt");
QString text =  NULL;
 QString modea ;

using namespace std;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QDateTime time = QDateTime::currentDateTime();
    QString current_date = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->txtShow->setText("\n" +ui->txtShow->toPlainText()+ "\n\n");
    socket = new QTcpSocket(this);
    socket_2 = new QTcpSocket(this);
    socket->connectToHost("47.106.185.108",5000);
    socket_2->connectToHost("47.106.185.108",8000);

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(sendMesage()));
   connect(socket,SIGNAL(readyRead()),this,SLOT(readMessage()));

    connect(socket_2,SIGNAL(readyRead()),this,SLOT(recvImg()));
    //connect(ui->pic,SIGNAL(clicked()),this,SLOT(sendImg()));
    socket->write("#RENAME "+_name.toLocal8Bit(),100);

}

void Widget::CloseChat()
{
    this->close();
}

void Widget::sendMesage()
{
    QDateTime time = QDateTime::currentDateTime();
    QString current_date = time.toString("yyyy-MM-dd hh:mm:ss");
    if(ui->txtContext->toPlainText().length() < 1000)
    {
        QString temp=NULL;
        textToBeSend = ui->txtContext->toPlainText();
        temp = textToBeSend+"\r\n";
        if(temp.endsWith('\n')&&!temp.startsWith('\n')&&!textToBeSend.isEmpty()){
            qDebug()<<"the text:"+text;
            text+=textToBeSend+"\r\n";

            file.open(QIODevice::ReadWrite);
            qint64 pos;
            pos = file.size();
            file.seek(pos);
            //qDebug()<<content;
            QString raking = "【管理员】";
           // QByteArray tem= raking.toLocal8Bit();
            //raking =
            file.write(raking.toUtf8()+_name.toUtf8()+" "+current_date.toUtf8()+"\r\n"+textToBeSend.toUtf8());
            file.close();
            //ui->txtShow->append("<img src=':/3440/face.png'>");
            ui->txtShow->append(raking.toUtf8()+" "+_name+" "+current_date.toUtf8()+"\r\n"+textToBeSend.toUtf8());

        }

        socket->write(temp.toLocal8Bit(),temp.toLocal8Bit().count()+3);
        //socket->flush();

        //ui->txtShow->setText(ui->txtShow->toPlainText()+"\n"+ ui->txtName->text() + "   " + current_date + "\n" + ui->txtContext->toPlainText() + "\n\n");
    }
    else
    {
        ui->txtShow->setText(ui->txtShow->toPlainText()+"\n"+current_date + "not good~~~\n\n");
    }
            ui->txtContext->clear();
}

void Widget::readMessage()
{
    QDateTime time = QDateTime::currentDateTime();
    QString current_date = time.toString("yyyy-MM-dd hh:mm:ss");
    //qDebug()<<a;
    QByteArray recv=NULL;
    recv= socket->readAll();
    //qDebug()<<QString::fromLocal8Bit(recv);
    QString test=recv;
    if(test.contains("img"))
    {
       qDebug()<<"aaaaaa"+test;
    }
    qDebug()<<"the recv:"+test;//存在问题
    if(!recv.isEmpty()&&test.endsWith('\n'))
    {
        if(test!=prevStr)
        {      
            QString msg = ui->txtShow->toPlainText();//get the text in the inputbox
            msg=msg+textToBeSend;

            recv += msg;
            QString str = QString::fromLocal8Bit(recv);

            QByteArray readmsg;
            QString raking = "【普通人】";
            QByteArray tem= raking.toLocal8Bit();

            readmsg = FileWrite(QString::fromLocal8Bit(tem)+" "+current_date+"\r\n"+str,41);

            ui->txtShow->append(QString::fromLocal8Bit(tem)+" "+current_date+"\r\n"+str+"\r\n");
        }

        prevStr=test;

    }

}



Widget::~Widget()
{

    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Return)
    {

        sendMesage();
    }
}



QByteArray Widget::FileWrite(QString content,qint16 a)
{

        file.open(QIODevice::ReadWrite);

        qint64 pos;
        pos = file.size();
        file.seek(pos);
        file.write(content.toUtf8());
        file.close();

        file.open(QIODevice::ReadOnly);

        QByteArray msg;
        msg = file.readAll();//read all data in the file

        file.close();
        return msg;
}

void Widget::on_pic00_clicked()
{
    qDebug()<<"in the on_QQface_clicked";
    chat_face *mychat_face=new chat_face();
    qDebug()<<"on_QQface_clicked() is press";

    mychat_face->show();
    connect(mychat_face,SIGNAL(load_face(QString)),this,SLOT(loadface(QString)));
    qDebug()<<"on_QQface_clicked after";

}

void Widget::on_txtShow_textChanged()
{
    ui->txtShow->moveCursor(QTextCursor::End);
}



void Widget::sendImg()
{
    QImage img("E:\\QT\\ssssssssss\\ChatRoom-master\\3440\\e4.jpg");
    QPixmap pix = QPixmap::fromImage(img);

    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    pix.save(&buffer,"jpg");
    quint32 pix_len = (quint32)buffer.data().size();
    qDebug("image size:%d",pix_len);

    QByteArray dataArray;
    dataArray.append(buffer.data());

    quint32 write_len = socket_2->write(dataArray);//and write

    qDebug("widget write len:%d",write_len);
}

void Widget::recvImg()
{
    QByteArray pp=socket_2->readAll();
    if(!pp.isEmpty()){
    QDateTime time = QDateTime::currentDateTime();
    QString current_date = time.toString("yyyyMMddhhmm");

    QString filename = "C:\\Users\\asus\\Desktop\\"+current_date+".png";

    QFile im(filename);

    im.open(QIODevice::ReadWrite);
       QByteArray array;
       array.append((QByteArray)pp);
       qint64 pos;
       pos = im.size();
       im.seek(pos);
       im.write(array);
       im.close();



       if(!img.isNull()){

           qDebug()<<"right"<<endl;

       } else {
           ;

       }
        }

}

void Widget::showImg()
{

}

void Widget::on_pushButton_2_clicked()
{
    QByteArray name;
    name = ui->txtName->text().toLocal8Bit();
    socket->write("#RENAME "+name,100);
    socket->flush();

}

void Widget::on_pushButton_3_clicked()
{
    QByteArray person;
    QByteArray msg;
    person = ui->txtPerson->text().toLocal8Bit();
    msg = ui->txtContext->toPlainText().toLocal8Bit();
    QString cmd = QString::fromLocal8Bit("#TO "+person+" "+msg);
    socket->write(cmd.toLocal8Bit());
    ui->txtContext->clear();

}

void Widget::on_pushButton_4_clicked()
{
    socket->write("#ONLINE",10);
}

void Widget::chatSlect()
{
    if(ui->txtPerson->text().isEmpty()) ui->chatSelect->setText("群聊模式");
    else ui->chatSelect->setText("私聊模式");
}

void Widget::on_txtPerson_textEdited(const QString &arg1)
{
    if(ui->txtPerson->text().isEmpty())
    {
        ui->chatSelect->setText("群聊模式");
//

    }
    else
    {
        ui->chatSelect->setText("私聊模式(to:"+arg1+")");


    }


}

void Widget::on_txtPerson_editingFinished()
{
    ;
}

void Widget::on_quitChat_clicked()
{

    if(ui->quitChat->text()=="退出房间")
        {
            socket->write("#QUIT",10);
            ui->chatSelect->setText("你已经退出该聊天室");
            ui->quitChat->setText("重新连接");
        }
    else if(ui->quitChat->text()=="重新连接")
        {
            socket->connectToHost("47.106.185.108",5000);
            ui->quitChat->setText("退出房间");
            ui->chatSelect->setText("群聊模式");

    }
}

void Widget::loadface(QString clickedname)
{
    return;
}

void Widget::on_pushButton_6_clicked()
{
    socket->write("#GETIP",10);
}

void Widget::on_pushButton_5_clicked()
{
    socket->write("#CHECK",10);
}

void Widget::on_pushButton_7_clicked()
{
    socket->write("#HELP",10);
}
