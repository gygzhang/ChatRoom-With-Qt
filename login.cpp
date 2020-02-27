#include "Login.h"
#include "ui_Login.h"
#include "widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QString>


extern QString _name;

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    //hide question mark on window
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    ui->setupUi(this);

    //set two buttons
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QString::fromLocal8Bit("??????????"));
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(QString::fromLocal8Bit("???"));
    ui->loginName->setFocus();
    //bind signal and slot function
    connect(ui->buttonBox->button(QDialogButtonBox::Ok),SIGNAL(clicked()),this,SLOT(on_loginbutton_clicked()));
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginbutton_clicked()
{
    //acquire user name
    QString QName=ui->loginName->text();
    std::string name=QName.toStdString();

    //name validity check
    if (name.length()!=0&&name.find(' ') == std::string::npos&&name.length() <= 19)
    {
        accept();
    }

    //non-empty check
    else if (name.length()==0) QMessageBox::warning(this,
                                               QString::fromLocal8Bit("???"),
                                               QString::fromLocal8Bit("UID ??????"),
                                               QMessageBox::Ok);

    _name = QName;
}
