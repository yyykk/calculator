#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::to_LCD(QString r){
    ui->lcdNumber->display(r);
    return 1;
}

void MainWindow::init_all(){
        point_flag = 0;
        flag = 0;
        number0 = 0;
        sign = 0;
        number1 = 0;
        result = 0;
}

int MainWindow::handle_number(int num){
    float& temp = sign == 0 ? number0 : number1;
    flag = sign == 0 ? 0 : 1;
    if(temp == 0){
        if(point_flag == 1){
            number_str += QString::number(num);
        }else{
            number_str = QString::number(num);
        }
    }else{
        number_str += QString::number(num);
    }
    temp = number_str.toFloat();
    to_LCD(number_str);
    return 1;
}
int MainWindow::handle_sign(char s){
    if (flag == 0){
        result = number0;
    }else{
        switch (sign){
        case '+' : result = number0 + number1; break;
        case '-' : result = number0 - number1; break;
        case '*' : result = number0 * number1; break;
        case '/' :
            if(number1 != 0){
                result = number0 / number1; break;
            }else{
                init_all();
                to_LCD("FFFFFFFF");
                return 0;
            }
        }
        show_log();
        QString temp = QString("%1").arg(result);
        to_LCD(temp.left(5));
    }
    show_log();
    point_flag = 0;
    sign = s;
    flag = 0;
    number0 = result;
    number1 = 0;
    return 1;
}

void MainWindow::on_pushButton_clicked()
{
    handle_number(1);
    show_log();
}

void MainWindow::on_pushButton_2_clicked()
{
    handle_number(2);
    show_log();
}

void MainWindow::on_pushButton_3_clicked()
{
    handle_number(3);
    show_log();
}

void MainWindow::on_pushButton_4_clicked()
{
    handle_number(4);
    show_log();
}

void MainWindow::on_pushButton_5_clicked()
{
    handle_number(5);
    show_log();
}

void MainWindow::on_pushButton_6_clicked()
{
    handle_number(6);
    show_log();
}

void MainWindow::on_pushButton_7_clicked()
{
    handle_number(7);
    show_log();
}

void MainWindow::on_pushButton_8_clicked()
{
    handle_number(8);
    show_log();
}

void MainWindow::on_pushButton_9_clicked()
{
    handle_number(9);
    show_log();
}

void MainWindow::on_pushButton_10_clicked()
{
    init_all();
    to_LCD("0");
}

void MainWindow::on_pushButton_11_clicked()
{
    handle_number(0);
    show_log();
}

void MainWindow::on_pushButton_12_clicked()
{
    if(sign == 0){
        number_str += ".";
    }else if(sign == '='){
        init_all();
        number_str = ".";
    }else if(flag != 0){
        number_str += ".";
    }
    point_flag = 1;

    to_LCD(number_str);
}

void MainWindow::on_pushButton_13_clicked()
{
    handle_sign('+');
}

void MainWindow::on_pushButton_15_clicked()
{
    handle_sign('-');
}

void MainWindow::on_pushButton_14_clicked()
{
    handle_sign('*');
}

void MainWindow::on_pushButton_16_clicked()
{
    handle_sign('/');
}

void MainWindow::on_pushButton_17_clicked()
{
    handle_sign('=');
}
