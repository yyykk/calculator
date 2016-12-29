#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QString"
#include "iostream"
#include "string"
#include "sstream"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int handle_input(int sign);//处理输入值
    void init_all();//初始化所有变量
    void show_LCD(QString str);//LCD显示变量
    int sign_to_int(QString input);//输入字符转int代号，详见符号代号对应表
    QString int_to_QString(int input);//int代号转字符
    QString compute();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
private:
    Ui::MainWindow *ui;

    float number1;
    QString symbol;//+-*/
    float number2;
    float result;
    int now;
    int next;
    int flag;
    QString numberstr1;//number1的字符串
    QString numberstr2;
    QString R;//结果的字符串

    QString number_str = "";
};

#endif // MAINWINDOW_H
