#ifndef RUNTIME_EXCEPTION_HPP
# define RUNTIME_EXCEPTION_HPP

# include <exception>
# include <string>

class RuntimeException : public std::runtime_error
{
private:
	char _what[128];
	RuntimeException(void);
	RuntimeException & operator=(RuntimeException const & rhs);

public:
	~RuntimeException(void) throw();
	RuntimeException(const char *what);
	RuntimeException(std::string const & what);
	RuntimeException(RuntimeException const & src);
	const char * what() const throw();
};

#endif
