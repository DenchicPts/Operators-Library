#pragma once

#include "DenchicPts.h"
#include <set>

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

template <typename Type, typename = enable_if_t<is_arithmetic_v<Type>>>
set<Type> SetFill( const Type& maks, const size_t& cell) { // ���������� � ����������� set ���������� ������� �� 0 �� maks
	set<Type> ab;
	for (size_t i = 0; i < cell; i++)
		ab.insert(rand() % maks);

	return ab;
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

template<typename Type>
multiset<Type> MultiSetFill(const Type& maks, const size_t& cell) { // ���������� � ����������� multiset ���������� ������� �� 0 �� maks
	multiset<Type> empty;
	for (size_t i = 0; i < cell; i++)
		empty.insert(rand() % maks);

	return empty;
}