#pragma once

#include <iostream>
#include <type_traits>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

template<typename Collection>
string Join(const Collection& collect, char d);

template<typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p);

#include "OperVector.cpp"
#include "OperSet.cpp"
#include "OperMap.cpp"



//									Multi Function

template<typename Collection>
string Join(const Collection& collect, char d) {
	stringstream ss;
	bool first = true;
	for (const auto& i : collect)
	{
		if (!first) {
			ss << d << " ";
		}
		first = false;
		ss << i;
	}
	return ss.str();
}

template<typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p) {
	return out << '(' << p.first << '-' << p.second << ')';
}