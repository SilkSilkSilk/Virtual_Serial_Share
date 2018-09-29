#ifndef SLAVE_RECV_H
#define SLAVE_RECV_H

#include <QWidget>
#include <QDebug>
#include <QScrollBar>
#include <QScrollArea>

#include "serial_base.h"
#include "listwidget.h"
//#include "my_scrollarea.h"

namespace Ui {
class Slave_recv;
}

class Slave_recv : public QWidget
{
    Q_OBJECT

public:
    explicit Slave_recv(QWidget *parent = 0);
    ~Slave_recv();

    Serial_base *serial_port;

private slots:
    void Serial_Read_Data();

private:
    Ui::Slave_recv *ui;
    ListWidget * list_widget;

protected:
    void mousePressEvent(QMouseEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // SLAVE_RECV_H
