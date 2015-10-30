//**********************************************************************
//			MPAGS Cipher Program v0.1.4
//
//		   Kristian Zarebski, October 30th 2015
//
//		Uses a function definition for code creation
//
//**********************************************************************

#include <iostream>
#include <string>

std::string transformChar(char in_char); 		//Declare Code Creation Function

int main(){						// Main function					

	char in_char{'x'};				//Declare Character variable for user input
	std::string result{""};
	std::cout << "Enter code: \n";
	while(std::cin >> in_char){			//Repeat conversion until end of input
		result+=" "+ transformChar(in_char);
	}
	std::cout << result << std::endl;
	return 0;

}

//*************************************************************************
//
//	Transform Function: takes user input and checks if it is a
//	letter or number, if it is a letter the character is converted to
//	capital, whereas numbers are converted into a name string
//	the result is then returned
//
//*************************************************************************

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
