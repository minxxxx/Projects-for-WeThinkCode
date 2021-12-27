#include <lexer.hpp>
#include <LexicalException.hpp>

Token getString(std::string str, size_t &i, size_t &lineNumber)
{
	size_t		start;
	std::string content;

	start = i;
	while (i < str.length() && (isdigit(str[i]) || isalpha(str[i])))
		i++;
	content = str.substr(start, i - start);
	Token ret(TOK_STRING, content, lineNumber);
	i--;
	return ret;
}

Token getOperator(std::string str, size_t &i, size_t &lineNumber)
{
	Token ret(TOK_OPERATOR, std::string(1, str[i]), lineNumber);
	return ret;
}

Token getSeparator(std::string str, size_t &i, size_t &lineNumber)
{
	size_t	start;
	std::string	content;

	start = i;
	while (i < str.length() && isseparator(str[i]))
	{
		if (str[i] == '\n')
			lineNumber++;
		i++;
	}
	content = str.substr(start, i - start);
	i--;
	return Token(TOK_SEP, content, lineNumber);
}

Token getDigit(std::string str, size_t &i, size_t &lineNumber)
{
	size_t		start;
	std::string	content;
	bool	minusOk = true;
	Token	ret;
	bool	dotSeen = false;
	int		dotOk = 0;
	/*
		Values for dotOk :
			0 : when before the dot and before first digit. Pass to 1 when first digit is read.
			1 : After the first digit when a dot is ok.
			2 : After the dot has been read.
	*/

	start = i;

	while (i < str.length())
	{
		if (str[i] == '-')
		{
			if (minusOk == false)
				throw LexicalException("Malformed number around char [" + std::string(1, str[i]) + "] on line " + std::to_string(lineNumber));
			else
				minusOk = false;
		}
		else if (str[i] == '.')
		{
			if (dotOk == 0 || dotOk == 2)
				throw LexicalException("Malformed number around char [" + std::string(1, str[i]) + "] on line " + std::to_string(lineNumber));
			else
				dotOk = 2;
			dotSeen = true;
		}
		else if (isdigit(str[i]))
		{
			if (dotOk == 0)
				dotOk = 1;
			minusOk = false;
		}
		else
			break;
		i++;
	}
	if (dotOk == 0 || (dotSeen && dotOk == 1))
		throw LexicalException("Malformed number around char [" + std::string(1, str[i]) + "] on line " + std::to_string(lineNumber));
	content = str.substr(start, i - start);
	if (dotOk == 1)
		ret = Token(TOK_INTEGER, content, lineNumber);
	else
		ret = Token(TOK_REAL, content, lineNumber);
	i--;
	return ret;
}
