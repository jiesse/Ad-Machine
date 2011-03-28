#include "managent.h"
#include <QApplication>
#include <QDebug>
#include <QDir>
#include "testwidget.h"
#include <QTime>

testWidget* widget;

QString strHomePath;


ManAgent::ManAgent(QObject *parent) :
    QObject(parent)
{
    filelen = 0;
    strHomePath = getenv("HOME");
   // QTime time;
    strHomePath += "/";
    strHomePath += QTime::currentTime().toString("hhmmss");
    qDebug() << strHomePath;
    // open udp socket
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(9988);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(slotUdpReadReady()));
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(slotTcpReadReady()));

    admShow = new QProcess(this);
}


void ManAgent::slotTcpReadReady()
{
    int readlen;
    while(tcpSocket->bytesAvailable() > 0)
    {
        if(filelen == 0)
        {
            readlen = 0;
            while(readlen != 4)
            {
                readlen += tcpSocket->read(buf+readlen, 4-readlen);
            }
            filenamelen = *(int*)buf;
            if((unsigned int)filenamelen == 0xffffffff)
            {
                tcpSocket->close();
                return;
            }

            readlen = 0;
            while(readlen != filenamelen)
            {
                readlen += tcpSocket->read(buf+readlen, filenamelen-readlen);
            }

            *(buf+filenamelen) = 0;
            strFileName = strHomePath;
            strFileName += buf;

            QDir dir;
            dir.mkpath(strFileName);
            dir.rmdir(strFileName);

            file = new QFile(strFileName);
            file->open(QFile::ReadWrite);
            qDebug() << strFileName << "begin";

            readlen = 0;
            while(readlen != 4)
            {
                readlen += tcpSocket->read(buf+readlen, 4-readlen);
            }
            filelen = *(int*)buf;
        }
        else
        {
            if((unsigned int)filelen>sizeof(buf))
                readlen = tcpSocket->read(buf, sizeof(buf));
            else
                readlen = tcpSocket->read(buf, filelen);
            file->write(buf, readlen);
            filelen -= readlen;

            if(filelen == 0)
            {
                qDebug() << strFileName << "end";
                file->close();
                delete file;
            }
        }
    }
}

void ManAgent::slotUdpReadReady()
{
    char buf[16];
    QHostAddress host;
    quint16 port;
    quint64 ret = udpSocket->readDatagram(buf, sizeof(buf), &host, &port);

    int serverPort;

    switch(ret)
    {
    case 2:
        qDebug() << "slotUdpReadReady 2";
        admShow->start("./admShow");

        break;
    case 3:
        qDebug() << "slotUdpReadReady 3";
        admShow->close();
        break;
    case 4:
        qDebug() << "slotUdpReadReady 4";
        serverPort = *(int*)buf;
        qDebug() << serverPort;
        tcpSocket->connectToHost(host, serverPort);
        break;
    default:
        break;
    }
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    widget = new testWidget();
    widget->show();
    new ManAgent();
    app.exec();
}
