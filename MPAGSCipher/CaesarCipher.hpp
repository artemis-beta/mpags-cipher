#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <cctype>
#include <vector>
#include "Cipher.hpp"

class CaesarCipher : public Cipher {

public:
	CaesarCipher(const std::string &cipher_key);
	virtual std::string Encrypt(std::string &input_string) override;
	virtual std::string Decrypt(std::string &input_string) override;
	std::string outputstring_{""};
	std::string inputstring_{""};

private:
	int key_{0};
	const std::vector<char> alphabet_{'A','B','C','D','E','F','G','H','I','J','K','L','M',\
			'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	

};

#endif //MPAGSCIPHER_CAESARCIPHER_HPP
