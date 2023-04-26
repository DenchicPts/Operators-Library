#include "DenchicPts.h"
int main() {
	srand(time(NULL));

	vector ab = VectorFill(100, 20);
	set kek = SetFill(10, 20);
	multiset dich = MultiSetFill(10, 20);

	map kekich = MapFill<int, string>(5);
	multimap depack = MultiMapFill<int, string>(5);

	cout << ab << endl << kek << endl << dich << endl;
	cout << kekich << endl << depack;
	return 0;
}
