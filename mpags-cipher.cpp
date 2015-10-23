//********************************************************
//		MPAGS Cipher Code Version 1
//
//	Takes code and converts to capitalised letters
//
//********************************************************

#include <iostream>
#include <string>
#include <ctype.h>
#include <array>
// This is one of the two valid signatures for main()
int main(int argc, char* argv[]) {

  char in_char{'x'}; 				//Define character check variable
  std::string result{""};			//Define Result string for printing
  
  std::cout << "Enter code: ";			//Prompt user for input
 
 while(std::cin >> in_char){			//Repeat conversion until end of input

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

	result += ' ';				
  }
   std::cout << result << "\n";			//Print result to console after 'Ctrl-D' 

   std::cout << "Recorded arguments were: \n";	//Output user arguments 
		for(int i{1}; i<argc; ++i){
			std::cout << "Argument " << i << ": " << argv[i] << "\n";
		}
  return 0;
}
