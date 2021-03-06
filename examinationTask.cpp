// examinationTask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "Set.h"
using namespace std;

//Перегруженный оператор сложения, то есть объединение
Set operator + (Set set1, Set set2) {
	int sizeOfSetFirst = set1.setInit.size();
	int sizeOfSetSecond = set2.setInit.size();
	int i = 0;
	int j = 0;
	for (i = 0; i < sizeOfSetFirst; i++) {

		for (j = 0; j < sizeOfSetSecond; j++) {
			if (set1.setInit[i] != set2.setInit[j]) {
				set1.appendMember(set2.setInit[j]);
			}
		}
		j++;
	}
	sort(set1.setInit.begin(), set1.setInit.end());
	set1.setInit.erase(unique(set1.setInit.begin(), set1.setInit.end()), set1.setInit.end());
	return set1;
};
//Перегруженный оператор вычитания, то есть вычитание множества из множества
Set operator - (Set set1, Set set2) {
	sort(set1.setInit.begin(), set1.setInit.end());
	sort(set2.setInit.begin(), set2.setInit.end());
	int sizeOfSetFirst = set1.setInit.size();
	int sizeOfSetSecond = set2.setInit.size();
	Set solution = {};

	int i = 0;
	int j = 0;
	for (i = 0; i < set1.setInit.size(); i++) {
		for (j = 0; j < sizeOfSetSecond; j++) {
			if (set1.setInit[i] == set2.setInit[j]) {
				set1.setInit.erase(remove(set1.setInit.begin(), set1.setInit.end(), set1.setInit[i]), set1.setInit.end());
			}
		}
		j++;
	}
	return set1;

	return solution;
};
//Я знаю, что стоило применить функцию, но у меня голова не варила уже так поздно либо я просто глупый.
int main()
{
	setlocale(LC_ALL, "Russian");
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
	}
	else
		fout << "No such" << endl;
	fout << "Несовпадающие предложения все остальные" << endl;
	fout.close();
}
