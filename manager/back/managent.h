#ifndef MANAGENT_H
#define MANAGENT_H

#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QTcpSocket>
#include <QProcess>
#include <QFile>


class ManAgent : public QObject
{
    Q_OBJECT
public:
    explicit ManAgent(QObject *parent = 0);

    QUdpSocket* udpSocket;
    QProcess* admShow;
    QTcpSocket* tcpSocket;
    QString path;
    QString path_dir;
    int flag;
    QFile file;

signals:

public slots:
    void slotUdpReadReady();
    void slotTcpReadReady();

};

#endif // MANAGENT_H
