//============================================================================
// Name        : ECE150-Project1.cpp
// Author      : Kunal Chandan
// Student ID  : 20778788
// Version     : 2.452.5.23
//============================================================================

#include <iostream>
#include <cmath>

#ifndef MARMOSET_TESTING
int main();
#endif
int pascal_triangle(int n);
int pascal_triangle_recursive(int n);
unsigned long fact(int n);

unsigned long fact(int n){
	unsigned long x = 1;
	while(n > 1){
		x*=n;
		n--;
	}
	return x;
}

unsigned long choose(int n, int k){
	unsigned long fallfact = 1;
	if(k > n/2){
		k=n-k;
	}
	int count = 1;
	for(int x = n-k+1; x <= n; x++){
		fallfact*=x;
		if(count <= k){
			fallfact/=count;
			count++;
		}
	}
	return fallfact;
}

int pascal_triangle(int n){
	int count = 0;
	for(int x = 0; x <= n; x++){
		for(int r = 0; r < x+1;r++){
			count++;
			std::cout << choose(x,r) << " ";
		}
		std::cout << std::endl;
	}
	return count;
}

int pascal_triangle_recursive(int n){
	if(n < 0){
		return 0;
	}
	int count = pascal_triangle_recursive(n-1);
	for(int r = 0; r <= n;r++){
		count++;
		std::cout << choose(n,r) << " ";
	}
	std::cout << std::endl;
	return count;
}

#ifndef MARMOSET_TESTING
int main() {
	std::cout << pascal_triangle(14) << std::endl;
	std::cout << choose(200, 100);
	//std::cout << pascal_triangle_recursive(100) << std::endl;

	return 0;
}
#endif
