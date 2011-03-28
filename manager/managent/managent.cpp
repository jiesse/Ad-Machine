#include "managent.h"
#include <QApplication>
#include <QDebug>
#include "testwidget.h"
#include <stdlib.h>
#include <string.h>
#include <QDir>
#include <QStringList>

#define PATH_PIC  "/home/administrator/adm/Picture/"
#define PATH_MEDIA "/home/administrator/adm/Media/"
#define PATH_TEXT  "/home/administrator/adm/Text/"
#define PATH_OTHER "/home/administrator/adm/Other/"

#define ADSHOW "/home/administrator/Adshow/Adshow"

testWidget* widget;

ManAgent::ManAgent(QObject *parent) :
    QObject(parent)
{
    // open udp socket

    flag = 0;
    //path_dir = "/home/administrator/adm/Media/";
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(8000);
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
    //qDebug()<<buff;

}

int ManAgent::slotUdpReadReady()
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
        if(!strcmp(buf,"kk"))
        admShow->start(ADSHOW);

        break;
    case 3:
        qDebug() << "slotUdpReadReady 3";
        if(!strcmp(buf,"kkk"))
        admShow->close();
        break;   

    default:
        break;
    }
    if(ret == 4)
    {
        qDebug() << "slotUdpReadReady 4";
        directory = PATH_PIC;
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

        directory = PATH_MEDIA;
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

        directory = PATH_TEXT;
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

        directory = PATH_OTHER;
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
       // file.setFileName("/home/administrator/adm/readme");
        file.setFileName("readme");
        file.open(QFile::WriteOnly);

        serverPort = atoi(buf);

        tcpSocket->connectToHost(host, serverPort);
    }
    if(ret > 4)
    {

        if(!strcmp(buf,"all_end"))
        {
            QString repath;
           qDebug()<<"file receive success";
            tcpSocket->write("success");
            file.close();
            repath = PATH_PIC;
            repath += "the_end";
            file.remove(repath);
            repath = PATH_MEDIA;
            repath += "the_end";
            file.remove(repath);
            repath = PATH_TEXT;
            repath += "the_end";
            file.remove(repath);
            repath = PATH_OTHER;
            repath += "the_end";
            file.remove(repath);
            return 0;

           // file.remove(PATH_PIC);
            //file.remove(PATH_OTHER);
           // file.remove(PATH_MEDIA);
        }
        else if(!strcmp(buf,"directory"))
        {
            flag++;
            if(flag == 5)
            {
                flag = 1;
            }
            qDebug()<<"new directory"<<endl;
            qDebug()<<"new directory"<<endl;
            switch(flag)
            {
            case 1: path_dir = PATH_MEDIA;
                    break;
            case 2: path_dir = PATH_PIC;
                    break;
            case 3: path_dir =PATH_TEXT;
                    break;
            case 4: path_dir =PATH_OTHER;
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
    return 0;
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    widget = new testWidget();
    widget->show();
    new ManAgent();
    app.exec();
}
