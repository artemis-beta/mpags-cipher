
//**************************************************************************************
//
//			Command Line Input Checking Function
//
//			Kristian Zarebski, October 30th 2015
//
//		Checks user input and also returns help if requested
//
//**************************************************************************************

// Header files

#include <string>
#include <iostream>
#include <stdlib.h>
#include "processCommandLine.hpp"

bool processCommandLine(char* argv[],CommandLineInfo &info_args){


	std::string input{""}, input2{""};	//Strings for arguments

	//Check that an option has been stated when program is initiated
	if(info_args.num_args == 1){std::cout << "ERROR: Program option required, type 'mpags-cipher -h'"\
	" for details \n"; return false;}
	
	input = argv[1]; // Set input to be the value of argument 1

	//Ensure that the first argument is either Code/Decode/Help option
	if(input != "-c" && input != "-d" && input != "-h"){std::cout << "ERROR: Program" \
	" option required, type 'mpags-cipher -h' for details \n"; return false;}

	// Print instructions if 'help' selected as program option
	if(input == "-h" || input == "--help"){ std::cout << "*****************************"\
		"************************************* \n" \
		"\t \t \t CaesarCipher v0.1.7 \t \t \t \n" \
		"****************************************************************** \n \n" \
		" -c \t \t \t Code a Message \n -d \t \t \t Decode a Message \n -h \t \t \t"\
		" Display this help message \n -i \t [filename] \t Use input file for" \
		" message, must be followed by a valid file name \n" \
		" -o \t [filename] \t Specify an output file to print translated text to,"\
		" must be followed by a valid file name \n \n Program requires either '-c',"\
		" '-d' or '-h' flags to work. \n \n"\
		"E.g. 'mpags-cipher -d -i inputfile.txt -o outputfile.txt' \n \n"; exit(0);}

	if(input == "-c"){info_args.ciphermode = CipherMode::Encrypt;}
	else{info_args.ciphermode = CipherMode::Decrypt;}

	// Check if file options selected by user and ensure that where an input/output file
	// has been requested, the user specifies a valid file name (cycles through arguments)

	for(int i{2}; i<info_args.num_args; ++i){
	
		input = argv[i];

		if(i != info_args.num_args-1){input2 = argv[i+1];}

		
		if(input.front() == '-'){if(input != "-o" && input != "-i"){
			std::cout << "ERROR: Invalid argument '" << input << "' \n"; 
			return false;}}
		
		if(input == "--Cipher"){if(i==info_args.num_args-1){
			std::cout << "ERROR: Cipher Type Not Specified! \n";
			return false;}
			else if(input2 == "caesar"){info_args.ciphertype = CipherType::Caesar;}
			else if(input2 == "playfair"){info_args.ciphertype = CipherType::PlayFair;}
			else{std::cout << "ERROR: Invalid Cipher Type! \n"; return false;}
		}

		if(input == "-o"){if(i ==info_args.num_args-1){ 
			std::cout << "ERROR: No Output File Defined! \n";
			return false;}

			else if(input2.front() == '-'){ 
			std::cout << "ERROR: Invalid File Name \n"; return false;}
			info_args.outfile = argv[i+1];
		}
		
		if(input == "-i"){
			if(i == info_args.num_args-1){ 
				std::cout << "ERROR: No Input File Defined! \n"; 
				info_args.infile = input; return false;}

			else if(input2.front() == '-'){ 
				std::cout << "ERROR: Invalid File Name \n"; return false;}
			info_args.infile = argv[i+1];
		
		} 
	}
	return true;
}
