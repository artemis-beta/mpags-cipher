
//**************************************************************************************
//
//			Command Line Input Checking Function
//
//			Kristian Zarebski, October 30th 2015
//
//		Checks user input and also returns help if requested
//
//**************************************************************************************

#include <string>
#include <iostream>

bool processCommandLine(int argc, char* argv[], std::string &infile, std::string &outfile){


	std::string input{""}, input2{""};

	if(argc == 1){return true;}

	for(int i{1}; i<argc; ++i){
	
		input = argv[i];

		if(i != argc-1){input2 = argv[i+1];}

		if(input.front() == '-'){if(input != "-h" && input != "-o" && input != "-i"){std::cout << "ERROR: Invalid argument '" << input << "' \n"; return false;}}

		if(input == "-h" || input == "--help"){ std::cout << "HAHA you need help! \n"; }
		
		if(input == "-o"){if(i == argc){ std::cout << "ERROR: No Output File Defined! \n"; outfile = input;  return false;}

		else if(input2.front() == '-'){ std::cout << "ERROR: Invalid File Name \n"; return false;}
		}
		
		if(input == "-i"){if(i == argc){ std::cout << "ERROR: No Input File Defined! \n"; infile = input; return false;}

		else if(input2.front() == '-'){ std::cout << "ERROR: Invalid File Name \n"; return false;}	
		
		} 
	}
	return true;
}
