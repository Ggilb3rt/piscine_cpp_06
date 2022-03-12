#include "Literal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Literal::Literal() : _stringLiteral("Nope"), _doubleLiteral(0.0), _type("Nope")
{
	return ;
}

Literal::Literal(std::string src) : _stringLiteral(src)
{
	this->_doubleLiteral = std::strtod(this->_stringLiteral.c_str(), NULL);
	this->setType();
	return ;
}

Literal::Literal( const Literal & src ) : _stringLiteral(src.getStringLiteral())
{
	*this = src;
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Literal::~Literal()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Literal &				Literal::operator=( Literal const & rhs )
{
	if ( this != &rhs )
	{
		//this->_stringLiteral = rhs.getStringLiteral();
		this->_type = rhs.getType();
		this->_doubleLiteral = rhs.getDoubleLiteral();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool			Literal::isChar() const {
	if (this->_stringLiteral.length() == 1
		&& std::isprint(this->_stringLiteral.c_str()[0]))
		return true;
	return false;
}

bool 			Literal::isInt() const {
	std::istringstream	iss(this->getStringLiteral());
	int					i;

	iss >> std::noskipws >> i;
	return iss.eof() && !iss.fail();
}

bool 			Literal::isFloat() const {
	std::istringstream	iss(this->getStringLiteral());
	float				f;

	iss >> std::noskipws >> f;
	return iss.eof() && !iss.fail();
}

bool 			Literal::isDouble() const {
	std::istringstream	iss(this->getStringLiteral());
	double				d;

	iss >> std::noskipws >> d;
	return iss.eof() && !iss.fail();
}

void			Literal::printChar() const {
	std::cout << "char: ";
	try
	{
		this->getCastChar();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return ;
	}
	std::cout << "'" << this->getCastChar() << "'" << std::endl;
}

void		Literal::printInt() const {
	std::cout << "int: ";
	try
	{
		std::cout << this->getCastInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void		Literal::printFloat() const {
	double		intPart;
	float		nb = this->getCastFloat();
	std::string	suffixe;
	
	suffixe = std::modf(nb, &intPart) != 0 ? "f" : ".0f";
	if (intPart == HUGE_VAL || intPart == -HUGE_VAL)
		suffixe = "f";

	std::cout << "float: " << nb << suffixe << std::endl;
}

void		Literal::printDouble() const {
	double		intPart;
	double		fractPart;
	double		nb = this->getCastDouble();
	std::string	suffixe;
	
	fractPart = std::modf(nb, &intPart);
	suffixe = fractPart != 0 ? "" : ".0";
	if (intPart == HUGE_VAL || intPart == -HUGE_VAL)
		suffixe = "";
	if (fractPart == 0 && this->getStringLiteral().find("e+") != std::string::npos)
		suffixe = "";
	std::cout << "double: " << nb << suffixe << std::endl;
}

void			Literal::printAll() const {
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string		Literal::getStringLiteral() const {
	return this->_stringLiteral;	
}

std::string		Literal::getType() const {
	return this->_type;	
}

double			Literal::getDoubleLiteral() const {
	return this->_doubleLiteral;
}

char			Literal::getCastChar() const {
	char	c; 
	
	if (this->getType() != TYPE_CHAR)
		c = static_cast<char>(this->getDoubleLiteral());
	else
		c = this->getStringLiteral().c_str()[0];
	if (std::isprint(c))
		return c;
	else if (c == 0 && !this->isChar())
		throw ImpossiblePrintErrorException();
	else
		throw NonPrintErrorException();
}

int				Literal::getCastInt() const {
	if (this->getDoubleLiteral() > INT_MAX
		|| this->getDoubleLiteral() < INT_MIN
		|| this->getStringLiteral() == "nan"
		|| this->getStringLiteral() == "nanf")
		throw ImpossiblePrintErrorException();
	return static_cast<int>(this->getDoubleLiteral());
}

float			Literal::getCastFloat() const {
	return static_cast<float>(this->getDoubleLiteral());
}

double			Literal::getCastDouble() const {
	return	this->getDoubleLiteral();
}



void			Literal::setType() {
	bool const		isDouble = this->isDouble();
	bool const		isFloat = this->isFloat();
	bool const		isInt = this->isInt();
	bool const		isChar = this->isChar();

	if (isChar)
		this->_type = TYPE_CHAR;
	if (isInt)
		this->_type = TYPE_INT;
	if (isFloat)
		this->_type = TYPE_FLOAT;
	if (isDouble)
		this->_type = TYPE_DOUBLE;
	if (!isChar && !isInt && !isFloat && !isDouble)
		this->_type = TYPE_NONE;
}

/* ************************************************************************** */