
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QtNetwork/QTcpSocket>
#include <QString>
#include <string.h>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QStringList picFiles;
    QString directory;
    QString filename;
    int i;
    QFile file;




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



      //filename = path + picFiles.at(0);


    //file.remove(filename);
    //qDebug()<<filename;
    //file.remove(path+picFiles.at(1));

    //file.remove(path+picFiles.at(2));


    // QString kk = "yaomoon";
    // QString mm = kk;
     //qDebug()<<kk;


    return app.exec();
}
