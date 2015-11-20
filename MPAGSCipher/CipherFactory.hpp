#ifndef CIPHER_FACTORY_HPP
#define CIPHER_FACTORY_HPP

#include <memory>
#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "PlayFairCipher.hpp"
#include "Cipher.hpp"

enum CipherType {

	Caesar,
	PlayFair
};

std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string &cipher_key);

#endif
