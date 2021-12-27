#include <Token.hpp>

std::string Token::_enumStr[TOK_SIZEOFENUM] = {
   "string",
   "integer",
   "real",
   "operator",
   "separator"
};

std::map<const std::string, eInstructionType> Token::_typeMap =
{
	{"push", Push},
	{"pop", Pop},
	{"dump", Dump},
	{"assert", Assert},
	{"add", Add},
	{"sub", Sub},
	{"mul", Mul},
	{"div", Div},
	{"mod", Mod},
	{"print", Print},
	{"exit", Exit},
	{"int8", TypeInt8},
	{"int16", TypeInt16},
	{"int32", TypeInt32},
	{"float", TypeFloat},
	{"double", TypeDouble},
};


Token::Token(void)
{
}

Token::Token(eTokenType type, size_t lineNumber) : _type(type), _lineNumber(lineNumber)
{
}

Token::Token(eTokenType type, std::string content, size_t lineNumber) : _type(type), _content(content), _lineNumber(lineNumber)
{
}


Token::Token(Token const & src) : _type(src._type), _content(src._content), _lineNumber(src._lineNumber)
{
}

Token::~Token(void)
{
}

Token & Token::operator=(Token const & rhs)
{
	_type = rhs._type;
	_content = rhs._content;
	_lineNumber = rhs._lineNumber;
	return *this;
}

void		Token::setContent(std::string content)
{
	_content = content;
}

eTokenType	Token::getType(void) const
{
	return _type;
}

size_t		Token::getLine(void) const
{
	return _lineNumber;
}

std::string	Token::getTypeAsStr(void) const
{
	return _enumStr[_type];
}

void		Token::setType(eTokenType type)
{
	_type = type;
}

std::string const & Token::getContent(void) const
{
	return _content;
}

eInstructionType Token::getInstructionType(void) const
{
	std::map<const std::string, eInstructionType>::iterator elem;

	elem = _typeMap.find(_content);
	if (elem == _typeMap.end())
		return Undefined;
	else
		return elem->second;
}
