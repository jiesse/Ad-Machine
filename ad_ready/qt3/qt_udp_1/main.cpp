
#include <QApplication>

#include "main.h"

MyPushButton::MyPushButton(QWidget* parent)
		: QPushButton(parent)
{
	socket = new QUdpSocket(this);
	connect(this, SIGNAL(clicked()), this, SLOT(SendData()));
}

void MyPushButton::SendData()
{
	socket->writeDatagram("senddata", 9, QHostAddress("127.0.0.1"), 8900);
}

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	
	MyPushButton button;
	button.show();
	return app.exec();
}
