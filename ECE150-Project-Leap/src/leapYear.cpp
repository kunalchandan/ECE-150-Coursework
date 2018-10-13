//============================================================================
// Name        : leapYear.cpp
// Author      : Kunal Chandan
// Version     : 1.0
// Description : Project Leap Year
//============================================================================

#include <cmath>
#include <iostream>

#ifndef MARMOSET_TESTING
int main();
#endif
bool is_leap_year(int year);

bool is_leap_year(int year){
	bool ret = false;
	if(year>=1582){
		if(year%4 == 0){
			ret = true;
		}
		if(year%100 == 0){
			ret = false;
		}
		if(year%400 == 0){
			ret = true;
		}
	}
	return ret;
}

#ifndef MARMOSET_TESTING
int main() {
	int year;
	std::cout << "Please enter a year." << std::endl;
	std::cin >> year;
	std::cout << year;
	if(is_leap_year(year)){
		std::cout << " is a leap year!" << std::endl;
	}
	else if(!is_leap_year(year)){
		std::cout << " is not a leap year!" << std::endl;
	}
}
#endif
