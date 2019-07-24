#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    disabledButton();
}



Widget::~Widget()
{
    delete ui;
}

void Widget::checkButton(void)
{
    if(money>=100)
        ui->pbcoffee->setEnabled(true);
    else
        ui->pbcoffee->setEnabled(false);
    if(money>=150)
        ui->pbtea->setEnabled(true);
    else
        ui->pbtea->setEnabled(false);
    if(money>=200)
        ui->pbgongcha->setEnabled(true);
    else
        ui->pbgongcha->setEnabled(false);
}

void Widget::disabledButton(void)
{
    ui->pbtea->setEnabled(false);
    ui->pbgongcha->setEnabled(false);
    ui->pbcoffee->setEnabled(false);

}

void Widget::changeMoney(int n)
{
    money +=n;
    ui->lcdNumber->display(QString::number(money));

    checkButton();

}


void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbcoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbtea_clicked()
{

    changeMoney(-150);
}

void Widget::on_pbgongcha_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbfinish_clicked()
{
    QMessageBox msg;

    int a= money / 500;
    money %= 500;
    int b = money / 100;
    money %= 100;
    int c = money / 50;
    money %= 50;
    int d = money / 10;

    auto str = QString("");

    str.append("500 = ");
    str.append(QString::number(a));
    str.append("\n");

    str.append("100 = ");
    str.append(QString::number(b));
    str.append("\n");

    str.append("50 = ");
    str.append(QString::number(c));
    str.append("\n");

    str.append("10 = ");
    str.append(QString::number(d));

    msg.information(nullptr,"money",str);

    money = 0;
    ui->lcdNumber->display(QString::number(money));
    disabledButton();
}
