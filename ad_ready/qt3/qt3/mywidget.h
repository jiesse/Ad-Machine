#ifndef MYWIDGET_H
#define MYWIDGET_H

//widget
#include <QTextEdit>
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>

//network

#include <QTcpServer>
#include <QTcpSocket>


class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    QTextEdit *edit1;
    QTextEdit *edit2 ;

    //network
    QTcpServer* server;
    QTcpSocket* socket;


    void keyReleaseEvent(QKeyEvent *);

    void mouseReleaseEvent(QMouseEvent *);


signals:



public slots:

    void slotConnect();
    void slotReadReady();
    void slotSendMessage();


};

#endif // MYWIDGET_H
