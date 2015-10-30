//**********************************************************************
//			MPAGS Cipher Program v0.1.4
//
//		   Kristian Zarebski, October 30th 2015
//
//		Uses a function definition for code creation
//
//**********************************************************************

// Standard Library includes

#include <iostream>
#include <string>
#include <cctype>
#include "TransformChar.hpp"

int main(int , char**){						// Main function					

	char in_char{'x'};				//Declare Character variable for user input
	std::string result{""};
	std::cout << "Enter code: \n";
	while(std::cin >> in_char){			//Repeat conversion until end of input
		result+=" "+ transformChar(in_char);
	}
	std::cout << result << std::endl;
	return 0;

}
