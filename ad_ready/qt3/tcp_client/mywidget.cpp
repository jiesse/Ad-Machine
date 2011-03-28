#include "mywidget.h"
#include <QHostAddress>
#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress("10.1.14.39"), 8900);

    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));

    edit1 = new QTextEdit();
    edit2 = new QTextEdit();

    button = new QPushButton("send");

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(edit1);
    layout->addWidget(edit2);
    layout->addWidget(button);
    setLayout(layout);

    connect(button, SIGNAL(clicked()), this, SLOT(slotSendMessage()));
}

void MyWidget::keyReleaseEvent(QKeyEvent* event)
{


    if(event->key()==Qt::Key_Return)
    {

       // cout << "push enter"<< endl;

      //  QString str = edit2->toPlainText();

       // str = str.left(str.length()-1);

       // edit1->append(str);

      //  edit2->clear();

        QString str = edit2->toPlainText();
        str = "jiesse:  "+ str;
        str = str.left(str.length()-1);
        //str.insert(0,QString("jiesse: "));
        edit1->append(str);
        edit2->clear();
        socket->write(str.toAscii());
    }

}

void MyWidget::slotSendMessage()
{
   // QString str = edit->toPlainText();
   // edit->clear();
   //socket->write(str.toAscii())}
}
void MyWidget::slotReadyRead()
{
    QByteArray ba = socket->read(1024);

    edit1->append(ba);
    //edit1->append('\n');
    //qDebug() << ba;
}

#include <QApplication>
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWidget win;
    win.show();

    return app.exec();
}
