#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMovie>
#include "digitflip.h"
class ShowVideo;
class ShowText;
class ShowPic;
class ShowTime;
class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ShowVideo *sv;
    ShowText *stext;
    ShowPic *sp;
    ShowTime *st;
    QLabel *label;
    QMovie *movie;
    DigiFlip *time;
signals:

public slots:

};

#endif // WIDGET_H
