#ifndef LITERAL_HPP
# define LITERAL_HPP

# include <iostream>
# include <string>

#define TYPE_CHAR "Char"
#define TYPE_INT "Int"
#define TYPE_FLOAT "Float"
#define TYPE_DOUBLE "Double"
#define TYPE_NONE "None"

class Literal
{

	public:

		Literal();
		Literal(std::string src);
		Literal( Literal const & src );
		~Literal();

		std::string		getStringLiteral() const;
		std::string		getType() const;
		double			getDoubleLiteral() const;
		void			setType();
		char			getChar() const;
		int				getInt() const;
		float			getFloat() const;
		double			getDouble() const;

		Literal &		operator=( Literal const & rhs );

		class	CastErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw() {return ("Can't cast");}
		};
		class	NonPrintErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw() {return ("non printable");}
		};

	private:
		std::string	const	_stringLiteral;
		double				_doubleLiteral;
		std::string			_type;
};


#endif /* ********************************************************* LITERAL_H */