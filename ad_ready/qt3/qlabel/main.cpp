
#include <QLabel>

#include <QApplication>

#include <QPushButton>

#include <QVBoxLayout>


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QWidget win;

    win.show();

    QPushButton *button = new QPushButton("quit");

    QLabel *label = new QLabel("<h2><i>hello" "<font color=red>qt</font></i></h2>");

    QVBoxLayout *layout = new QVBoxLayout(&win);

    QObject::connect(button,SIGNAL(clicked()),&app,SLOT(quit()));

    layout->addWidget(label,3);

    layout->addWidget(button,3);



    app.exec();
}
