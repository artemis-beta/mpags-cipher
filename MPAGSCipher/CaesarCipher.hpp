#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <cctype>
#include <vector>

class CaesarCipher{

public:
	CaesarCipher(int &cipher_key);
	void Encrypt();
	void Decrypt();
	std::string outputstring_{""};
	std::string inputstring_{""};

private:
	int key_{0};
	const std::vector<char> alphabet_{'A','B','C','D','E','F','G','H','I','J','K','L','M',\
			'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	

};

#endif //MPAGSCIPHER_CAESARCIPHER_HPP
