#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "host_send.h"
#include "slave_recv.h"

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = 0);
	~MainWindow();

private slots:
	void on_chooseButton_clicked();

private:
	Ui::MainWindow* ui;
	Host_Send* host_send;
	Slave_recv* slave_recv;

protected:
	void keyPressEvent(QKeyEvent  *event);
	bool event(QEvent *e);
};

#endif // MAINWINDOW_H
