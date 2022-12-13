#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>

using namespace std;

//подсчёт количества слов
int WordCnt(const string& str){
	int cnt = 0;
	stringstream ss;
	ss << str;
	string tmp;
	while(ss >> tmp){ ++cnt; }
	return cnt;
}

int main(){
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	ifstream in("input.txt");
	string input;//слово
	stringstream ss;	//строковый поток
	int cnt;
	cout << "Количество слов: ";
	cin >> cnt;
	while(getline(in, input, '.')){//считываем по предложению
		 if(cnt == 	WordCnt(input))
			 ss << input << '\n'; //заносим в строковый поток

	}
	while(getline(ss, input)){
		cout << input << '\n';// выводим предложения
	}
	in.close();//закрываем файл										   
	system("pause>>void");
}
