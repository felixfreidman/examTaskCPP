#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Set {
public:
	vector<char> setInit;
	//���������� ��������
	vector<char>  appendMember(char symbol);
	//��������� ��������
	vector<char>  evictMember(char symbol);
	//��������� ��������
	bool compareSets(Set set2);
	//����������� ��������
	Set crossSets(Set set2);
	//������ ������� � ������ �������� ���������
	void print();

};