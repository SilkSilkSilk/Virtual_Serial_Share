#ifndef MY_SCROLLAREA_H
#define MY_SCROLLAREA_H

#include <QWidget>
#include <QScrollArea>

class my_ScrollArea : public QScrollArea
{
	Q_OBJECT
public:
	my_ScrollArea(QWidget* parent = nullptr);
	~my_ScrollArea();

	virtual void wheelEvent(QWheelEvent* event);
	virtual bool eventFilter(QObject* obj, QEvent* event);
};

#endif // MY_SCROLLAREA_H
