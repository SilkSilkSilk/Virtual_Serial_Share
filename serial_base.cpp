#include "serial_base.h"

Serial_base::Serial_base(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Serial_base)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);
//    QObject::connect(serial, &QSerialPort::readyRead, this, &Serial_base::Read_Data); //有数据就读回来

    ui->PortBox->clear(); //先清除
    QList < QSerialPortInfo > SerialList = QSerialPortInfo::availablePorts();
    foreach (QSerialPortInfo info,SerialList)
    {
        ui->PortBox->addItem(info.portName());
    }

    //    tab_Index==0
    ui->BaudBox->addItem(QString::number(1200));
    ui->BaudBox->addItem(QString::number(2400));
    ui->BaudBox->addItem(QString::number(4800));
    ui->BaudBox->addItem(QString::number(9600));
    ui->BaudBox->addItem(QString::number(14400));
    ui->BaudBox->addItem(QString::number(19200));
    ui->BaudBox->addItem(QString::number(38400));
    ui->BaudBox->addItem(QString::number(115200));
    ui->BaudBox->addItem(QString::number(128000));
    ui->BaudBox->addItem(QString::number(256000));
    ui->BaudBox->addItem(QString::number(500000));
    ui->BaudBox->setCurrentIndex(7); //显示波特率下拉菜单默认显示115200

    ui->BitNumBox->addItem(QString::number(5));
    ui->BitNumBox->addItem(QString::number(6));
    ui->BitNumBox->addItem(QString::number(7));
    ui->BitNumBox->addItem(QString::number(8));
    ui->BitNumBox->setCurrentIndex(3); //显示8位数据

    ui->ParityBox->addItem(QString("no parity"));
    ui->ParityBox->addItem(QString("Odd parity"));
    ui->ParityBox->addItem(QString("Even parity"));
    ui->ParityBox->setCurrentIndex(0); //显示无校验

    ui->StopBox->addItem(QString::number(1));
    ui->StopBox->addItem(QString::number(2));
    ui->StopBox->setCurrentIndex(0); //显示停止位1
}

Serial_base::~Serial_base()
{
    delete ui;
}

void Serial_base::on_flshButton_clicked()
{

}

void Serial_base::on_openButton_clicked()
{
    if (ui->openButton->text() == tr("打开串口"))
    {
        if (ui->PortBox->currentText().isEmpty())
        {
            QMessageBox msgBox;
            msgBox.setText("open serial failed!!");
            msgBox.exec();
            return;
        }
        serial->setPortName(ui->PortBox->currentText()); //设置串口名

        serial->open(QIODevice::ReadWrite); //打开串口

        serial->setBaudRate(ui->BaudBox->currentText().toInt()); //设置波特率

        switch (ui->BitNumBox->currentIndex()) //设置数据位  QSerialPort::Datax==ui->StopBox->currentText()
        {
            case 0: serial->setDataBits(QSerialPort::Data5);
                break;
            case 1: serial->setDataBits(QSerialPort::Data6);
                break;
            case 2: serial->setDataBits(QSerialPort::Data7);
                break;
            case 3: serial->setDataBits(QSerialPort::Data8);
                break;
            default: break;
        }

        switch (ui->ParityBox->currentIndex()) //设置奇偶校验
        {
            case 0: serial->setParity(QSerialPort::NoParity);
                break;
            case 1: serial->setParity(QSerialPort::OddParity);
                break;
            case 2: serial->setParity(QSerialPort::EvenParity);
                break;
            default: break;
        }

        switch (ui->StopBox->currentIndex()) //设置停止位
        {
            case 0: serial->setStopBits(QSerialPort::OneStop);
                break;
            case 1: serial->setStopBits(QSerialPort::TwoStop);
                break;
            default: break;
        }

        serial->setFlowControl(QSerialPort::NoFlowControl); //无硬件流

        ui->PortBox->setEnabled(false);
        ui->BaudBox->setEnabled(false);
        ui->BitNumBox->setEnabled(false);
        ui->ParityBox->setEnabled(false);
        ui->StopBox->setEnabled(false);
        ui->flshButton->setEnabled(false);
        ui->openButton->setText(tr("关闭串口"));
    }
    else
    {
        serial->clear();
        serial->close();

        ui->PortBox->setEnabled(true);
        ui->BaudBox->setEnabled(true);
        ui->BitNumBox->setEnabled(true);
        ui->ParityBox->setEnabled(true);
        ui->StopBox->setEnabled(true);
        ui->flshButton->setEnabled(true);
        ui->openButton->setText(tr("打开串口"));
    }
}

//void Serial_base::Read_Data()
//{
//    QByteArray buf = serial->readAll();
//}
