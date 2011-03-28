#include "managent.h"
#include <QApplication>
#include <QDebug>
#include "testwidget.h"
#include <stdlib.h>
#include <string.h>
#include <QDir>
#include <QStringList>

testWidget* widget;

ManAgent::ManAgent(QObject *parent) :
    QObject(parent)
{
    // open udp socket

    flag = 1;
    path_dir = "/home/administrator/adm/Media/";
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(9900);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(slotUdpReadReady()));
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(slotTcpReadReady()));

    admShow = new QProcess(this);
}

void ManAgent::slotTcpReadReady()
{


     QByteArray buff;

    buff = tcpSocket->readAll();

    file.write(buff);
    qDebug()<<buff;

}

void ManAgent::slotUdpReadReady()
{
    char buf[16] = {0};
    QString filename;
    QStringList picFiles;
    QString directory;
    int i;

    QHostAddress host;
    quint16 port;
    quint64 ret = udpSocket->readDatagram(buf, sizeof(buf), &host, &port);

    int serverPort;

    switch(ret)
    {
    case 2:
        qDebug() << "slotUdpReadReady 2";
        admShow->start("/home/administrator/Adshow/Adshow");

        break;
    case 3:
        qDebug() << "slotUdpReadReady 3";
        admShow->close();
        break;   

    default:
        break;
    }
    if(ret == 4)
    {
        qDebug() << "slotUdpReadReady 4";
        directory = "/home/administrator/adm/Picture/";
        QDir dir(directory);
        dir.setFilter(QDir::Files);
        picFiles = dir.entryList();

        for(i = 0;i < picFiles.length(); i++)
        {
            qDebug()<<picFiles.at(i);
        }
        for(i = 0;i < picFiles.length(); i++)
        {
            filename = directory + picFiles.at(i);
            file.remove(filename);
        }

        directory = "/home/administrator/adm/Media/";
        QDir dir2(directory);
        dir2.setFilter(QDir::Files);
        picFiles = dir2.entryList();

        for(i = 0;i < picFiles.length(); i++)
        {
            qDebug()<<picFiles.at(i);
        }
        for(i = 0;i < picFiles.length(); i++)
        {
            filename = directory + picFiles.at(i);
            file.remove(filename);
        }

        directory = "/home/administrator/adm/Text/";
        QDir dir3(directory);
        dir3.setFilter(QDir::Files);
        picFiles = dir3.entryList();

        for(i = 0;i < picFiles.length(); i++)
        {
            qDebug()<<picFiles.at(i);
        }
        for(i = 0;i < picFiles.length(); i++)
        {
            filename = directory + picFiles.at(i);
            file.remove(filename);
        }

        directory = "/home/administrator/adm/Other/";
        QDir dir4(directory);
        dir4.setFilter(QDir::Files);
        picFiles = dir4.entryList();

        for(i = 0;i < picFiles.length(); i++)
        {
            qDebug()<<picFiles.at(i);
        }
        for(i = 0;i < picFiles.length(); i++)
        {
            filename = directory + picFiles.at(i);
            file.remove(filename);
        }
        file.setFileName("/home/administrator/adm/readme");
        file.open(QFile::WriteOnly);

        serverPort = atoi(buf);

        tcpSocket->connectToHost(host, serverPort);
    }
    if(ret > 4)
    {

        if(!strcmp(buf,"all_end"))
        {
           qDebug()<<"file receive success";
            tcpSocket->write("success");
        }
        if(!strcmp(buf,"directory"))
        {
            flag++;
            qDebug()<<"new directory"<<endl;
            qDebug()<<"new directory"<<endl;
            switch(flag)
            {
            case 2: path_dir = "/home/administrator/adm/Picture/";
                    break;
            case 3: path_dir = "/home/administrator/adm/Text/";
                    break;
            case 4: path_dir = "/home/administrator/adm/Other/";
                    break;
            default:
                    break;
            }
        }
        else
        {
            path = path_dir;
            path.append(buf);
        }
        qDebug()<<buf;
        qDebug() << "slotUdpReadReady > 4";
        file.close();
        file.setFileName(path);
        file.open(QFile::WriteOnly);

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
