//*****************************************************************************
//
//				PlayFairCipher Function
//			Kristian Zarebski, October 30th 2015
//
//   Based on the PlayFair Cipher encryption.
//
//*****************************************************************************

#include <cctype>
#include <iostream>
#include "PlayFairCipher.hpp"
#include <vector>
#include <algorithm>
#include <iterator>


PlayFairCipher::PlayFairCipher(const std::string &cipher_key) : key_{0}{ key_ = cipher_key;}

void PlayFairCipher::setKey(std::string key){

	// Store the original key
	key_ = toupper(key);

	// Append the alphabet
	
	std::vector <char>::iterator rm_symb, diff;
	const std::vector<char> alphabet{'A','B','C','D','E','F','G','H','I','J','K','L','M',\
			'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	std::vector<char> grid = alphabet;
	std::transform(key.begin(), key.end(), key.begin(), ::toupper);
	std::vector<char> key_vec(key.begin(), key.end());

	// Remove elements from key that are non-alpha and create a new vector from the result

	rm_symb = std::remove_if(key_vec.begin(), key_vec.end(),[](char i){return !isalpha(i);});
	std::cout << std::endl << std::endl;
	key_vec.erase(rm_symb, key_vec.end());
	for(int k{0}; k<key_vec.size(); ++k){if(key_vec[k]=='J'){key_vec[k] = 'I';} std::cout << key_vec[k];}

	for (std::vector<char>::iterator dup = key_vec.begin(); dup != key_vec.end(); ++dup) 
key_vec.erase(std::remove(dup + 1, key_vec.end(), *dup), key_vec.end());

	// Add the remainder of the alphabet to the end of the array


	
	for(int k{0}; k<key_vec.size(); ++k){ diff = std::remove(grid.begin(), grid.end(), key_vec[k]);}

	grid.insert(grid.begin(), key_vec.begin(), key_vec.end());

	// Print the grid

	grid.resize(26);
	for(int k{0}; k<grid.size(); ++k){std::cout << grid[k] << std::endl;}

	// Store the coords for each letter
	// Store the playfair cipher key map

}
void PlayFairCipher::Encrypt(std::string &input_string){

input_string_ = input_string;
// Make sure input is valid
// (Upper case, only chars and add an X
// Find repeated chars and add an X
// if the size is odd, add a trailing Z
// Loop over the input in the Digraphs
// Find the coords in the grid for each digraph
// For each Digraph, decide how to encrypt 
// return the text
return input;
}
void PlayFairCipher::Decrypt(std::string &input_string){

input_string_ = input_string;

}

