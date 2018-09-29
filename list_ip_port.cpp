#include "list_ip_port.h"
#include "ui_list_ip_port.h"

//QLineEdit double_ip, double_port;
//qint8 list_ip_port::last_edit = -1;

list_ip_port::list_ip_port(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_ip_port)
{
    ui->setupUi(this);

    connect(this, &list_ip_port::update_ip_port, this, &list_ip_port::update_iprt);
    setStyle(3);

//    this->installEventFilter(this);
    this->show();
}

list_ip_port::~list_ip_port()
{
    delete ui;
}

void list_ip_port::set_text_ip(QString ip)
{
    list_ip = ip;
    emit update_ip_port();
}

void list_ip_port::set_text_port(QString po)
{
    list_port = po;
    emit update_ip_port();
}

void list_ip_port::set_text_ip_port(QString ip, QString po)
{
    list_ip = ip;
    list_port = po;
    emit update_ip_port();
}

void list_ip_port::update_iprt(void)
{
    ui->label_ip->setText(list_ip);
    ui->label_port->setText(list_port);
}

void list_ip_port::setStyle(qint8 se)  //false == normal
{
    //底色
    //color: rgb(178, 223, 238);    sel色            1
    //color: rgb();    normal色         0

    //边框
    //color: rgb(100, 153, 252);    move sel色       2
    //color: rgb(188, 188, 188);    no move sel色    3

    if( se == 0)
    {
        this->setStyleSheet("");
    }
    else if (se == 1)
    {
        this->setStyleSheet("background-color: rgb(178, 223, 238)");
    }
    else if(se == 2)
    {
        ui->frame->setStyleSheet(QString::fromUtf8("#frame{border:2px solid rgb(100, 153, 252)};"));
    }
    else if ( se == 3)
    {
        ui->frame->setStyleSheet(QString::fromUtf8("#frame{border:2px solid rgb(188, 188, 188)};"));
    }
}

void list_ip_port::ip_port_Press()
{
    if ( Release_Flg == true)
    {
        Release_Flg = false;
    }

    if (Press_Flg != true)
    {
        Press_Flg = true;
    }
}

void list_ip_port::ip_port_Release()
{
    if (Press_Flg == true)
    {
        Press_Flg = false;

        if ( is_select_Flg == false)
        {
            is_select_Flg = true;
            setStyle(1);
        }
        else
        {
            is_select_Flg = false;
            setStyle(0);
        }
    }
}

void list_ip_port::ip_port_Move(bool flg)       //true:move     false:no move
{
    if ( flg == true)
    {
        if (is_move_Flg == false)
        {
            is_move_Flg = true;
            setStyle(2);
        }
    }
    else
    {
        if (is_move_Flg == true)
        {
            is_move_Flg = false;
            setStyle(3);
        }
    }
}

void list_ip_port::open_double(qint8 index)
{
    if ( index >= 20)
        return;

//    double_ip.setGeometry(0, index * 30, 170, 30);
//    double_port.setGeometry(180, index * 30, 100, 30);
}

void list_ip_port::close_double()
{

}

void list_ip_port::ip_port_double(qint8 index)
{
//    double_ip.setText(list_ip);
//    double_port.setText(list_port);

    open_double(index);
}


