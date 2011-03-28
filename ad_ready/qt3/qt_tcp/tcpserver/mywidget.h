#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QPushButton>
#include <QTextEdit>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    QTcpServer* server;
    QTcpSocket* socket;

    QPushButton* button;
    QTextEdit* edit;

signals:

public slots:
    void slotConnect();
    void slotReadReady();

    void slotSendMessage();

};

#endif // MYWIDGET_H
