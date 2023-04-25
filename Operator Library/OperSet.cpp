#pragma once

#include "DenchicPts.h"
#include <set>
using namespace std;

template<typename Collection>
string Join(const Collection& collect, char d);
//                                   Operator Work

template<typename Type>
ostream& operator<<(ostream& out, const set<Type>& sets) { // ����� ��������� ����� cout
	return  out << '(' << Join(sets,',') << ')';
}

template<typename Type>
ostream& operator<<(ostream& out, const multiset<Type>& multiset) { // ����� ������ ��������� ����� cout
	return  out << '(' << Join(multiset, ',') << ')';
}

//                                     Default Function
template<typename Type>
void SetFill(set<Type>& empty, const int& maks, const size_t& cell) { // ���������� set ���������� ������� �� 0 �� maks
	for (size_t i = 0; i < cell; i++)
		empty.insert(rand() % maks);
}

template<typename Type>
void SetFill(set<Type>& empty, const size_t& cell) { // ���������� set ������ � ����������
	Type intro;
	cout << "Enter only " << typeid(Type).name() << endl;
	for (size_t i = 0; i < cell; i++) {
		cin >> intro;
		empty.insert(intro);
	}
}
template<typename Type>
void MultiSetFill(multiset<Type>& empty, const int& maks, const size_t& cell) { // ���������� multiset ���������� ������� �� 0 �� maks
	for (size_t i = 0; i < cell; i++)
		empty.insert(rand() % maks);
}

template<typename Type>
void MultiSetFill(multiset<Type>& empty, const size_t& cell) { // ���������� multiset ������ � ����������
	Type intro;
	cout << "Enter only " << typeid(Type).name() << endl;
	for (size_t i = 0; i < cell; i++) {
		cin >> intro;
		empty.insert(intro);
	}
}