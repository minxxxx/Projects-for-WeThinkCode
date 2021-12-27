#include <Parser.hpp>
#include <LexicalException.hpp>
#include <RuntimeException.hpp>

std::map<eParserState, void (Parser::*)(void)> Parser::_stateMap =
{
	{Start, &Parser::stateStart},
	{ExpectingValue, &Parser::stateExpectingValue},
	{ExpectingOpeningBracket, &Parser::stateExpectingOpeningBracket},
	{ExpectingRelativeNumber, &Parser::stateExpectingRelativeNumber},
	{ExpectingDecimalNumber, &Parser::stateExpectingDecimalNumber},
	{ExpectingClosingBracket, &Parser::stateExpectingClosingBracket},
	{ExpectingSeparator, &Parser::stateExpectingSeparator}
};

std::map<eInstructionType, eOperandType> Parser::_typeMap
{
	{TypeInt8, OperandTypeInt8},
	{TypeInt16, OperandTypeInt16},
	{TypeInt32, OperandTypeInt32},
	{TypeFloat, OperandTypeFloat},
	{TypeDouble, OperandTypeDouble}
};


Parser::Parser(std::vector<Token> const & tokens) : _tokens(tokens), _state(Start)
{
}

std::vector<Instruction>	Parser::getInstructions(bool & errorOccured)
{
	/*
		Create an instruction list from the tokens.
	*/
	_iterator = _tokens.begin();
	bool	printed_err_message = false;


	while (_iterator != _tokens.end())
	{
		std::map<eParserState, void (Parser::*)(void)>::iterator it;

		it = _stateMap.find(_state);
		if (it == _stateMap.end())
			throw SyntaxicException("Didn't expect this state !");
		else
		{
			try {
				(this->*(it->second))();
			} catch (const SyntaxicException & e) {
				if (printed_err_message == false)
				{
					std::cout << "Parser error(s) : " << std::endl;
					printed_err_message = true;
				}
				errorOccured = true;
				std::cout << '\t' << e.what() << std::endl;
				while (_iterator != _tokens.end() && _iterator + 1 != _tokens.end() && _iterator->getType() != TOK_SEP)
					_iterator++;
				_state = Start;
			} catch (const RuntimeException & e) {
				if (printed_err_message == false)
				{
					std::cout << "Parser error(s) : " << std::endl;
					printed_err_message = true;
				}
				errorOccured = true;
				std::cout << '\t' << e.what() << std::endl;
				while (_iterator != _tokens.end() && _iterator + 1 != _tokens.end() && _iterator->getType() != TOK_SEP)
					_iterator++;
				_state = Start;
			}
		}
		_iterator++;
	}

	try {
		std::vector<Instruction>::iterator it2 = _instructions.begin();
		while (it2 != _instructions.end())
		{
			if (it2->getType() == Exit)
				return _instructions;
			it2++;
		}
		throw SyntaxicException("Expected an exit instruction in the program.");
	} catch (const SyntaxicException & e) {
		if (printed_err_message == false)
		{
			std::cout << "Parser error : " << std::endl;
			printed_err_message = true;
		}
		std::cout << '\t' << e.what() << std::endl;
		errorOccured = true;
		throw SyntaxicException("Why would you print this ?");
	}
}

Parser::Parser(void)
{
	_state = Start;
}

void Parser::setToken(std::vector<Token> const & tokens)
{
	_tokens = tokens;
}

Parser::Parser(Parser const & src)
{
	*this = src;
}

Parser::~Parser(void)
{
}

Parser & Parser::operator=(Parser const & rhs)
{
	_tokens = rhs._tokens;
	_state = rhs._state;
	return *this;
}

eOperandType	Parser::instructionToOperand(eInstructionType src)
{
	std::map<eInstructionType, eOperandType>::iterator it;

	it = _typeMap.find(src);
	if (it != _typeMap.end())
		return it->second;
	throw SyntaxicException("Error !");
}

const IOperand	*Parser::createCurrentOperand()
{
	const IOperand			*operand;
	eInstructionType		instructionType;
	eOperandType			operandType;

	instructionType = _currentTypeSpecifier->getInstructionType();
	operandType = instructionToOperand(instructionType);
	operand = operandFactory.createOperand(operandType, _iterator->getContent());

	return operand;
}
