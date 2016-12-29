#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("奇奇的计算器");
    number1 = 0;
    symbol = "";
    number2 = 0;
    result = 0;
    now = 0;
    next = 0;
    flag = 0;
    numberstr1 = "0";
    numberstr2 = "0";
}

MainWindow::~MainWindow(){
    delete ui;
}

QString MainWindow::compute(){
    number1 = numberstr1.right(5).toFloat();
    number2 = numberstr2.right(5).toFloat();
    switch (sign_to_int(symbol)) {
    case 11 : result = number1 + number2; break;
    case 12 : result = number1 - number2; break;
    case 13 : result = number1 * number2; break;
    case 14 :
        if (number2 == 0){
            return "EEEEE";
        }else{
            result = number1 / number2; break;
        }
    default : break;
    }
    return QString("%1").arg(result).left(5);

}

int MainWindow::handle_input(int sign)//该函数注意分case阅读，每一个case表示计算器的一种状态
{
    switch (now){
    case 0:
        if (sign == 0 || (sign >= 13 && sign <= 15)) {//input 0,*,/
            show_LCD("0");
            next = 0;
        }else if (sign >= 1 && sign <= 10) {//input 1~9,.
            if (sign == 10) {//如果输入为小数点.则将小数点标志位置1
                flag = 1;
                numberstr1 += int_to_QString(sign);
            }else{
                numberstr1 = int_to_QString(sign);
            }
            show_LCD(numberstr1);
            next = 1;
        }else {//输入+-则表示该数为正或者负
            numberstr1 = int_to_QString(sign);
            show_LCD(numberstr1);
            next = 1;
        }
        break;
    case 1:
        if (sign >= 0 && sign <= 10) {//输入0~10，.
            if (sign != 10 || flag == 0) {//如果输入的不是小数点或者小数点标志不为1，则直接在数后加上.
                if (sign == 10) {//如果输入为小数点,则将小数点标志置1
                    flag = 1;
                }
                numberstr1 += int_to_QString(sign);
            }
            show_LCD(numberstr1);//该状态显示number1
            next = 1;
        }else if (sign >= 11 && sign <= 14) {//参照状态跳转表
            symbol = int_to_QString(sign);
            show_LCD(numberstr1);
            next = 2;
        }else {//输入“=”，直接输出结果，初始化所有变量，准备下一次计算
            R = numberstr1;
            show_LCD(R);
            init_all();
        }
        break;
    case 2:
        flag = 0;
        if (sign == 13 || sign == 14) {//输入“*/”则直接给symbol赋值
            symbol = int_to_QString(sign);
            show_LCD(numberstr1);
            next = 2;
        }else if (sign == 15) {//输入“0，=”不改变状态
            show_LCD(numberstr1);
            next = 2;
        }else if (sign >= 0 && sign <= 10) {//与状态0相似，只不过number1换成了number2
            if (sign == 10) {
                flag = 1;
                numberstr2 += int_to_QString(sign);
            }else{
                numberstr2 = int_to_QString(sign);
            }
            show_LCD(numberstr2);
            next = 3;
        }else {
            numberstr2 = int_to_QString(sign);
            show_LCD(numberstr2);
            next = 3;
        }
        break;
    case 3:
        if (sign == 15) {//输入“=”，则输出结果
            R = compute();
            show_LCD(R);
            init_all();
        }else if(sign >= 11 && sign <= 14){
            show_LCD(numberstr2);
            next = 3;
        }else {//
            if (sign != 10 || flag == 0) {//与状态1相似，只不过number1换成了number2
                if (sign == 10) {
                    flag = 1;
                }
                numberstr2 += int_to_QString(sign);
            }
            show_LCD(numberstr2);
            next = 3;
        }
        break;
    default://输入出错
        show_LCD("FFFFF");
        init_all();
        break;
    }
    now = next;
    cout << "now = " << now << endl;
    return 0;
}

void MainWindow::init_all(){
    number1 = 0;
    symbol = "";
    number2 = 0;
    result = 0;
    now = 0;
    next = 0;
    flag = 0;
    numberstr1 = "0";
    numberstr2 = "0";
    R = "";
}

void MainWindow::show_LCD(QString str){
    ui->lcdNumber->display(str);
}

int MainWindow::sign_to_int(QString input){
    if (input == "+") {
        return 11;
    }else if (input == "-") {
        return 12;
    }else if (input == "*") {
        return 13;
    }else if (input == "/") {
        return 14;
    }else if (input == "=") {
        return 15;
    }
}

QString MainWindow::int_to_QString(int input){
    if (input == 10) {
        return ".";
    }else if (input == 11) {
        return "+";
    }else if (input == 12) {
        return "-";
    }else if (input == 13) {
        return "*";
    }else if (input == 14) {
        return "/";
    }else if (input == 15) {
        return "=";
    }else {
        return QString::number(input);//int字符转QString
    }
}

void MainWindow::on_pushButton_clicked(){
    handle_input(1);
}

void MainWindow::on_pushButton_2_clicked(){
    handle_input(2);
}

void MainWindow::on_pushButton_3_clicked(){
    handle_input(3);
}

void MainWindow::on_pushButton_4_clicked(){
    handle_input(4);
}

void MainWindow::on_pushButton_5_clicked(){
    handle_input(5);
}

void MainWindow::on_pushButton_6_clicked(){
    handle_input(6);
}

void MainWindow::on_pushButton_7_clicked(){
    handle_input(7);
}

void MainWindow::on_pushButton_8_clicked(){
    handle_input(8);
}

void MainWindow::on_pushButton_9_clicked(){
    handle_input(9);
}

void MainWindow::on_pushButton_10_clicked(){
    init_all();
    show_LCD("0");
}

void MainWindow::on_pushButton_11_clicked(){
    handle_input(0);
}

void MainWindow::on_pushButton_12_clicked(){
     handle_input(10);
}

void MainWindow::on_pushButton_13_clicked(){
    handle_input(11);
}

void MainWindow::on_pushButton_15_clicked(){
    handle_input(12);
}

void MainWindow::on_pushButton_14_clicked(){
    handle_input(13);
}

void MainWindow::on_pushButton_16_clicked(){
    handle_input(14);
}

void MainWindow::on_pushButton_17_clicked(){
    handle_input(15);
}
