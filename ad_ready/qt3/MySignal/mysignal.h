#ifndef MYSIGNAL_H
#define MYSIGNAL_H

#include <QObject>

#include <QDebug>

class mySignal : public QObject
{
    Q_OBJECT
public:
    explicit mySignal(QObject *parent = 0);

    void sendSignal()
    {
        emit my_sig();
    }

signals:

    void my_sig();


public slots:

    void my_slot()
    {
        qDebug() << "slot call";
    }

};

#endif // MYSIGNAL_H
