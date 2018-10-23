//============================================================================
// Name        : Intervals.cpp
// Author      : Kunal Chandan
// Version     :
// Copyright   : 
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <limits>

//FUNCTIONS
void interval_calculator();
void initoppCMDmap();
void clear_input();
bool does_opp_exist(std::string input);
std::vector<double> placeInput(int num);
std::vector<double> sort_vector(std::vector<double> vect);
void call_function(std::string oppCMD, std::vector<double> inputs);
void print_vector(std::vector<double> vect);
void error_interval(std::vector<double> inputs);


//GLOBAL VARIABLES
std::map<std::string, int> oppCMDmap;
std::vector<double> im_interval;
std::vector<double> me_interval;

//Program
void error_interval(std::vector<double> inputs){
	std::cout << "Error: invalid interval as "
			  << inputs[0]
			  << " > "
			  << inputs[1]
			  << std::endl;

}

std::vector<double> sort_vector(std::vector<double> vect){
	std::sort(vect.begin(), vect.end());
	return vect;
}

void print_vector(std::vector<double> vect){
	if(!vect.empty()){
		std::cout << "[";
		for(uint x = 0; x < vect.size(); x++){
			std::cout << vect[x];
			if(x != vect.size()-1){
				 std::cout << ", ";
			}
		}
		std::cout << "]" << std::endl;
	}
	else{
		std::cout << "--" << std::endl;
	}
}

