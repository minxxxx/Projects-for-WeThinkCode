/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:30:48 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/23 16:53:29 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_HPP
#define AVM_HPP

#include <iostream>
#include <fstream>
#include "AVMException.hpp"
#include  "Program.class.hpp"
#include  "IOperand.class.hpp"
#include "Stack.class.hpp"

class AVM
{
private:
	static AVM		_instance;
	Program			_program;
	//Lexer			_lexer; singleton!
	//Parser		_parser; singleton!
	Stack			_stack;

	AVM();
	AVM(bool verbose);
	AVM(AVM const&);
	AVM &operator=(AVM const &);



public:
	bool			_verbose;	
	//static const std::string  TYPENAME[];// = { "Int8", "Int16", "Int32", "Float", "Double" };

	static AVM &get(void);
	static bool	verbose(void);

	bool	analyse(std::istream &ifstream, bool verbose, bool terminal);
	bool	run(bool verbose);


	static Program	&prg(void);

	~AVM();


	class AssertFailureException : public AVMException
	{
		std::string _msg;
		public:
		AssertFailureException( const std::string& stackstring, int stacktype, const std::string& assertstring, int comtype);
		AssertFailureException(AssertFailureException const &Ex);
		virtual ~AssertFailureException() throw ();
		AssertFailureException &operator=(AssertFailureException const &);
		virtual const char * what(void) const throw (); //{ return _msg.c_str(); }
	};

	class PrintFailureException : public AVMException
	{
		std::string _msg;
	public:
		PrintFailureException( const std::string& stackstring, int stacktype);
		PrintFailureException(PrintFailureException const &Ex);
		virtual ~PrintFailureException() throw ();
		PrintFailureException &operator=(PrintFailureException const &);
		virtual const char * what(void) const throw (); //{ return _msg.c_str(); }
	};

};

#endif

