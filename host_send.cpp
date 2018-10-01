#include "host_send.h"
#include "ui_host_send.h"

Host_Send::Host_Send(QWidget* parent) :
	QWidget(parent),
	TCP_server(nullptr),
	TCP_clien(nullptr),
	ui(new Ui::Host_Send)
{
	ui->setupUi(this);

	serial_ch340 = new Serial_base(this);
	serial_ch340->ui->groupBox->setTitle(QString("ch340-真实串口"));
	serial_ch340->move(10, 20);
	serial_ch340->show();

	QObject::connect(serial_ch340->serial, &QSerialPort::readyRead, this, &Host_Send::Read_Data_ch340);

	serial_virtual = new Serial_base(this);
	serial_virtual->ui->groupBox->setTitle(QString("com-虚拟串口"));
	serial_virtual->move(210, 20);
	serial_virtual->show();

	QObject::connect(serial_virtual->serial, &QSerialPort::readyRead, this, &Host_Send::Read_Data_virtual);

	ui->groupBox->setTitle(QString("网络串口"));
	ui->tcp_close->setEnabled(false);
	ui->tcp_open->setEnabled(true);
}

Host_Send::~Host_Send()
{
	TCP_server->deleteLater();
	TCP_clien->deleteLater();
	delete ui;
}

void Host_Send::Read_Data_ch340()
{
	qDebug() << "Read_Data_ch340";
}

void Host_Send::Read_Data_virtual()
{
	qDebug() << "Read_Data_virtual";
}

void Host_Send::on_tcp_open_clicked()
{
	if (TCP_server == nullptr)
	{
		qDebug() << "TCP_server == nullptr";
		TCP_server = new QTcpServer(this);

		if (!TCP_server->listen(QHostAddress::LocalHost, 50000))
		{
			qDebug() << TCP_server->errorString();
			TCP_server->close();
		}

		connect(TCP_server, &QTcpServer::newConnection, this, &Host_Send::newclientconnect);
	}
	ui->tcp_open->setEnabled(false);
	ui->tcp_close->setEnabled(true);
}

void Host_Send::on_tcp_close_clicked()
{
	if (TCP_server != nullptr)
	{
		TCP_server->deleteLater();
		TCP_server = nullptr;
		if (TCP_clien != nullptr)
		{
			TCP_clien->deleteLater();
			TCP_clien = nullptr;
		}
	}
	ui->textBrowser_ip->setText("");
	ui->textBrowser_port->setText("");

	ui->tcp_close->setEnabled(false);
	ui->tcp_open->setEnabled(true);
}

void Host_Send::newclientconnect()
{
	if (TCP_clien != nullptr)
	{
		delete TCP_clien;
	}
	TCP_clien = this->TCP_server->nextPendingConnection();
	ui->textBrowser_ip->setText(TCP_clien->peerName());
	ui->textBrowser_port->setText(QString::number(TCP_clien->peerPort()));
	connect(TCP_clien, &QTcpSocket::readyRead, this, &Host_Send::TCP_clien_read);
	qDebug() << "have a new clien connect!";
}

void Host_Send::TCP_clien_read()
{
	buf = TCP_clien->readAll();

	//    if (strncmp(buf.data(), REQUEST, sizeof(REQUEST)) == 0)
	//    {
	//        QByteArray data(RESPONSE);
	//        recv_clien->write(data);
	//        qDebug() << "RESPONSE to client";
	//        flag_recv = 1;
	//    }
}
