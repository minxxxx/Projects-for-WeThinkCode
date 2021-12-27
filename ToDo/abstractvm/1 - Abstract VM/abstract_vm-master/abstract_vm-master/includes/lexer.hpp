#ifndef LEXER_HPP
# define LEXER_HPP

# include <string>
# include <iostream>
# include <vector>
# include <Token.hpp>

Token getString(std::string str, size_t &i, size_t &lineNumber);
Token getDigit(std::string str, size_t &i, size_t &lineNumber);
Token getOperator(std::string str, size_t &i, size_t &lineNumber);
Token getSeparator(std::string str, size_t &i, size_t &lineNumber);

bool isseparator(char c);
std::vector<Token> lexer(std::string arg, bool & errorOccured);

#endif
