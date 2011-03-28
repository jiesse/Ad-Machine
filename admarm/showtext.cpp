#include "showtext.h"
#include <QPainter>
#include <QTimer>
#include <QTextStream>
#include <QFile>
#include <QDebug>
ShowText::ShowText(QWidget *parent) :
    QWidget(parent)
{
    QFile file("/adm/Text/text.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream text(&file);
    QString line;
    line = text.readLine();
    qDebug() << line;
    label = new QLabel(this);
    label->resize(755, 73);
    label->setFont(QFont("文泉驿微米黑",30,30));
    m_text = line;
//    m_text = QObject::trUtf8("说书唱戏劝人方，三条大路走中央。善恶到头终有报，人间正道是沧桑。");
    update();
    QTimer *timer = new QTimer;
    timer->start(300);
    connect(timer, SIGNAL(timeout()), this, SLOT(onChange()));
}
void ShowText::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(QColor(0, 255, 0));
    p.drawRect(0, 0, 775, 73);
    p.end();
}

void ShowText::update()
{
    label->setText(m_text);
}

void ShowText::onChange()
{
    QChar ch = m_text.at(0);
    m_text.remove(0, 1);
    m_text.append(ch);
    update();
}
