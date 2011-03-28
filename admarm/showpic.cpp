#include "showpic.h"
#include <QPainter>
#include <QDir>
#include <QTimer>
#include <QDebug>

void ShowPic::resizeEvent(QResizeEvent *)
{
    label->setGeometry(0, 0, size().width(), size().height());
    label->setScaledContents(true);
}

ShowPic::ShowPic(QWidget *parent) :
    QWidget(parent)
{
    label = new QLabel(this);

    QDir dir("/adm/PicFile");
    dir.setFilter(QDir::Files);
    picFiles = dir.entryList();
//    movie = new QMovie("/adm/PicFile/1.gif");
//    label->setMovie(movie);
//    movie->start();
#if 1
    slotChangePic();
    QTimer* timer;
    timer = new QTimer();
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotChangePic()));
#endif
}

void ShowPic::slotChangePic()
{
#if 1
    QString strPath = "/adm/PicFile/";
    strPath += picFiles.at(0);
    label->setPixmap(strPath);
    picFiles.append(picFiles.at(0));
    picFiles.removeFirst();
#endif
}

void ShowPic::paintEvent(QPaintEvent *)
{

    QPainter p(this);
    p.setBrush(QBrush(QColor(255, 0 , 0)));
    p.drawRect(QRect(QPoint(0, 0), this->size()));
    p.end();

}
