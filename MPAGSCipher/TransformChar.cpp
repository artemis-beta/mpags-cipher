//*************************************************************************
//
//	Transform Function: takes user input and checks if it is a
//	letter or number, if it is a letter the character is converted to
//	capital, whereas numbers are converted into a name string
//	the result is then returned
//
//*************************************************************************

#include <iostream>
#include "TransformChar.hpp"
#include <cctype>
#include <string>

std::string transformChar(char in_char){

	
	std::string result{""};
					

		if(isdigit(in_char)){			//Check if input is numeric

	  		switch (in_char)		//Convert number to word
	      		{

				case '0':

					result += "ZERO";
					break;

				case '1':
					result += "ONE";
					break;
				case '2':

					result += "TWO";
					break;

				case '3':
					result += "THREE";
					break;
			
				case '4': 
					result += "FOUR";
					break;
			
				case '5':
					result += "FIVE";
					break;

				case '6':
					result += "SIX";
					break;

				case '7':
					result += "SEVEN";
					break;

				case '8':

					result += "EIGHT";
					break;
			
				case '9':

					result += "NINE";
					break;

			
	  		}

		

		}
	
		else if(isalpha(in_char)){		//Check if input is letter and convert to capital
		
			result += toupper(in_char);

		}
		
	return result;		
}
