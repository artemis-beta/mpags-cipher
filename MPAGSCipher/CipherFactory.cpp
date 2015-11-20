#include <memory>
#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "PlayFairCipher.hpp"
#include "Cipher.hpp"


std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string &cipher_key)
{

	switch (type) {

		case CipherType::Caesar :
			return std::make_unique<CaesarCipher>(cipher_key);
	
		case CipherType::PlayFair :
			return std::make_unique<PlayFairCipher>(cipher_key);

	}

	return std::unique_ptr<Cipher>(nullptr); 
}

