#include "widget.h"
#include "login.h"

#include <QApplication>
#include <QTextCodec>
#include<QString>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //qt    utf8    server  gbk
    //QTextCodec::setCodecForLocale()
    // QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    //QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    // QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::codecForName("GBK");
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

//    start p;
//    p.show();
    //QObject::connect()

    Login login;
    if (login.exec()==QDialog::Accepted)
    {
        Widget w;
        //user.mainWindow=&w;

        w.show();
        return a.exec();
    }
    else return 0;


    //Widget ww;
    //ww.show();
    //QObject::)

    //return a.exec();
}
