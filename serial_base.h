#ifndef SERIAL_BASE_H
#define SERIAL_BASE_H

#include "ui_serial_base.h"

#include <QWidget>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>

namespace Ui
{
	class Serial_base;
}

class Serial_base : public QWidget
{
	Q_OBJECT

public:
	explicit Serial_base(QWidget* parent = 0);
	~Serial_base();

	Ui::Serial_base* ui;
	QSerialPort* serial;

private slots:
	void on_flshButton_clicked();

	void on_openButton_clicked();

	//    void Read_Data();

private:
};

#endif // SERIAL_BASE_H
