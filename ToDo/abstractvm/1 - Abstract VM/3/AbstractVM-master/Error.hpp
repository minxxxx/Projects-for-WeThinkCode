/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:05:15 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/17 09:24:07 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

// Nested error handling classes
class Error {
	public:
		Error( void ) {};
		~Error( void ) {};
		class SyntaxError : public std::exception {
			public:
				std::string		e_msg;
				SyntaxError(const std::string& line, const std::string& input);
				virtual const char* what() const throw();
		};
		class OverflowError : public std::exception {
			public:
				std::string		e_msg;
				OverflowError(const std::string& line, const std::string& input);
				virtual const char* what() const throw();
		};
		class UnderflowError : public std::exception {
			public:
				std::string		e_msg;
				UnderflowError(const std::string& line, const std::string& input);
				virtual const char* what() const throw();
		};
		class InstructionError : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class EmptyError : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class ZeroError : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class ExitError : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class AssertError : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class StackSizeError : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NotInt8 : public std::exception {
			public:
				std::string		e_msg;
				NotInt8(const std::string& line, const std::string& input);
				virtual const char* what() const throw();
		};
		virtual const char* what() const throw(); 
};

