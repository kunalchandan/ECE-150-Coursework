//============================================================================
// Name        : ECE-150-Practice.cpp
// Author      : Kunal Chandan
// Version     :
// Copyright   : 
//============================================================================

#include <iostream>

const int size = sizeof(int)*8;
bool bin[2][size];

void dec2bin(int dec){
	for(int x = size-1; x >= 0; x--){
		if(dec-(1 << x) >= 0){
			bin[0][x] = !bin[0][x];
			dec-=(1 << x);
			std::cout << dec << "\n";
		}
	}
}

void dec_to_bin(int dec){
	for(int x = size-1; x >= 0; x--){
		bin[1][x] = dec / (1 << x);
		dec = dec % (1 << x);
	}
	std::cout << std::endl;
}

int main() {
	int dec = 12354;
	std::cout << dec << std::endl;

	dec2bin(dec);
	dec_to_bin(dec);
	for(int x = size-1; x >= 0; x--){
			std::cout << bin[0][x];
	}std::cout << std::endl;
	for(int x = size-1; x >= 0; x--){
			std::cout << bin[1][x];
	}
	std::cout << std::endl;
	return 0;
}
