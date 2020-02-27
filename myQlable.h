#ifndef MYQLABLE_H
#define MYQLABLE_H
#include <QLabel>
#include <QWidget>
#include <QDebug>

class myQLabel:public QLabel
{
    Q_OBJECT
public:
    myQLabel(QWidget *parent=0);
  //  ~myQLabel();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent *ev);
};

#endif // MYQLABLE_H
