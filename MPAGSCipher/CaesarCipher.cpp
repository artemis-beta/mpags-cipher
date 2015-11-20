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
#include "CaesarCipher.hpp"


CaesarCipher::CaesarCipher(const std::string &cipher_key) : key_{0}{ key_ = std::stoi(cipher_key);}
std::string CaesarCipher::Encrypt(std::string &inputstring){

	inputstring_=inputstring;

	for(int j{0}; j < int(inputstring_.size()); ++j){

		for(int i{0}; i<= 25; ++i){

			std::cout << "Output: " << inputstring_[j] << "\t" << alphabet_[i] <<std::endl;

			if(toupper(inputstring_[j]) == alphabet_[i]){


				inputstring_[j] = alphabet_[(i+key_) % 26];

				outputstring_ = inputstring_; 
				break;
			}
	
		}	
	}
	outputstring_ = inputstring_;
	return outputstring_;
}
std::string CaesarCipher::Decrypt(std::string &inputstring){

	inputstring_ = inputstring;

	for(int j{0}; j < int(inputstring_.size()); ++j){

		for(int i{0}; i<= 25; ++i){

			std::cout << "Output: " << inputstring_[j] << "\t" << alphabet_[i] <<std::endl;

			if(toupper(inputstring_[j]) == alphabet_[i]){

				key_ = key_ % 26;
			
				if((i-key_) < 0){ 
				
					inputstring_[j] = alphabet_[26-abs(i-key_)]; outputstring_ = inputstring_; break;}


				else{inputstring_[j] = alphabet_[i-key_]; outputstring_ = inputstring_; break;}
			
			}
		}
	}
	return outputstring_;
}
