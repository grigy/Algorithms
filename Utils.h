#ifndef ALGO1_UTILS_H
#define ALGO1_UTILS_H

#include <string>
#include <fstream>
#include <vector>

bool readNumbers(const std::string& name, std::vector<int>& v)
{
	std::ifstream f(name);

	if (f) {
		int d;
		while (f >> d) {
			//std::cout << d << std::endl;
			v.push_back(d);
		}
		std::cout << "read numbers: " << v.size() << std::endl;
		return true;
	} else {
		std::cout << "can't open file " << name << std::endl;
		return false;
	}
}

void waitForEnter() {
	std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
}

#endif