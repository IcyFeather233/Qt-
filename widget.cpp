#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//clear the frame
    //阴影边框效果
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();

    shadow->setBlurRadius(20);//阴影边角圆滑程度
    shadow->setColor(Qt::black);
    shadow->setOffset(0);//偏移

    ui->ShadowWidget->setGraphicsEffect(shadow);
    this->setAttribute(Qt::WA_TranslucentBackground);//父窗口透明
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    QPoint y = event->globalPos();
    QPoint x = y - this->z;
    this->move(x);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    QPoint y = event->globalPos();
    QPoint x = this->geometry().topLeft();
    this->z = y - x;
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    this->z = QPoint();//把Z清空释放
}
