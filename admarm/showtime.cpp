#include "showtime.h"
#include <QPainter>
ShowTime::ShowTime(QWidget *parent) :
    QWidget(parent)
{
}
void ShowTime::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(QColor(255, 0 , 0));
    p.drawRect(0, 0, 195, 97);
    p.end();
}
