#ifndef SHOWPIC_H
#define SHOWPIC_H

#include <QWidget>
#include <QLabel>
#include <QMovie>

class ShowPic : public QWidget
{
    Q_OBJECT
public:
    explicit ShowPic(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    QLabel *label;
    QMovie *movie;
    QStringList picFiles;
signals:

public slots:
    void slotChangePic(void);

};

#endif // SHOWPIC_H
