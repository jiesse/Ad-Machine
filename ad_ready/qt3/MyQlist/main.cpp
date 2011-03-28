
#include <QList>
#include <QDebug>

#include <QFile>

#include <QDir>

int main(int argc ,char *argv[])
{

#if 0
    QList<int> list;

    QList<int>::Iterator it;

    list.append(10);
    list.append(39);
    list.append(90);

    for(it = list.begin();it !=list.end(); ++it )
    {
       qDebug() << *it;
    }

#endif
#if 0
    QFile file("/home/jiesse/xxx");
    file.open(QFile::ReadOnly);
    QByteArray ba = file.readAll();

    qDebug() << ba;
    file.close();

#endif

#if 1

    QDir dir(".");

    QFileInfoList list =dir.entryInfoList();

    QList<QFileInfo>::Iterator it;

    QFileInfo fi;

    for(it =list.begin(); it != list.end(); it++)
    {
        fi =*it;
        qDebug() << fi.filePath();
    }
#endif

}
