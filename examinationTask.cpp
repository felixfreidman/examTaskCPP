// examinationTask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "Set.h"
using namespace std;

//Я знаю, что стоило применить функцию, но у меня голова не варила уже так поздно либо я просто глупый.
int main()
{
	Set set1{};
	Set set2{};
	Set set3{};
	Set set4{};
	ifstream file("file.txt");
	ofstream fout;
	char stopChar = '.';
	char data[1000];
	int counter = 0;
	if (file.is_open()) {
		while (true) {
			file >> data[counter];
			if (data[counter] == stopChar) break;
			set1.appendMember(data[counter]);
			counter++;
		}
		set1.print();
		while (true) {
			file >> data[counter];
			if (data[counter] == stopChar) break;
			set2.appendMember(data[counter]);
			counter++;
		}
		set2.print();
		while (true) {
			file >> data[counter];
			if (data[counter] == stopChar) break;
			set3.appendMember(data[counter]);
			counter++;
		}
		set3.print();
		while (true) {
			file >> data[counter];
			if (data[counter] == stopChar) break;
			set4.appendMember(data[counter]);
			counter++;
		}
		set4.print();
	}
	fout.open("result.txt");
	fout << "Common dictionary:" << endl;
	if (set1.compareSets(set2)) {
		fout << "1 and 2" << endl;
	}
	else if (set1.compareSets(set3)) {
		fout << "1 and 3" << endl;
	}
	else if (set1.compareSets(set4)) {
		fout << "1 and 4" << endl;
	}
	else if (set2.compareSets(set3)) {
		fout << "2 and 3" << endl;
	}
	else if (set2.compareSets(set4)) {
		fout << "2 and 4" << endl;
	}
	else if (set3.compareSets(set4)) {
		fout << "3 and 4" << endl;
	} else
		fout << "No such" << endl;
	fout << "Несовпадающие предложения все остальные" << endl;
	fout.close();
}
