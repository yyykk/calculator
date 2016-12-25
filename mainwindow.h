#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "string"
#include "iostream"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void show_log(){
        std::cout << "number0 = " << number0 << std::endl;
        std::cout << "sign = " << sign << std::endl;
        std::cout << "number1 = " << number1 << std::endl;
        std::cout << "result = " << result << std::endl;
    }
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    int handle_number(int num);
    int handle_sign(char s);
    int to_LCD(QString r);
    void init_all();

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

    int point_flag = 0;
    int flag = 0;
    float number0 = 0;
    char sign = 0;
    float number1 = 0;
    float result = 0;

    QString number_str = "";
};

#endif // MAINWINDOW_H
