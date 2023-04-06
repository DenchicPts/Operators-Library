#include "DenchicPts.h"
#include <set>


//                                   Operator Work

template<typename Type>
ostream& operator<<(ostream& stream, const set<Type>& sets) { // ����� ��������� ����� cout
	for (const auto& i : sets)
		stream << i << " ";
	return stream;
}

template<typename Type>
ostream& operator<<(ostream& stream, const multiset<Type>& multiset) { // ����� ������ ��������� ����� cout
	for (const auto& i : multiset)
		stream << i << " ";
	return stream;
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