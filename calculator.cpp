// calculator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "iostream"
#include "string"
#include "sstream"

using namespace std;

class calculator {
public:
	calculator(){//���캯��
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
	int handle_input(int sign);//��������ֵ
	void init_all();//��ʼ�����б���
	void show_LCD(string str);//LCD��ʾ����
	int sign_to_int(char input);//�����ַ�תint���ţ�������Ŵ��Ŷ�Ӧ��
	string int_to_string(int input);//int����ת�ַ�
private:
	float number1;
	string symbol;//+-*/
	float number2;
	float result;
	int now;
	int next;
	int flag;
	string numberstr1;//number1���ַ���
	string numberstr2;
	string R;//������ַ���
};

int calculator::handle_input(int sign)//�ú���ע���case�Ķ���ÿһ��case��ʾ��������һ��״̬
{
	switch (now){
	case 0:
		if (sign == 0 || (sign >= 13 && sign <= 15)) {//input 0,*,/
			show_LCD("0");
			next = 0;
		}else if (sign >= 1 && sign <= 10) {//input 1~9,.
			if (sign == 10) {//�������ΪС����.��С�����־λ��1
				flag = 1;
				numberstr1 += int_to_string(sign);
			}else{
				numberstr1 = int_to_string(sign);
			}
			show_LCD(numberstr1);
			next = 1;
		}else {//����+-���ʾ����Ϊ�����߸�
			numberstr1 = int_to_string(sign);
			show_LCD(numberstr1);
			next = 1;
		}
		break;
	case 1:
		if (sign >= 0 && sign <= 10) {//����0~10��.
			if (sign != 10 || flag == 0) {//�������Ĳ���С�������С�����־��Ϊ1����ֱ�����������.
				if (sign == 10) {//�������ΪС����,��С�����־��1
					flag = 1;
				}
				numberstr1 += int_to_string(sign);
			}
			show_LCD(numberstr1);//��״̬��ʾnumber1
			next = 1;
		}else if (sign >= 11 && sign <= 14) {//����״̬��ת��
			symbol = int_to_string(sign);
			show_LCD(numberstr1);
			next = 2;
		}else {//���롰=����ֱ������������ʼ�����б�����׼����һ�μ���
			R = numberstr1;
			show_LCD(R);
			init_all();
		}
		break;
	case 2:
		flag = 0;
		if (sign == 13 || sign == 14) {//���롰*/����ֱ�Ӹ�symbol��ֵ
			symbol = int_to_string(sign);
			show_LCD(numberstr1);
			next = 2;
		}else if (sign == 0 || sign == 15) {//���롰0��=�����ı�״̬
			show_LCD(numberstr1);
			next = 2;	
		}else if (sign >= 1 && sign <= 10) {//��״̬0���ƣ�ֻ����number1������number2
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
		if (sign == 15) {//���롰=������������
			R = numberstr1 + " " + symbol + " " + numberstr2;
			show_LCD(R);
			init_all();
		}else {//
			if (sign != 10 || flag == 0) {//��״̬1���ƣ�ֻ����number1������number2
				if (sign == 10) {
					flag = 1;
				}
				numberstr2 += int_to_string(sign);
			}
			show_LCD(numberstr2);
			next = 3;
		}
		break;
	default://�������
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
	}else {//��Ϊ��������������������Ϊ���֣���charת��Ӧint
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
		stringstream temp;//int�ַ�תstring
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











