#include "DenchicPts.h"

void main() {


	multimap<int, string> abobus;
	abobus.emplace(1, "2");
	abobus.emplace(3, "4");
	abobus.emplace(2, "3");
	abobus.emplace(5, "6");
	abobus.emplace(6, "7");


	map<int, string> abobus2;
	abobus.emplace(2, "2");
	abobus.emplace(4, "4");
	abobus.emplace(3, "3");
	abobus.emplace(6, "6");
	abobus.emplace(7, "7");

	multimap<int, string> abobus3 = abobus2 + abobus;

	cout << abobus + abobus2;
	cout << abobus3;
	return;
}
