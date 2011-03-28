#include <QWidget>
#include <QUdpSocket>
#include <QPushButton>



class MyPushButton : public QPushButton
{
	Q_OBJECT
public:
	MyPushButton(QWidget* parent = 0);

	QUdpSocket* socket;

public slots:
	void SendData();
};
