#include <iostream>
#include "Set.h"
using namespace std;

vector<char>  Set::appendMember(char symbol) {
	setInit.push_back(symbol);
	sort(setInit.begin(), setInit.end());
	setInit.erase(unique(setInit.begin(), setInit.end()), setInit.end());
	return setInit;
};
//Вычитание элемента
vector<char>  Set::evictMember(char symbol) {
	int index = -1;
	auto it = find(setInit.begin(), setInit.end(), symbol);
	if (it != setInit.end())
	{
		index = it - setInit.begin();
	}
	setInit.erase(setInit.begin() + index);
	return setInit;
};
//Сравнение множеств
bool Set::compareSets(Set set2) {
	sort(setInit.begin(), setInit.end());
	sort(set2.setInit.begin(), set2.setInit.end());
	int sizeOfSetFirst = setInit.size();
	int sizeOfSetSecond = set2.setInit.size();
	bool result = true;
	int i = 0;
	int j = 0;
	for (i = 0; i < sizeOfSetFirst; i++) {
		if (setInit[i] != set2.setInit[j]) {
			result = false;
		}
		j++;
	}
	if (result) {
		return result;
	}
	else {
		return result;
	}
};
//Пересечение множеств
Set Set::crossSets(Set set2) {
	Set set3{};
	int sizeOfSetFirst = setInit.size();
	int sizeOfSetSecond = set2.setInit.size();
	int i = 0;
	int j = 0;
	for (i = 0; i < sizeOfSetFirst; i++) {
		for (j = 0; j < sizeOfSetSecond; j++) {
			if (setInit[i] == set2.setInit[j]) {
				set3.appendMember(setInit[i]);
			}
		}
	}
	return set3;
};
//Просто выводим в печать элементы множества
void Set::print() {
	for (int i = 0; i < setInit.size(); i++) {
		cout << " ' " << setInit[i] << " ' ";
	}
	cout << "" << endl;
}
		if (result) {
			return result;
		}
		else {
			return result;
		}
	};
	//Пересечение множеств
	Set Set::crossSets(Set set2) {
		Set set3{};
		int sizeOfSetFirst = setInit.size();
		int sizeOfSetSecond = set2.setInit.size();
		int i = 0;
		int j = 0;
		for (i = 0; i < sizeOfSetFirst; i++) {
			for (j = 0; j < sizeOfSetSecond; j++) {
				if (setInit[i] == set2.setInit[j]) {
					set3.appendMember(setInit[i]);
				}
			}
		}
		return set3;
	};
	//Просто выводим в печать элементы множества
	void Set::print() {
		for (int i = 0; i < setInit.size(); i++) {
			cout << " ' " << setInit[i] << " ' ";
		}
		cout << "" << endl;
	}
