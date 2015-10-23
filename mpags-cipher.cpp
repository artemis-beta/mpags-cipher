//! Main implementation of the mpags-cipher program
#include <iostream>
#include <string>
#include <ctype.h>
// This is one of the two valid signatures for main()
int main(int /*argc*/, char* /*argv*/[]) {

  char in_char{'x'};
  std::string result{""};
  
  std::cout << "Enter a number: ";
 
 while(std::cin >> in_char){

	if(isdigit(in_char)){

  		switch (in_char)
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
	
	else if(isalpha(in_char)){
		
		result += toupper(in_char);

	}

	result += ' ';
  }
   std::cout << result << std::endl;
  return 0;
}
