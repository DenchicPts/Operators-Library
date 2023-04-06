#pragma once

#include "DenchicPts.h"
#include <map>
using namespace std;


//                                     Operation Work

template<typename Type, typename Type2>
ostream& operator<<(ostream& stream, const map<Type, Type2>& m) { // ����� ���������� map ����� cout
	for (const auto& i : m)
		stream << i.first << " : " << i.second << endl;
	return stream;
}
template<typename Type, typename Type2>
ostream& operator<<(ostream& stream, const multimap<Type, Type2>& m) { // ����� ������ ���������� map ����� cout
	for (const auto& i : m)
		stream << i.first << " : " << i.second << endl;
	return stream;
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

//                              Default Function

template<typename Type, typename Type2>
void MapFill(map<Type, Type2>& m, const size_t& cell) { // ���������� map ������ � ����������
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
void MultiMapFill(multimap<Type, Type2>& m, const size_t& cell) { // ���������� multimap ������ � ����������
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
