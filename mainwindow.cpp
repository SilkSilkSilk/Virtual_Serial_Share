#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	host_send(nullptr),
	slave_recv(nullptr),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	setFixedSize(this->width(), this->height()); //固定大小
}

MainWindow::~MainWindow()
{
	delete host_send , slave_recv;
	delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
	
}

bool MainWindow::event(QEvent *e)
{
	if (e->type() == QEvent::KeyPress || e->type() == QEvent::KeyRelease)
	{
		if (!slave_recv->isHidden())
		{
			slave_recv->eventFilter(static_cast<QObject*>(slave_recv), e);			//因为键盘事件传输不到slave_recv界面，所以手动传输
		}
	} 
	return QMainWindow::event(e);
}

void MainWindow::on_chooseButton_clicked()
{
	if (ui->host_send->isChecked())
	{
		if (slave_recv != nullptr)
		{
			slave_recv->hide();
		}

		if (host_send == nullptr)
		{
			host_send = new Host_Send(this);

			host_send->move(QPoint(0, 0));
			host_send->raise();
			host_send->show();
		}
		else
		{
			if (host_send->isHidden())
			{
				host_send->raise();
				host_send->show();
			}
		}
	}
	else if (ui->slave_recv->isChecked())
	{
		if (host_send != nullptr)
		{
			host_send->hide();
		}

		if (slave_recv == nullptr)
		{
			slave_recv = new Slave_recv(this);

			slave_recv->move(QPoint(0, 0));
			slave_recv->raise();
			slave_recv->show();
		}
		else
		{
			if (slave_recv->isHidden())
			{
				slave_recv->raise();
				slave_recv->show();
			}
		}
	}
}
