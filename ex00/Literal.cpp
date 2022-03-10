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
char			Literal::getChar() const {
	char	c; 
	
	if (this->getType() != TYPE_CHAR)
		c = static_cast<char>(this->getDoubleLiteral());
	else
		c = this->getStringLiteral().c_str()[0];
	if (std::isprint(c))
		return c;
	else
		throw NonPrintErrorException();
}

int				Literal::getInt() const {
	return static_cast<int>(this->getDoubleLiteral());
}

float			Literal::getFloat() const {
	return static_cast<float>(this->getDoubleLiteral());
}

double			Literal::getDouble() const {
	return	this->getDoubleLiteral();
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

void			Literal::setType() {
	// char
	// int
	// float
	// double
	if (this->_stringLiteral.length() == 1 && std::isprint(this->_stringLiteral.c_str()[0]))
	{
		this->_type = TYPE_CHAR;

	}
	else
		this->_type = TYPE_NONE;
}

/* ************************************************************************** */