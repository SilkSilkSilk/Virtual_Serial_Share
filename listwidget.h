#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QDebug>

#include "list_ip_port.h"

class ListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = nullptr);

    void MouseEvent(QEvent *event, qint16 xPress, qint16 yPress);

public:
    QPoint point;

signals:

public slots:

private:
    #define MAX_IP_PORT 50
    list_ip_port * ip_port_array[MAX_IP_PORT];
    qint8 last_move = -1;

protected:
//    void mousePressEvent(QMouseEvent *event);
};

#endif // LISTWIDGET_H
