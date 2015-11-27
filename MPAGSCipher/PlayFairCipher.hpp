#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include <cctype>
#include <vector>
#include "Cipher.hpp"

class PlayFairCipher : public Cipher {

public:
	PlayFairCipher(const std::string &cipher_key);
	void setKey(std::string key);
	virtual std::string Encrypt(std::string &input_string) override;
	virtual std::string Decrypt(std::string &input_string) override;
	std::string outputstring_{""};
	std::string inputstring_{""};

private:
	std::string key_{""};
	const std::vector<char> alphabet_{'A','B','C','D','E','F','G','H','I','J','K','L','M',\
			'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	

};

#endif //MPAGSCIPHER_PLAYFAIRCIPHER_HPP
