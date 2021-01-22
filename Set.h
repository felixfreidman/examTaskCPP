#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Set {
public:
	vector<char> setInit;
	//Добавить элемент во множество
	vector<char>  appendMember(char symbol) {
		setInit.push_back(symbol);
		sort(setInit.begin(), setInit.end());
		setInit.erase(unique(setInit.begin(), setInit.end()), setInit.end());
		return setInit;
	};
	//Убрать элемент из множества
	vector<char>  evictMember(char symbol) {
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
	bool compareSets(Set set2) {
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
	Set crossSets(Set set2) {
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
	//Метод для отображения элементов множества
	void print() {
		for (int i = 0; i < setInit.size(); i++) {
			cout << " ' " << setInit[i] << " ' ";
		}
		cout << "" << endl;
	}
};
//Перегруженный оператор сложения: теперь это оператор объединения множеств
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
//Перегруженный оператор вычитания: теперь это оператор вычитения множеств
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

