#include "listwidget.h"

ListWidget::ListWidget(QWidget *parent) :
    QWidget(parent)
{
    point.setY(10);

    for(int i = 0; i < 20; i++)
    {
        ip_port_array[i] = new list_ip_port(this);
        ip_port_array[i]->move(point);
        point.setY(point.y() + 30 + 10);
    }

    this->setFixedSize(280, point.y());
}

void ListWidget::MouseEvent(QEvent *event, qint16 xPress, qint16 yPress)
{
    //qDebug() << "ListWidget::MouseEvent" << event->type() << " xPress = " << xPress << " yPress = " << yPress;
    int index = 0;
    for(; index < 20; index++)
    {
        if (ip_port_array[index]->geometry().contains(xPress, yPress))
        {
            break;
        }
    }

    switch (event->type())
    {
        case QEvent::MouseButtonPress:
            if(index >= 20)     //不在控件上
                return;
            ip_port_array[index]->ip_port_Press();
            break;

        case QEvent::MouseButtonRelease:
            if(index >= 20)
                return;
            ip_port_array[index]->ip_port_Release();
            break;

        case QEvent::MouseMove:
            if(index >= 20)
                return;

            if(last_move >= 0 && last_move < 20 && last_move != index)
            {
                ip_port_array[last_move]->ip_port_Move(false);      //消去上一次的move
            }
            ip_port_array[index]->ip_port_Move(true);
            last_move = index;
            break;

        case QEvent::MouseButtonDblClick:
            if(index >= 20)
                return;
//            ip_port_array[index]->ip_port_Release();
            break;

        default:
            break;
    }
}
