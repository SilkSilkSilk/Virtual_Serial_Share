#ifndef HOST_SEND_H
#define HOST_SEND_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QTcpServer>
#include <QTcpSocket>

#include "serial_base.h"

namespace Ui
{
	class Host_Send;
}

class Host_Send : public QWidget
{
	Q_OBJECT

public:
	explicit Host_Send(QWidget* parent = 0);
	~Host_Send();

	Serial_base* serial_ch340;
	Serial_base* serial_virtual;

private slots:
	void Read_Data_ch340();
	void Read_Data_virtual();

	void on_tcp_open_clicked();

	void on_tcp_close_clicked();

	void newclientconnect();

	void TCP_clien_read();

private:
	Ui::Host_Send* ui;
	QTcpServer* TCP_server;
	QTcpSocket* TCP_clien;
	QHostAddress addr_client;
	QByteArray buf;
};

#endif // HOST_SEND_H
