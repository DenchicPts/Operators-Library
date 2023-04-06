#include "DenchicPts.h"

void main() {

	vector<int> abobus;
	vector<float> abobus2;
	VectorFill(abobus, 100, 5);
	VectorFill(abobus2, 100, 5);
	cout << abobus + abobus2;
	
	set<int> geg;
	SetFill(geg, 100, 20);
	cout << geg;
	return;
}