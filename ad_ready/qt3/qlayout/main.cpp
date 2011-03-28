#include <QApplication>

#include <QSpinBox>

#include <QSlider>

#include <QVBoxLayout>

int  main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QWidget *window = new QWidget;

    window->setWindowTitle("ENTER YOUR AGE");

    QSpinBox *spinbox = new QSpinBox;

    QSlider *slider = new QSlider(Qt::Horizontal);

    spinbox->setRange(0,1300);

    slider->setRange (0,1300);

    QObject::connect(spinbox,SIGNAL(valueChanged(int)),
                     slider,SLOT(setValue(int)));

    QObject::connect (slider,SIGNAL(valueChanged(int))
                      ,spinbox,SLOT(setValue(int)));

    spinbox->setValue(35);

    QVBoxLayout *layout = new QVBoxLayout;

    layout ->addWidget(spinbox,2);

    layout ->addWidget(slider,3);

    window->setLayout(layout);

    window->show();

    return app.exec();


}