void enter(std::vector<double> inputs){
	if(inputs[0] > inputs[1]){
		error_interval(inputs);
	}
	else{
		im_interval.assign(inputs.begin(),inputs.end());
	}
}
void exit(){
	std::cout << "Bye bye: Terminating interval calculator program." << std::endl;
}
void negate(){
	im_interval[0] = -im_interval[0];
	im_interval[1] = -im_interval[1];
	im_interval = sort_vector(im_interval);
}
void invert(){
	if((im_interval[0] == 0) || (im_interval[1] == 0) || (im_interval[0] <= 0 && im_interval[1] >= 0)){
		std::cout << "Error: division by zero" << std::endl;
		im_interval.clear();
	}
	else{
		im_interval[0] = 1/im_interval[0];
		im_interval[1] = 1/im_interval[1];
		im_interval = sort_vector(im_interval);
	}
}
void ms(){
	me_interval.assign(im_interval.begin(), im_interval.end());
}
void mr(){
	if(!me_interval.empty()){
		im_interval.assign(me_interval.begin(), im_interval.end());
	}
}
void mc(){
	me_interval.clear();
}
void mp(){
	if(!me_interval.empty()){
		for(uint x = 0; x < me_interval.size(); x++){
			me_interval[x]+=im_interval[x];
		}
	}
}
void mm(){
	if(!me_interval.empty()){
		for(uint x = 0; x < me_interval.size(); x++){
			me_interval[x]-=im_interval[x];
		}
	}
}
void scalar_add(std::vector<double> input){
	for(uint x = 0; x < im_interval.size(); x++){
		im_interval[x]+=input[0];
	}
}
void scalar_subtract(std::vector<double> input){
	for(uint x = 0; x < im_interval.size(); x++){
		im_interval[x]-=input[0];
	}
}
void scalar_multiply(std::vector<double> input){
		for(uint x = 0; x < im_interval.size(); x++){
			im_interval[x]*=input[0];
		}
		im_interval = sort_vector(im_interval);
}
void scalar_divide(std::vector<double> input){
	if(input[0] == 0){
		std::cout << "Error: division by zero" << std::endl;
		im_interval.clear();
	}
	else{
		for(uint x = 0; x < im_interval.size(); x++){
			im_interval[x]/=input[0];
		}
		im_interval = sort_vector(im_interval);
	}
}
void scalar_divided_by(std::vector<double> input){
	if((im_interval[0] == 0) || (im_interval[1] == 0) || (im_interval[0] <= 0 && im_interval[1] >= 0)){
		std::cout << "Error: division by zero" << std::endl;
		im_interval.clear();
	}
	else{
		for(uint x = 0; x < im_interval.size(); x++){
			im_interval[x]=input[0]/im_interval[x];
		}
		im_interval = sort_vector(im_interval);
	}

}
void interval_add(std::vector<double> inputs){
	if(inputs[0] > inputs[1]){
		error_interval(inputs);
	}
	else{
		if(!im_interval.empty() && inputs[0] <= inputs[1]){
			for(uint x = 0; x < im_interval.size(); x++){
				im_interval[x]+=inputs[x];
			}
		}
		else if(inputs[0] > inputs[1]){
			error_interval(inputs);
		}
	}
}
void interval_subtract(std::vector<double> inputs){
	if(inputs[0] > inputs[1]){
		error_interval(inputs);
	}
	else{
		if(inputs[0] <= inputs[1]){
			for(uint x = 0; x < im_interval.size(); x++){
				im_interval[x]-=inputs[x];
			}
		}
		else{
			error_interval(inputs);
		}
	}
}
void interval_multiply(std::vector<double> inputs){
	if(inputs[0] > inputs[1]){
		error_interval(inputs);
	}
	else{
		std::vector<double> tempA;
		tempA.assign(im_interval.begin(), im_interval.end());
		std::vector<double> tempB;
		tempB.assign(im_interval.begin(), im_interval.end());
		for(uint x = 0; x < im_interval.size(); x++){
			tempA[x]*=inputs[x];
			tempB[x]*=inputs[im_interval.size()-(x+1)];
		}
		im_interval.clear();
		im_interval.insert(im_interval.end(), tempA.begin(), tempA.end());
		im_interval.insert(im_interval.end(), tempB.begin(), tempB.end());
		im_interval = sort_vector(im_interval);
		im_interval.erase(im_interval.begin()+1, im_interval.end()-1);
	}
}
void interval_divide(std::vector<double> inputs){
	if(inputs[0] > inputs[1]){
		error_interval(inputs);
	}
	else if((inputs[0] == 0) || (inputs[1] == 0) || (inputs[0] <= 0 && inputs[1] >= 0)){
		std::cout << "Error: division by zero" << std::endl;
		im_interval.clear();
	}
	else{
		std::vector<double> tempA;
		tempA.assign(im_interval.begin(), im_interval.end());
		std::vector<double> tempB;
		tempB.assign(im_interval.begin(), im_interval.end());
		for(uint x = 0; x < im_interval.size(); x++){
			tempA[x]/=inputs[x];
			tempB[x]/=inputs[im_interval.size()-(x+1)];
		}
		im_interval.clear();
		im_interval.insert(im_interval.end(), tempA.begin(), tempA.end());
		im_interval.insert(im_interval.end(), tempB.begin(), tempB.end());
		im_interval = sort_vector(im_interval);
		im_interval.erase(im_interval.begin()+1, im_interval.end()-1);
	}
}
void intersect(std::vector<double> inputs){
	if(inputs[0] > inputs[1]){
		error_interval(inputs);
	}
	else{
		if(std::min(inputs[1], im_interval[1]) >= std::max(inputs[0], im_interval[0])){
			im_interval[1] = std::min(inputs[1], im_interval[1]);
			im_interval[0] = std::max(inputs[0], im_interval[0]);
		}
		else{
			im_interval.clear();
		}
	}
}
void integers(){
	std::vector<int> integers;
	for(int x = std::ceil(im_interval[0]); x <= std::floor(im_interval[1]); x++){
		integers.push_back(x);
	}
	for(uint x = 0; x < integers.size(); x++){
		std::cout << integers[x];
		if(x < integers.size()-1){
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}
void cartesian_integers(std::vector<double> inputs){
	if(inputs[0] <= inputs[1]){
		std::vector<int> i;
		std::vector<int> j;
		for(int x = std::ceil(im_interval[0]); x <= std::floor(im_interval[1]); x++){
			i.push_back(x);
		}
		for(int x = std::ceil(inputs[0]); x <= std::floor(inputs[1]); x++){
			j.push_back(x);
		}
		bool run = false;
		for(uint y = 0; y < i.size(); y++){
			for(uint x = 0; x < j.size(); x++){
				std::cout << "(" << i[y] << "," << j[x] << ")";
				if(x+y < j.size()+i.size()-2){
					std::cout << ", ";
				}
				run = true;
			}
		}
		if(run){
			std::cout << std::endl;
		}
	}
	else{
		error_interval(inputs);
	}
}

void call_function(std::string oppCMD, std::vector<double> inputs){
	if(oppCMD == "exit"){
		exit();
	}else if( oppCMD == "enter"){
		enter(inputs);
	}else if( oppCMD == "negate"){
		negate();
	}else if( oppCMD == "invert"){
		invert();
	}else if( oppCMD == "ms"){
		ms();
	}else if( oppCMD == "mr"){
		mr();
	}else if( oppCMD == "mc"){
		mc();
	}else if( oppCMD == "m+"){
		mp();
	}else if( oppCMD == "m-"){
		mm();
	}else if( oppCMD == "scalar_add"){
		scalar_add(inputs);
	}else if( oppCMD == "scalar_subtract"){
		scalar_subtract(inputs);
	}else if( oppCMD == "scalar_multiply"){
		scalar_multiply(inputs);
	}else if( oppCMD == "scalar_divide"){
		scalar_divide(inputs);
	}else if( oppCMD == "scalar_divided_by"){
		scalar_divided_by(inputs);
	}else if( oppCMD == "interval_add"){
		interval_add(inputs);
	}else if( oppCMD == "interval_subtract"){
		interval_subtract(inputs);
	}else if( oppCMD == "interval_multiply"){
		interval_multiply(inputs);
	}else if( oppCMD == "interval_divide"){
		interval_divide(inputs);
	}else if( oppCMD == "intersect"){
		intersect(inputs);
	}else if( oppCMD == "integers"){
		integers();
	}else if( oppCMD == "cartesian_integers"){
		cartesian_integers(inputs);
	}
}

std::vector<double> placeInput(int num){
	std::vector<double> banana;
	for(int x = 0; x < num; x++){
		double temp;
		if(std::cin >> temp){}
		else{
			std::cout << "Error: illegal command" << std::endl;
			clear_input();
			break;
		}
		banana.push_back(temp);
	}
	return banana;
}

void clear_input(){
	std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void initoppCMDmap(){
	oppCMDmap["exit"]               = -1;
	oppCMDmap["enter"]              =  2;
	oppCMDmap["negate"]             =  0;
	oppCMDmap["invert"]             =  0;
	oppCMDmap["ms"]                 =  0;
	oppCMDmap["mr"]                 =  0;
	oppCMDmap["mc"]                 =  0;
	oppCMDmap["m+"]                 =  0;
	oppCMDmap["m-"]                 =  0;
	oppCMDmap["scalar_add"]         =  1;
	oppCMDmap["scalar_subtract"]    =  1;
	oppCMDmap["scalar_multiply"]    =  1;
	oppCMDmap["scalar_divide"]      =  1;
	oppCMDmap["scalar_divided_by"]  =  1;
	oppCMDmap["interval_add"]       =  2;
	oppCMDmap["interval_subtract"]  =  2;
	oppCMDmap["interval_multiply"]  =  2;
	oppCMDmap["interval_divide"]    =  2;
	oppCMDmap["intersect"]          =  2;
	oppCMDmap["integers"]           =  0;
	oppCMDmap["cartesian_integers"] =  2;
}

bool does_opp_exist(std::string input) {
	auto search = oppCMDmap.find(input);
	if(search == oppCMDmap.end()){
		return false;
	}
	return true;
}

void interval_calculator() {
	bool key = true;

	while (key) {
		////////
		START://START
		////////
		std::cout << "input :> ";
		// TAKE INPUT
		std::string oppCMD;
		std::cin >> oppCMD;
		// VERIFY INPUT
		if (!does_opp_exist(oppCMD)) {
			std::cout << "Error: illegal OPP command" << std::endl;
			clear_input();
			goto START;// or use continue;
		}
		//START OPERATIONS
		int num_nums = oppCMDmap[oppCMD];
		if(num_nums == -1){//QUIT
			key = false;
			exit();
			break;
		}
		std::vector<double> inputs = placeInput(num_nums);

		if(im_interval.empty() && oppCMD != "enter"){
			print_vector(im_interval);
		}
		else{
			call_function(oppCMD, inputs);
			print_vector(im_interval);
		}
	}
}

int main() {
	initoppCMDmap();
	interval_calculator();
	return 0;
}
