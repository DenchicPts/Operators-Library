#pragma once

#include "DenchicPts.h"
#include <set>

//                                   Operator Work

template<typename Type>
ostream& operator<<(ostream& out, const set<Type>& sets) { // Вывод множества через cout
	return  out << '(' << Join(sets,',') << ')';
}

template<typename Type>
ostream& operator<<(ostream& out, const multiset<Type>& multiset) { // Вывод мульти множества через cout
	return  out << '(' << Join(multiset, ',') << ')';
}

//                                     Default Function
template<typename Type>
void SetFill(set<Type>& empty, const int& maks, const size_t& cell) { // заполнение set случайными числами от 0 до maks
	for (size_t i = 0; i < cell; i++)
		empty.insert(rand() % maks);
}

template <typename Type, typename = enable_if_t<is_arithmetic_v<Type>>>
set<Type> SetFill( const Type& maks, const size_t& cell) { // заполнение и возвращение set случайными числами от 0 до maks
	set<Type> ab;
	for (size_t i = 0; i < cell; i++)
		ab.insert(rand() % maks);

	return ab;
}

template<typename Type>
void SetFill(set<Type>& empty, const size_t& cell) { // заполнение set вводом с клавиатуры
	Type intro;
	cout << "Enter only " << typeid(Type).name() << endl;
	for (size_t i = 0; i < cell; i++) {
		cin >> intro;
		empty.insert(intro);
	}
}

template<typename Type>
void MultiSetFill(multiset<Type>& empty, const int& maks, const size_t& cell) { // заполнение multiset случайными числами от 0 до maks
	for (size_t i = 0; i < cell; i++)
		empty.insert(rand() % maks);
}

template<typename Type>
void MultiSetFill(multiset<Type>& empty, const size_t& cell) { // заполнение multiset вводом с клавиатуры
	Type intro;
	cout << "Enter only " << typeid(Type).name() << endl;
	for (size_t i = 0; i < cell; i++) {
		cin >> intro;
		empty.insert(intro);
	}
}

template<typename Type>
multiset<Type> MultiSetFill(const Type& maks, const size_t& cell) { // заполнение и возвращение multiset случайными числами от 0 до maks
	multiset<Type> empty;
	for (size_t i = 0; i < cell; i++)
		empty.insert(rand() % maks);

	return empty;
}