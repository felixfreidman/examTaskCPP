#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Set {
public:
	vector<char> setInit;
	//Добавление элемента
	vector<char>  appendMember(char symbol);
	//Вычитание элемента
	vector<char>  evictMember(char symbol);
	//Сравнение множеств
	bool compareSets(Set set2);
	//Пересечение множеств
	Set crossSets(Set set2);
	//Просто выводим в печать элементы множества
	void print();

};