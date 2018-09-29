#include "my_scrollarea.h"

my_ScrollArea::my_ScrollArea(QWidget *parent) :
    QScrollArea(parent)
{

}

my_ScrollArea::~my_ScrollArea()
{

}

void my_ScrollArea::wheelEvent(QWheelEvent* event)
{
    QScrollArea::wheelEvent(event);
}

bool my_ScrollArea::eventFilter(QObject *obj, QEvent *event)
{
    return QScrollArea::eventFilter(obj, event);
}
