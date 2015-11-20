#ifndef CIPHER_HPP
#define CIPHER_HPP

class Cipher {
	public:
		Cipher() = default;
		Cipher(const Cipher& rhs) = default;
		Cipher(Cipher&& rhs) = default;
		Cipher& operator=(const Cipher& rhs) = default;
		Cipher& operator=(Cipher&& rhs)= default;
		virtual ~Cipher() = default;

		virtual std::string Encrypt(std::string &input_key) = 0;
		virtual std::string Decrypt(std::string &input_key) = 0;


};

#endif 
