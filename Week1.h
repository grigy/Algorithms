#include <iostream>
#include <vector>
#include "Utils.h"
#include "CountInversions.h"

void Week1(const string& name) {
	cout << __FUNCTION__ << endl;
	std::vector<int> v;
	if ( readNumbers(name, v) ) {
		std::cout << CountInversions(v) << std::endl;
	}
	waitForEnter();
}