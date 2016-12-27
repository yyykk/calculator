// calculator.cpp : 定义控制台应用程序的入口点。
//

#include "iostream"
#include "string"
#include "sstream"

using namespace std;

class calculator {
public:
	calculator(){//构造函数
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
	int handle_input(int sign);//处理输入值
	void init_all();//初始化所有变量
	void show_LCD(string str);//LCD显示变量
	int sign_to_int(char input);//输入字符转int代号，详见符号代号对应表
	string int_to_string(int input);//int代号转字符
private:
	float number1;
	string symbol;//+-*/
	float number2;
	float result;
	int now;
	int next;
	int flag;
	string numberstr1;//number1的字符串
	string numberstr2;
	string R;//结果的字符串
};

int calculator::handle_input(int sign)//该函数注意分case阅读，每一个case表示计算器的一种状态
{
	switch (now){
	case 0:
		if (sign == 0 || (sign >= 13 && sign <= 15)) {//input 0,*,/
			show_LCD("0");
			next = 0;
		}else if (sign >= 1 && sign <= 10) {//input 1~9,.
			if (sign == 10) {//如果输入为小数点.则将小数点标志位置1
				flag = 1;
				numberstr1 += int_to_string(sign);
			}else{
				numberstr1 = int_to_string(sign);
			}
			show_LCD(numberstr1);
			next = 1;
		}else {//输入+-则表示该数为正或者负
			numberstr1 = int_to_string(sign);
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
				numberstr1 += int_to_string(sign);
			}
			show_LCD(numberstr1);//该状态显示number1
			next = 1;
		}else if (sign >= 11 && sign <= 14) {//参照状态跳转表
			symbol = int_to_string(sign);
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
			symbol = int_to_string(sign);
			show_LCD(numberstr1);
			next = 2;
		}else if (sign == 0 || sign == 15) {//输入“0，=”不改变状态
			show_LCD(numberstr1);
			next = 2;	
		}else if (sign >= 1 && sign <= 10) {//与状态0相似，只不过number1换成了number2
			if (sign == 10) {
				flag = 1;
				numberstr2 += int_to_string(sign);
			}else{
				numberstr2 = int_to_string(sign);
			}
			show_LCD(numberstr2);
			next = 3;
		}else {
			numberstr2 = int_to_string(sign);
			show_LCD(numberstr2);
			next = 3;
		}
		break;
	case 3:
		if (sign == 15) {//输入“=”，则输出结果
			R = numberstr1 + " " + symbol + " " + numberstr2;
			show_LCD(R);
			init_all();
		}else {//
			if (sign != 10 || flag == 0) {//与状态1相似，只不过number1换成了number2
				if (sign == 10) {
					flag = 1;
				}
				numberstr2 += int_to_string(sign);
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

void calculator::init_all(){
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

void calculator::show_LCD(string str){
	cout << numberstr1 << "\t" << symbol << "\t" << numberstr2 << "\t" << R << endl;
	cout << "LCD : " << str << endl;
}

int calculator::sign_to_int(char input)
{
	if (input == '.') {
		return 	10;
	}else if (input == '+') {
		return 11;
	}else if (input == '-') {
		return 12;
	}else if (input == '*') {
		return 13;
	}else if (input == '/') {
		return 14;
	}else if (input == '=') {
		return 15;
	}else {//因为不是其他符号所以输入为数字，则char转对应int
		return int(input - 48);
	}
}

string calculator::int_to_string(int input){
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
		stringstream temp;//int字符转string
		temp << input;
		return temp.str();
	}
}

int main(){
	calculator test;
	char input;
	while (1) {
		cin >> input;
		test.handle_input(test.sign_to_int(input));
	}
	return 0;
}











