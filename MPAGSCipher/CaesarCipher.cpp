//*****************************************************************************
//
//				CaesarCipher Function
//			Kristian Zarebski, October 30th 2015
//
//   Based on the Caesar Cipher encryption, takes a character and performs
//   a translation along the alphabet to encode a message, the translation
//   being taken as the cipher key. Can code/decode based on selected option
//
//*****************************************************************************

#include <cctype>
#include <iostream>

char CaesarCipher(int cipher_key, char cipher_input, std::string option){

	// Alphabet array
	char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',\
			'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	cipher_input = toupper(cipher_input); //Convert all input into capitals


	//Compare character with array elements until a match is found, based
	//on the program option selected either perform encryption or decryption
	//by moving across the array elements and returning the result.
	//Program also accounts for cipher_keys larger than array size, performing
	//a wrap if needed

	for(int i{0}; i<= 25; ++i){

		if(cipher_input == alphabet[i]){	

			if(option == "-c"){
				cipher_input = alphabet[(i+cipher_key) % 26];
				return cipher_input;}

			if(option == "-d"){
		
				cipher_key = cipher_key % 26;
			
				if((i-cipher_key) < 0){ 
				
				cipher_input = alphabet[26-abs(i-cipher_key)];}

				else{cipher_input = alphabet[i-cipher_key];}
			
				return cipher_input;
				
			}
	
		}

	}

	// If special non alphabet character used (e.g. '?') don't change
	return cipher_input;  
}
