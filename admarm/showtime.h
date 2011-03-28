#ifndef SHOWTIME_H
#define SHOWTIME_H

#include <QWidget>

class ShowTime : public QWidget
{
    Q_OBJECT
public:
    explicit ShowTime(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
signals:

public slots:

};

#endif // SHOWTIME_H
