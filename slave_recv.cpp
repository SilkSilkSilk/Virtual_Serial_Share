#include "slave_recv.h"
#include "ui_slave_recv.h"

Slave_recv::Slave_recv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Slave_recv)
{
    ui->setupUi(this);


    serial_port = new Serial_base(this);
    serial_port->ui->groupBox->setTitle(QString("com-虚拟串口"));
    serial_port->move(10, 20);
    serial_port->show();

    QObject::connect(serial_port->serial, &QSerialPort::readyRead, this, &Slave_recv::Serial_Read_Data);

    ui->label->setText(QString("网络配置"));

    list_widget = new ListWidget(this);
    ui->scrollArea->setWidget(list_widget);

    ui->touch_labe->setMouseTracking(true);
    ui->touch_labe->installEventFilter(this);
}

Slave_recv::~Slave_recv()
{
    delete ui;
}

void Slave_recv::Serial_Read_Data()
{

}

void Slave_recv::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Slave_recv::mousePressEvent";
}

bool Slave_recv::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->touch_labe)
    {
        if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::MouseMove || event->type() == QEvent::MouseButtonDblClick)
        {
            QPoint pos = mapFromGlobal(QCursor::pos());
            pos = ui->touch_labe->mapFromParent(pos);
            QScrollBar *scor = ui->scrollArea->verticalScrollBar();
            list_widget->MouseEvent(event, pos.x(), pos.y() + scor->value());
            //qDebug() << "in Slave_recv::eventFilter" << event->type();

            return true;        //拦截此事件的继续传递
        }
        else if(event->type() == QEvent::Wheel)
        {
            ui->scrollArea->wheelEvent(reinterpret_cast<QWheelEvent*>(event));
            return true;
        }
        else
        {
            return ui->scrollArea->eventFilter(obj, event);
        }
    }
    else      //不影响其他的控件的事件
    {
        // pass the event on to the parent class
        qDebug() << "obj = " << obj->objectName();
        return QWidget::eventFilter(obj, event);
    }
}

