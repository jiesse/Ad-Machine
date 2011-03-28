#include "widget.h"
#include "showvidel.h"
#include "showpic.h"
#include "digitflip.h"
#include "showtext.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    resize(800, 480);
    label = new QLabel(this);
    label->resize(800, 480);
    label->setGeometry(0, 0, size().width(), size().height());
    label->setScaledContents(true);
    label->setPixmap(QPixmap("/adm/blue.jpg"));



    stext = new ShowText(this);
    stext->show();


    sp = new ShowPic(this);
    sp->show();



    time = new DigiFlip(this);
    time->show();
    time->resize(195, 80);

    sv = new ShowVideo(this);



    QVBoxLayout* vLayout = new QVBoxLayout(this);
    QHBoxLayout* hLayout = new QHBoxLayout();

    vLayout->addLayout(hLayout, 5);
    vLayout->addWidget(stext, 1);

    vLayout = new QVBoxLayout();
    hLayout->addWidget(sv, 54);
    hLayout->addLayout(vLayout, 19);

    vLayout->addWidget(time, 9);
    vLayout->addWidget(sp, 25);

    sv->show();


}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget mainwindow;



    mainwindow.show();
    return app.exec();
}
