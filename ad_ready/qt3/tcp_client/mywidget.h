#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QPushButton>
#include <QTextEdit>
#include <QKeyEvent>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
    QTcpSocket* socket;

    QTextEdit* edit1;
    QTextEdit* edit2;
    QPushButton* button;

    void keyReleaseEvent(QKeyEvent* event);

signals:

public slots:
    void slotReadyRead();
    void slotSendMessage();

};

#endif // MYWIDGET_H
