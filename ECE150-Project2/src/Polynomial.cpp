//============================================================================
// Name        : ECE150-Project2.cpp
// Author      : Kunal Chandan
// Version     : KMS..100
// Description : I will commit after this is over
//============================================================================

#include <iostream>
#include <algorithm>
#include <cmath>
#include "Polynomial.h"

void poly_add( poly_t &p, poly_t const &q );
void poly_subtract( poly_t &p, poly_t const &q );
void poly_multiply( poly_t &p, poly_t const &q );
double poly_divide( poly_t &p, double r );
void poly_diff( poly_t &p );
double poly_approx_int( poly_t const &p, double a, double b, unsigned int n );
void ppoly(poly_t &p);
void init_poly(poly_t &p, double const init_coeffs[], unsigned int const init_degree);
#ifndef MARMOSET_TESTING
int main() {
  /*double *coe1 = new double[1]{1};
	double *coe2 = new double[2]{-2,1};
	poly_t p{nullptr, 0};
	poly_t q{nullptr, 0};
	init_poly(p, coe1, 0);
	init_poly(q, coe2, 1);
	ppoly(p);
	std::cout << poly_divide(p,2) << std:: endl;
	ppoly(p);*/
	double *coe4 = new double[8]{1,2,3,4,5,6,7,8};
	poly_t s{nullptr, 0};
	init_poly(s, coe4, 7);
	ppoly(s);
	std::cout << poly_divide(s, 2) << std::endl;
	ppoly(s);
	std::cout << poly_divide(s, 2) << std::endl;
	ppoly(s);
	std::cout << poly_divide(s, 2) << std::endl;
	ppoly(s);
	std::cout << poly_divide(s, 2) << std::endl;
	ppoly(s);
	std::cout << poly_divide(s, 2) << std::endl;
	ppoly(s);
	std::cout << poly_divide(s, 2) << std::endl;
	ppoly(s);
	std::cout << poly_divide(s, 2) << std::endl;
	ppoly(s);
	std::cout << poly_divide(s, 2) << std::endl;
	ppoly(s);
	
	return 0;
}
#endif

//Testing functions
void ppoly(poly_t &p){
	for(int x = 0; x < p.degree+1; x++){
		std::cout << p.a_coeffs[x] << "x^" << x << " + ";
	}
	std::cout << "--- + " << p.degree << std::endl;
}

//Header Functions
void init_poly(poly_t &p, double const init_coeffs[], unsigned int const init_degree){
	if(p.a_coeffs != nullptr){
		delete[] p.a_coeffs;
	}
	p.a_coeffs = new double[init_degree+1]{};
	for(int x = 0; x < init_degree+1; x++){
		p.a_coeffs[x] = init_coeffs[x];
	}
	p.degree = init_degree;
}
void destroy_poly(poly_t &p ){
	delete[] p.a_coeffs;
	p.a_coeffs = nullptr;
	p.degree = 0;
}
unsigned int poly_degree( poly_t const &p ){
	if(p.a_coeffs == nullptr){
		throw 0;
	}
	return p.degree;
}
double poly_coeff( poly_t const&p, unsigned int n ){
	if(p.a_coeffs == nullptr){
		throw 0;
	}else if((0 <= n) && n <= (p.degree)){
		return p.a_coeffs[n];
	}else{
		return 0;
	}
}
double poly_val(poly_t const &p, double const x ){
	if(p.a_coeffs == nullptr){
		throw 0;
	}
	double sum = 0;
	for(int y = p.degree; y >= 0; y--){
		sum = sum*x + p.a_coeffs[y];
	}
	return sum;
}

//Helper Funcitons
void check_null(poly_t const &p){
	if(p.a_coeffs == nullptr){
		throw 0;
	}
}
double* copy_array(double* old_arr, int old_s, int new_s){
	double* new_arr = new double[new_s]{};
	int min_d = std::min(old_s, new_s);
	for(int x = 0; x < min_d; x++){
		new_arr[x] = old_arr[x];
	}
	delete[] old_arr;
	return new_arr;
}
void clean_coeffs(poly_t &p){
	unsigned int num_z = 0;
	for(int x = p.degree; x >= 0; x--){
		if(p.a_coeffs[x] == 0){
			num_z++;
		}
		else{
			x=-1;
		}
	}
	int new_s = ((p.degree-num_z) >= 100000)? 0 : (p.degree-num_z);
	p.a_coeffs = copy_array(p.a_coeffs, p.degree+1, new_s+1);
	p.degree = new_s;
}

//Main functions
void poly_add( poly_t &p, poly_t const &q ){
	check_null(p);
	check_null(q);
	int max_d = std::max(p.degree, q.degree);
	int min_d = std::min(p.degree, q.degree);
	p.a_coeffs = copy_array(p.a_coeffs, p.degree+1, max_d+1);
	p.degree = max_d;
	for(int x = 0; x <= max_d; x++){
		if(x <= q.degree){
			p.a_coeffs[x] += q.a_coeffs[x];
		}
	}
	clean_coeffs(p);
}
void poly_subtract( poly_t &p, poly_t const &q ){
	check_null(p);
	check_null(q);
	int max_d = std::max(p.degree, q.degree);
	int min_d = std::min(p.degree, q.degree);
	p.a_coeffs = copy_array(p.a_coeffs, p.degree+1, max_d+1);
	p.degree = max_d;
	for(int x = 0; x <= max_d; x++){
		if(x <= q.degree){
			p.a_coeffs[x] -= q.a_coeffs[x];
		}
	}
	clean_coeffs(p);
}
void poly_multiply( poly_t &p, poly_t const &q ){
	check_null(p);
	check_null(q);
	unsigned int new_d = p.degree+q.degree;
	double* new_coeffs = new double[new_d+1]{};
	for(int x = 0; x <= p.degree; x++){
		for(int y = 0; y <= q.degree; y++){
			new_coeffs[x+y] += p.a_coeffs[x]*q.a_coeffs[y];
		}
	}
	delete[] p.a_coeffs;
	p.a_coeffs = new_coeffs;
	p.degree = new_d;
	clean_coeffs(p);
}
double poly_divide( poly_t &p, double r ){
	check_null(p);
	double return_val = poly_val(p, r);
	double* new_coeffs = new double[p.degree]{};
	double net = 0;
	for(int x = p.degree-1; x >= 0; x--){
		new_coeffs[x] = p.a_coeffs[x+1]+net*r;
		net = new_coeffs[x];
	}
	delete [] p.a_coeffs;
	p.a_coeffs = new_coeffs;
	p.degree--;
	clean_coeffs(p);
	return return_val;
}
void poly_diff( poly_t &p ){
	check_null(p);
	if(p.degree >= 1){
		for(int x = 0; x < p.degree; x++){
			p.a_coeffs[x] = p.a_coeffs[x+1]*(x+1);
		}
		p.a_coeffs = copy_array(p.a_coeffs, p.degree+1, p.degree);
		p.degree = p.degree-1;
	}else{
		p.a_coeffs[0] = 0;
	}
}
double poly_approx_int( poly_t const &p, double a, double b, unsigned int n ){
	check_null(p);
	double h = (b-a)/n;
	double integral = poly_val(p, a) + poly_val(p, b);
	for(int k = 1; k < n; k++){
		double xk = a + (k*h);
		integral+=2*poly_val(p, xk);
	}
	integral*= (h/2);
	return integral;
}
