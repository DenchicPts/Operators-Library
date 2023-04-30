#pragma once

#include "DenchicPts.h"
#include <map>

//                                     Operation Work

template<typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& m) { // Вывод контейнера map через cout
	return out << '{' << Join(m, NULL) << '}';
}

template<typename Key, typename Value>
ostream& operator<<(ostream& out, const multimap<Key, Value>& m) { // Вывод мульти контейнера map через cout
	return out << '{' << Join(m, NULL) << '}';
}

template <typename Type1, typename Type2>
map<Type1, Type2>
operator+(const map<Type1, Type2>& map1, const map<Type1, Type2>& map2) {
	map<Type1, Type2> result = map1;
	result.insert(map2.begin(), map2.end());
	return result;
}

template <typename Type1, typename Type2>
multimap<Type1, Type2>
operator+(const multimap<Type1, Type2>& map1, const multimap<Type1, Type2>& map2) {
	multimap<Type1, Type2> result = map1;
	result.insert(map2.begin(), map2.end());
	return result;
}

template <typename Type1, typename Type2>
multimap<Type1, Type2>
operator+(const map<Type1, Type2>& map1, const multimap<Type1, Type2>& map2) {
	multimap<Type1, Type2> result = map2;
	result.insert(map1.begin(), map1.end());
	return result;
}

template <typename Type1, typename Type2>
multimap<Type1, Type2>
operator+(const multimap<Type1, Type2>& map1, const map<Type1, Type2>& map2) {
	multimap<Type1, Type2> result = map1;
	result.insert(map2.begin(), map2.end());
	return result;
}
//                              Default Function

template<typename Type, typename Type2>
void MapFill(map<Type, Type2>& m, const size_t& cell) { // заполнение map вводом с клавиатуры
	Type first;
	Type2 second;
	for (size_t i = 0; i < cell; i++)
	{
		cout << "Enter key for value : ";
		cin >> first;
		cout << "Enter value : ";
		cin >> second;
		m.emplace(first, second);
	}
}

template<typename Type, typename Type2>
map<Type,Type2> MapFill( const size_t& cell) { // заполнение map вводом с клавиатуры
	map<Type, Type2> m;
	Type first;
	Type2 second;
	for (size_t i = 0; i < cell; i++)
	{
		cout << "Enter key for value : ";
		cin >> first;
		cout << "Enter value : ";
		cin >> second;
		m.emplace(first, second);
	}
	return m;
}

template<typename Type, typename Type2>
void MultiMapFill(multimap<Type, Type2>& m, const size_t& cell) { // заполнение multimap вводом с клавиатуры
	Type first;
	Type2 second;
	for (size_t i = 0; i < cell; i++)
	{
		cout << "Enter key for value : ";
		cin >> first;
		cout << "Enter value : ";
		cin >> second;
		m.emplace(first, second);
	}
}

template<typename Type, typename Type2>
multimap<Type,Type2> MultiMapFill( const size_t& cell) { // заполнение multimap вводом с клавиатуры
	multimap<Type, Type2> m;
	Type first;
	Type2 second;
	for (size_t i = 0; i < cell; i++)
	{
		cout << "Enter key for value : ";
		cin >> first;
		cout << "Enter value : ";
		cin >> second;
		m.emplace(first, second);
	}
	return m;
}

template <typename Type1, typename Type2>
multimap<Type1, Type2>
MapToMulti(const map<Type1, Type2>& map1, const map<Type1, Type2>& map2)
{
	multimap<Type1, Type2> result;
	result.insert(map1.begin(), map1.end());
	result.insert(map2.begin(), map2.end());
	return result;
}

template <typename Type1, typename Type2>
multimap<Type1, Type2>
MapToMulti(multimap<Type1, Type2>& result, const map<Type1, Type2>& map1, const map<Type1, Type2>& map2)
{
	result.insert(map1.begin(), map1.end());
	result.insert(map2.begin(), map2.end());
	return result;
}

template <typename Type1, typename Type2>
map<Type1, Type2>
MultiToMap(map<Type1, Type2>& result, const multimap<Type1, Type2>& map1, const multimap<Type1, Type2>& map2)
{
	result.insert(map1.begin(), map1.end());
	result.insert(map2.begin(), map2.end());
	return result;
}

template <typename Type1, typename Type2>
map<Type1, Type2>
MultiToMap(const multimap<Type1, Type2>& map1, const multimap<Type1, Type2>& map2)
{
	map<Type1, Type2> result;
	result.insert(map1.begin(), map1.end());
	result.insert(map2.begin(), map2.end());
	return result;
}