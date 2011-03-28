#include "showvidel.h"
#include <QPainter>
#include <QDebug>

Render::Render(QWidget *parent):
        QWidget(parent)
{}

void Render::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setBrush(QBrush(QColor(255, 0 , 0)));
    p.drawRect(QRect(QPoint(0, 0), this->size()));
    p.end();
}
ShowVideo::ShowVideo(QWidget *parent) :
    QWidget(parent)
{
    QString strPath = "/adm/VideoFiles/";
    this->mplayerProcess = new QProcess(this);
    render = new Render(this);
    
    render->move(0, 0);
    render->resize(543, 355);
    QStringList args;
    args << "-slave";
    args << "-quiet";
//    args << "-autosync" << "0";
//    args << "-framedrop";
    args << "-wid" << QString::number(render->winId());
//    args << "-fs";
    args << strPath + "dw.flv";
    qDebug() << strPath;
    qDebug() << args;
    this->mplayerProcess->start("/usr/bin/mplayer", args);
}

ShowVideo::~ShowVideo()
{
    this->mplayerProcess->close();
}
