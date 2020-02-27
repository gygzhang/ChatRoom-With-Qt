#include "chat_face.h"
#include "ui_chat_face.h"
#include <QHBoxLayout>
#include"myQlable.h"
chat_face::chat_face(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat_face)
{
    ui->setupUi(this);

        QMovie *pm=new QMovie("./imqface/1.gif");

        connect(ui->label_33,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_34,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_35,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_36,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_37,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_38,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_39,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));

        connect(ui->label_40,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_41,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_42,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_43,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_44,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_45,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_46,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_47,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_48,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_49,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));

        connect(ui->label_50,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_51,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_52,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_53,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_54,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_55,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_56,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_57,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_58,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_59,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));

        connect(ui->label_60,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_61,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_62,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_63,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_64,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_65,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_66,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_67,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_68,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_69,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));

        connect(ui->label_70,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_71,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_72,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_73,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_74,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_75,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_76,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_77,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_78,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
        connect(ui->label_79,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));

        connect(ui->label_80,SIGNAL(clicked()),this,SLOT(myqlable_clicked()));
}

void chat_face::myqlable_clicked()
{
    qDebug()<<"myqlable is being clicked!!!";
    myQLabel *sendname=qobject_cast<myQLabel*>(sender());
    QString beclicked_name=sendname->objectName();
    qDebug()<<beclicked_name;
    emit load_face(beclicked_name);
}

chat_face::~chat_face()
{
    delete ui;
}


