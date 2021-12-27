#ifndef LEXICAL_EXCEPTION_HPP
# define LEXICAL_EXCEPTION_HPP

# include <exception>
# include <string>

class LexicalException : public std::logic_error
{
private:
	char _what[128];
	LexicalException(void);
	LexicalException & operator=(LexicalException const & rhs);

public:
	~LexicalException(void) throw();
	LexicalException(const char *what);
	LexicalException(std::string const & what);
	LexicalException(LexicalException const & src);
	const char * what() const throw();
};

#endif
