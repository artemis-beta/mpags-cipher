//! Main implementation of the mpags-cipher program
#include <iostream>
#include <string>
// This is one of the two valid signatures for main()
int main(int /*argc*/, char* /*argv*/[]) {

	int a{10}, e{11};
	const double b{334.567};
	int c{b};
	auto d{true};
	std::string f{"BOOM"};	

	char g{f[2]};

	a = 20;

	std::cout << "Hello World! \n";
	std::cout << "The integer value you arbitrarily picked to state is: " << a << std::endl;
	std::cout << "The non random number of the day is: " << b << std::endl;
	std::cout << "Divide a double by an int and you get: " << b/a << std::endl;
	std::cout << "DON'T divide an int by an int: " << a/e << " <- loss of precision!" << std::endl;
	std::cout << "Life is pretty " << f << std::endl;
	std::cout << "Not so random character is '" << g << "' \n";
	return 0;
}
