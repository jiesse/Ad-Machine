
#include <QApplication>

#include "mysignal.h"

mySignal::mySignal(QObject *parent) :
    QObject(parent)
{
}


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    mySignal obj1;

    mySignal obj2;

    QObject::connect(&obj1,SIGNAL(my_sig()),&obj2,SLOT(my_slot()));

    obj1.sendSignal();

    return app.exec();

}
