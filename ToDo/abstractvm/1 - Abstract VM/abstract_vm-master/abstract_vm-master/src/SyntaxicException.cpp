#include <SyntaxicException.hpp>
#include <iostream>

SyntaxicException::~SyntaxicException(void) throw()
{
}

SyntaxicException & SyntaxicException::operator=(SyntaxicException const & rhs)
{
	memcpy(_what, rhs._what, sizeof(_what));
	return *this;
}

SyntaxicException::SyntaxicException() : std::logic_error("Not defined"), _what("Not defined")
{
}

SyntaxicException::SyntaxicException(const char *what) : std::logic_error(what)
{
	strncpy(_what, what, sizeof(_what) - 1);
}

SyntaxicException::SyntaxicException(std::string const & what) : std::logic_error(what)
{
	strncpy(_what, what.c_str(), sizeof(_what) - 1);
}

const char * SyntaxicException::what() const throw()
{
	return _what;
}
