#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <iostream>

enum class CipherMode {

	Encrypt,
	Decrypt
	
};

enum class CipherType {

	Caesar,
	PlayFair
};

struct CommandLineInfo {

	std::string infile;
	std::string outfile;
	int num_args;
	char in_char;
	char out_char;
	CipherMode ciphermode;
	CipherType ciphertype;
};

bool processCommandLine(char* argv[],CommandLineInfo &info_args);

#endif //MPAGSCIPHER_PROCESSCOMMANDLINE_HPP


