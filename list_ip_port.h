#ifndef LIST_IP_PORT_H
#define LIST_IP_PORT_H

#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <iostream>

namespace Ui {
class list_ip_port;
}

class list_ip_port : public QWidget
{
    Q_OBJECT
public:
    explicit list_ip_port(QWidget *parent = 0);
    ~list_ip_port();
    void local_update();
    void set_text_ip(QString ip);
    void set_text_port(QString po);
    void set_text_ip_port(QString ip, QString po);
    void setStyle(qint8 se);
    void ip_port_Press();
    void ip_port_Release();
    void ip_port_Move(bool flg);
    void ip_port_double(qint8 index);

signals:
    void update_ip_port();

public slots:
    void update_iprt(void);
    void open_double(qint8 index);
    void close_double();

public:
    //static qint8 last_edit;

private:
    Ui::list_ip_port *ui;
    QString list_ip;
    QString list_port;
    bool Press_Flg = false;
    bool Release_Flg = false;
    bool is_select_Flg = false;
    bool is_move_Flg = false;

protected:

};

#endif // LIST_IP_PORT_H
