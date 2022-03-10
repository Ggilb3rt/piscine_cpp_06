#include <iostream>
#include <sstream>
#include <string>
#include "Literal.hpp"

void	checkBasics(int ac, char** av) {
	if (ac != 2)
		throw "Bad number of arguments";
	if (ac > 1)
		if (!strcmp(av[1], ""))
			throw "Argument is empty";
	return ;
}

bool isFloat( std::string myString ) {
    std::istringstream iss(myString);
    float f;
    iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail(); 
}

int main( int ac, char** av) {
	try
	{
		checkBasics(ac, av);
	}
	catch(const char* e)
	{
		std::cerr << e << std::endl;
		return 0;
	}

	std::string			sav = static_cast<std::string>(av[1]);
	Literal			input(sav);

	std::cout << "is float " << isFloat(sav) << std::endl;

	std::cout << "Type id : " << input.getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Char: ";
	try
	{
		input.getChar();
		std::cout << "'" << input.getChar() << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout
				<< "Int: " << input.getInt() << std::endl
				<< "Float: " << input.getFloat() << "f" << std::endl
				<< "Double: " << input.getDouble() << std::endl;
	std::cout << std::endl;
	
	return 0;
}