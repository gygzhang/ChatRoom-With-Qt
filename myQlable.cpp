#include "myQlable.h"

myQLabel::myQLabel(QWidget *parent):QLabel(parent)
{
    ;
}

void myQLabel::mousePressEvent(QMouseEvent *ev)
{
    emit  clicked();
}
