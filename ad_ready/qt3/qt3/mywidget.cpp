#include "mywidget.h"
#include<QVBoxLayout>
#include <iostream>
#include <QDebug>

using namespace std;

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
//network
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any,8900);

    connect(server,SIGNAL(newConnect()),this,SLOT(slotConnect()));


//widget
    edit1 = new QTextEdit();
    edit2 = new QTextEdit();

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(edit1,5);
    layout->addWidget(edit2,1);


}
    void MyWidget::keyReleaseEvent(QKeyEvent* event)
    {
       // if(event->key()!=Qt::Key_Return)
       //     cout<<"other key"<< endl;

        if(event->key()==Qt::Key_Return)
        {

           // cout << "push enter"<< endl;

          //  QString str = edit2->toPlainText();

           // str = str.left(str.length()-1);

           // edit1->append(str);

          //  edit2->clear();

            QString str = edit2->toPlainText();
            edit2->clear();
            socket->write(str.toAscii());
        }


    }

    void MyWidget::slotSendMessage()
    {
        //QString str = edit->toPlainText();
        //edit->clear();
        //socket->write(str.toAscii());
    }

    void MyWidget::slotConnect()
    {
        socket = server->nextPendingConnection();
        connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadReady()));

        qDebug() << "connected";
    }

    void MyWidget::slotReadReady()
    {
        QByteArray ba = socket->read(1024);
        qDebug() << ba;
    }

#if 0
    void MyWidget::mouseReleaseEvent(QMouseEvent *event)
    {
       if(event->button()==Qt::LeftButton)
        {

            //qDebug()<<"release left button"<< endl;
            cout<<"release left button"<< endl;
        }


    }
#endif

