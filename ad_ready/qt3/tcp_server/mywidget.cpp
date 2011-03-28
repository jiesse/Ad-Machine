#include "mywidget.h"
#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 8900);

    connect(server, SIGNAL(newConnection()), this, SLOT(slotConnect()));

    edit = new QTextEdit();
    button = new QPushButton();

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(edit);
    layout->addWidget(button);

    setLayout(layout);

    connect(button, SIGNAL(clicked()), this, SLOT(slotSendMessage()));

}

void MyWidget::slotSendMessage()
{
    QString str = edit->toPlainText();
    edit->clear();
    socket->write(str.toAscii());
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


#include <QApplication>
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWidget win;
    win.show();

    return app.exec();
}
