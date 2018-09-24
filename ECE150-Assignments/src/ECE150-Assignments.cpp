//============================================================================
// Name        : ECE150-Assignments.cpp
// Author      : Kunal Chandan
// Version     : 1.0
// Description : Assignment 1 ECE 150
//============================================================================

#include <iostream>
int main();
void question1();
void question2();
int days_in_week();
void question4();
void question5();
void question6();
void question7();
void question8();
void question9();
void question10();
void question11();
void question12();
void question13_14();
void question15();
void question16();
void question17();
void question18();
void question19_20(double x);
void y(double x, double y, double z);
void question22();
void question23();
void question24();
void question25();
void question26();

void question1(){
	std::cout << "Favorite course after week 1 is ECE 105 classical mechanics" << std::endl;
}
void question2(){
	std::cout <<
			"The compiler is essentially stating that the "
			"functions for outputting to the screen is not "
			"available, and cannot be found in the currently "
			"available functions" << std::endl;
}
int days_in_week(){
	// Question 3
	std::cout << "7 days in a week.";
	std::cout << std::endl;
	return 0;
}
void question4(){
	std::cout << "The functions will be executed in the order:\n"
			"statement_2()\n"
			"statement_1()\n"
			"statement_4()\n"
			"statement_3()\n"
			"statement_5()\n" << std::endl;
}
void question5(){
	std::cout << "The function declaration states to the compiler "
			"that such a function exists. Whereas with the function "
			"definition, the function contains a block of statements" << std::endl;
}
void question6(){
	std::cout << "The five categories of literal data are:\n"
			"ints -> integer values 29\n"
			"floats -> real numbers 2.718\n"
			"boolean -> true false things\n"
			"characters -> for example 's' \n"
			"strings -> \"this\" \n" << std::endl;
}
void question7(){
	std::cout << "\\\\\'\"" << std::endl;
}
void question8(){
	std::cout << "endl ensures that across Windows and Unix systems the "
			"correct line ending and line beginning characters are used." << std::endl;
}
void question9(){
	std::string matrix[3][3]{
	{std::string{"A"},std::string{"1"},std::string{"\\"}},
	{std::string{"Hgah"},std::string{"3"},std::string{"150"}},
	{std::string{"\"x\""},std::string{"b"},std::string{"D"}}};
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			std::cout << matrix[x][y] << "\t";
		}
		std::cout << std::endl;
	}
}
void question10(){
	std::cout << "You cannot use keyword identifiers to define the "
			"identifier of a function. These are reserved special "
			"sequences for the compiler" << std::endl;
}
void question11(){
	std::cout <<
			"_Aa0_0 \n"
			"_0_0" << std::endl;
}
void question12(){
	std::cout << "12" << std::endl;
	std::cout << "10" << std::endl;
	std::cout << "10" << std::endl;
}
void question13_14(){
	int m{3};
	int x{4};
	int b{5};
	std::cout << "The output of mx+b is: " << (m*x)+b << std::endl;
}
void question15(){
	std::cout << "The third one, and the fifth one are correct" << std::endl;
}
void question16(){
	double pi = 3.1415926537;
	double radius = 5.3;
	std::cout << "Diameter: \t" << 2*radius <<"\n"
			  << "Circumference: \t" << pi*radius*2<<"\n"
			  << "Area: \t" << pi*radius*radius <<std::endl;
}
void question17(){
	std::cout << "o + o + o + o +" << std::endl;
	std::cout << "+ o + o + o + o" << std::endl;
	std::cout << "o + o + o + o +" << std::endl;
	std::cout << "+ o + o + o + o" << std::endl;
	std::cout << "o + o + o + o +" << std::endl;
	std::cout << "+ o + o + o + o" << std::endl;
	std::cout << "o + o + o + o +" << std::endl;
}
void question18(){
	bool flip = true;
	for(int x = 0; x < 7; x++){
		for(int y = 0; y < 8; y++){
			if(flip){
				std::cout << "o ";
			}else{
				std::cout << "+ ";
			}
			flip =! flip;
		}
		flip =! flip;
		std::cout << std::endl;
	}
}
void question19_20(double x){
	double m = 2.34;
	double b = 532.2;
	std::cout << m*x + b << std::endl;
}
void y(double m, double x, double b){
	std::cout << m*x + b << std::endl;
}
void question22(){
	std::cout << "O Elberth ";
	std::cout << "Gilthoniel,";
	std::cout << std::endl;
	std::cout << "o menel palandiriel,";
	std::cout << std::endl;
	std::cout << "le nallon si di'nguruthos!";
	std::cout << std::endl;
	std::cout << "A trio non, Fanuilos!";
	std::cout << std::endl;
}
void question23(){
	std::cout << "The space allows for the next "
			"word to be printed with a space between "
			"them, since it's not automatically inserted"
			<< std::endl;
}
void question24(){
	std::cout << "It moves the printer to the next line." << std::endl;
}
void question25(){
	std::cout << (2+35+320+1+5+32+9)/7 << std::endl;
}
void question26(){
	std::cout << (2+35+320+1+5+32.00+9)/7 << std::endl;
	std::cout << "The difference is that since the "
			"32.00 is recognized as a floating point "
			"number all the other numbers are upcasted "
			"to floating point numbers and the average "
			"is thusly calculated." << std::endl;
}
int main() {
	question1();
	question2();
	days_in_week();// Question 3
	question4();
	question5();
	question6();
	question7();
	question8();
	question9();
	question10();
	question11();
	question12();
	question13_14();
	question15();
	question16();
	question17();
	question18();
	question19_20(1.2243);
	y(1.0,2.0,3.0);
	question22();
	question23();
	question24();
	question25();
	question26();
	return 0;
}
