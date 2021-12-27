#ifndef SYNTAXIC_EXCEPTION_HPP
# define SYNTAXIC_EXCEPTION_HPP

# include <exception>
# include <string>

class SyntaxicException : public std::logic_error
{
private:
	char _what[128];
	SyntaxicException(void);
	SyntaxicException & operator=(SyntaxicException const & rhs);

public:
	~SyntaxicException(void) throw();
	SyntaxicException(const char *what);
	SyntaxicException(std::string const & what);
	SyntaxicException(SyntaxicException const & src);
	const char * what() const throw();
};

#endif
