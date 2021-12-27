#ifndef PARSER_HPP
# define PARSER_HPP

# include <Token.hpp>
# include <Instruction.hpp>
# include <SyntaxicException.hpp>
# include <vector>
# include <map>
# include <eOperandType.hpp>
# include <OperandFactory.hpp>

enum eParserState {
	Start, // Just after a separator
	ExpectingValue, // after a push or an assert.
	ExpectingOpeningBracket,
	ExpectingRelativeNumber,
	ExpectingDecimalNumber,
	ExpectingClosingBracket,
	ExpectingSeparator
};

class Parser {

public:
	Parser(std::vector<Token> const & tokens);
	std::vector<Instruction> getInstructions(bool & errorOccured);

	Parser(void);
	Parser(Parser const & src);
	~Parser(void);

	void setToken(std::vector<Token> const & tokens);

	Parser & operator=(Parser const & rhs);

private:

	static std::map<eParserState, void (Parser::*)(void)> _stateMap;
	static std::map<eInstructionType, eOperandType> _typeMap;

	std::vector<Token> _tokens;
	eParserState _state;
	std::vector<Token>::iterator	_iterator;
	std::vector<Token>::iterator	_currentInstructionSpecifier;
	std::vector<Token>::iterator	_currentTypeSpecifier;
	std::vector<Token>::iterator	_currentContentSpecifier;
	std::vector<Instruction> _instructions;
	OperandFactory operandFactory;


	void	stateStart(void);
	void	stateExpectingValue(void);
	void	stateExpectingOpeningBracket(void);
	void	stateExpectingRelativeNumber(void);
	void	stateExpectingDecimalNumber(void);
	void	stateExpectingClosingBracket(void);
	void	stateExpectingSeparator(void);

	eOperandType	instructionToOperand(eInstructionType);

	const IOperand	*createCurrentOperand(); // _iterator must be on desired content iterator.
};

#endif
