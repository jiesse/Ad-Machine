#ifndef SHOWVIDEL_H
#define SHOWVIDEL_H

#include <QWidget>
#include <QProcess>

class Render: public QWidget
{
    Q_OBJECT
public:
    explicit Render(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);

};

class ShowVideo : public QWidget
{
    Q_OBJECT
public:
    explicit ShowVideo(QWidget *parent = 0);
    virtual ~ShowVideo();

    QProcess *mplayerProcess;
    Render *render;
signals:

public slots:

};

#endif // SHOWVIDEL_H
