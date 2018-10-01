#include "listwidget.h"

ListWidget::ListWidget(QWidget* parent) :
	QWidget(parent)
{
	point.setY(10);

	double_edit.double_ip = new QLineEdit(this);
	double_edit.double_port = new QLineEdit(this);
	double_edit.double_ip->hide();
	double_edit.double_port->hide();
	double_edit.double_ip->setFixedSize(170, 30);
	double_edit.double_port->setFixedSize(100, 30);

	for (int i = 0; i < 20; i++)
	{
		ip_port_array[i] = new list_ip_port(double_edit.double_ip, double_edit.double_port, this); //list_ip_port类共用一个ip和port
		ip_port_array[i]->move(point);
		point.setY(point.y() + 30 + 10);
	}

	this->setFixedSize(280, point.y());
}

void ListWidget::MouseEvent(QEvent* event, qint16 xPress, qint16 yPress)
{
	//qDebug() << "ListWidget::MouseEvent" << event->type() << " xPress = " << xPress << " yPress = " << yPress;
	int index = 0;
	for (; index < 20; index++)
	{
		if (ip_port_array[index]->geometry().contains(xPress, yPress))
		{
			break;
		}
	}
	if (index >= 20) //不在控件上
	{
		if (double_edit.last_doubleEdit >= 0 && double_edit.last_doubleEdit < 20)
		{
			ip_port_array[double_edit.last_doubleEdit]->close_double(double_edit.last_doubleEdit); //消去上一次的double_edit
		}
		
//		for(auto a = 0; a < 20; a++)
//		{
//			ip_port_array[a]->ip_port_cansen_select();
//		}
		return;
	}

	switch (event->type())
	{
	case QEvent::MouseButtonPress:
		if (double_edit.double_ip->isVisible() && double_edit.double_ip->geometry().contains(xPress, yPress))
		{
			double_edit.double_ip->setFocus();
		}
		if (double_edit.double_port->isVisible() && double_edit.double_port->geometry().contains(xPress, yPress))
		{
			double_edit.double_port->setFocus();
		}

		ip_port_array[index]->ip_port_Press();
		break;

	case QEvent::MouseButtonRelease:
		ip_port_array[index]->ip_port_Release();
		break;

	case QEvent::MouseMove:
		if (last_move >= 0 && last_move < 20 && last_move != index)
		{
			ip_port_array[last_move]->ip_port_Move(false); //消去上一次的move
		}
		ip_port_array[index]->ip_port_Move(true);
		last_move = index;
		break;

	case QEvent::MouseButtonDblClick:
		if (double_edit.last_doubleEdit >= 0 && double_edit.last_doubleEdit < 20 && double_edit.last_doubleEdit != index)
		{
			ip_port_array[double_edit.last_doubleEdit]->close_double(double_edit.last_doubleEdit); //消去上一次的double_edit
		}
		ip_port_array[index]->ip_port_double(index);
		double_edit.last_doubleEdit = index;
		break;

	default:
		break;
	}
}
