#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QEvent>
#include <QKeyEvent>
#include <QTextCursor>
#include <QTimer>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    QString textToBeSend=nullptr;

protected:
    void keyPressEvent(QKeyEvent *e);
public slots:

    void sendMesage();
    void readMessage();


    void CloseChat();
    QByteArray FileWrite(QString content,qint16 a);

    void sendImg();

    void chatSlect();
private slots:
    void on_txtShow_textChanged();

    void on_pic00_clicked();

    void recvImg();
    void showImg();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_txtPerson_textEdited(const QString &arg1);

    void on_txtPerson_editingFinished();

    void on_quitChat_clicked();

    void loadface(QString clickedname);

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket * socket;

    QString ver = "1.0";

    QTcpSocket * socket_2;
};

#endif // WIDGET_H
