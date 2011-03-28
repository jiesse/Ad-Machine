

#include <QApplication>

//#include <QtGui/QTextBrowser>

#include "mywidget.h"

int main(int argc, char * argv[])
{


     QApplication app(argc,argv);

     MyWidget win ;


    // QTextBrowser textwin;

    // textwin.show();

     win.show();

     return app.exec();

}
