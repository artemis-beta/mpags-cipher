//**********************************************************************
//			MPAGS Cipher Program v0.1.7
//
//		   Kristian Zarebski, October 30th 2015
//
//		Based around the Caesar Cipher concept of translating
//		by a fixed value the characters of the alphabet
//
//**********************************************************************

// Standard Library includes

#include <iostream>
#include <string>
#include <cctype>
#include "TransformChar.hpp"
#include "processCommandLine.hpp"
#include "CaesarCipher.hpp"
#include "PlayFairCipher.hpp"
#include "CipherFactory.hpp"
#include <fstream>

int main(int argc, char* argv[]){		// Main function with user arguments 		
	//std::string info_input.infile{""};			// Set string for input file name
	//std::string outfile{""};		// Set string for output file name
	std::string option{""};			// Set string for code/decode options	
	std::ofstream output_file;		// outfile stream for Output File
	std::ifstream input_file;		// infile stream for Input File
	//char in_char{'x'};			// Character variable for user input
	//char out_char{'y'};			// Character variable for conversion output
	std::string input_key{""};			// Integer for translation - cipher key
	std::string result{""}; 		// String for final result
	std::string input_string{""};

	CipherMode select{CipherMode::Encrypt};
	CipherType type{CipherType::Caesar};
	CommandLineInfo info_input{"","",argc,'x','y',select,type};


	// Following function checks the arguments provided when initiating the program
					
	bool checkCommandLine = processCommandLine(argv,info_input);

	if(checkCommandLine == false){ return 1; }


	option = argv[1];	// Take the first argument to be the specifier for Code/Decode

	output_file.open(info_input.outfile);	//open output file
	input_file.open(info_input.infile);	//open input file
	

	// Checks performed to ensure that if an output/input file name has been specified, the file
	// has opened successfully

	if(info_input.outfile != ""){bool output_check = output_file.good();

		std::cout << "Setting output file to: " << info_input.outfile << std::endl;

		if(output_check == false){ std::cout << "Error reading output file \n"; return 1;}

	}
	if(info_input.infile != ""){bool input_check = input_file.good();

		std::cout << "Setting input file to: " << info_input.infile << std::endl;

		if(input_check == false){ std::cout << "Error reading input file \n"; return 1;}

	}

	// State if user has selected Code/Decode function depending on the 'option' arg. provided

	if(info_input.ciphermode == CipherMode::Encrypt){std::cout << "MESSAGE CODER \n \n";}
	else{std::cout << "MESSAGE DECODER \n \n";}

	// Request cipher key before proceeding checking it is a valid integer
	std::cout << "Enter Cipher Key for Caesar Cipher: ";
	while(!(std::cin >> input_key)){std::cout << "INVALID INPUT: Enter an integer \n"; 
	std::cin.clear(); std::cin.ignore(275, '\n');}


	// Taking the message input for the cipher as being either a text file (if input file declared) 
	// or user input depending on the presence of the input file argument. 
	// Then performs the CaesarCipher operation on individual characters of the input.


	auto aCipher = cipherFactory( info_input.ciphertype, input_key );

	if(info_input.infile != ""){

		if(info_input.ciphermode == CipherMode::Encrypt){
			std::cout << "Input type set to 'file'\n";		
			while(std::getline(input_file, input_string)){

						result = aCipher->Encrypt(input_string);
			}
		}
		else{
			std::cout << "Input type set to 'file'\n";		
			while(std::getline(input_file, input_string)){

						result = aCipher->Decrypt(input_string);
			}
		}
	}
	else{
		std::cout << "\n Input type set to 'user'\n";
		std::cout << "\n Enter Message for Caesar Cipher: ";
		std::cin >> input_string;

		if(info_input.ciphermode == CipherMode::Encrypt){
				result = aCipher->Encrypt(input_string);
		}
		else{
				result = aCipher->Decrypt(input_string);
		}
	}
	std::cout << std::endl << result << std::endl;	// Print the converted string to the terminal
	output_file <<result << std::endl;		// If an output file is declared
							// also print this result to the file

	output_file.close();				// Close output file to ensure no data loss
	input_file.close();				// Close input file
	return 0;
}
