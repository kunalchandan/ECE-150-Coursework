#include <iostream>

using namespace std;

int main(){
	int size = 7;
	for (int x = 1; x < size; x++){
		for (int y = x; y < size; y++){
			std::cout << "   ";
		}
		std::cout << " * ";
		for (int y = (x*2)-2; y > 1; y--){
			std::cout << "   ";
		}
		if(x!=1){
			std::cout << " * ";
		}
		std::cout << std::endl;
	}
	for (int x = size; x > 0; x--){
		for (int y = x; y < size; y++){
			std::cout << "   ";
		}
		std::cout << " * ";
		for (int y = (x*2)-2; y > 1; y--){
			std::cout << "   ";
		}
		if(x>1){
			std::cout << " * ";
		}
		std::cout << std::endl;
	}
	return 0;
}
