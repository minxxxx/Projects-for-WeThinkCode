/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:03:51 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/23 17:01:29 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKCOM_CLASS_HPP
# define STACKCOM_CLASS_HPP

#include "IOperand.class.hpp"
#include "AVMException.hpp"
#include "Stack.class.hpp"
#include <string>
#include <iostream>
#include <stack>
#include <vector>

typedef struct s_command
{
	std::string         commande;
	std::string			strvalue;
	long double         operand;
	t_precision         precision;
}               t_command;

class Program
{
private:

	std::vector<t_command>  _tab;
	bool					_verbose;
	Program(Program const &);
	Program &operator=(Program const &);

public :
	Program();
	~Program();
	
	bool 		isEmpty(void) const;
	size_t  	getSize(void) const;
	void 		print (void) const;
	bool 		verify (void) const;
	//bool		run(Stack const &stack); must be here
	bool		run(bool verbose, Stack &stack);

	void 		push (t_command iop);
	t_command &	last(void);
	t_command &	at(size_t i);


	class SizeEmptyException : public AVMException
	{
		public:
			SizeEmptyException();
			SizeEmptyException(SizeEmptyException const &);
			virtual ~SizeEmptyException() throw ();
			SizeEmptyException &operator=(SizeEmptyException const &);
			virtual const char * what(void) const throw ();
	};

	class NoExitException : public AVMException
	{
		public:
			NoExitException();
			NoExitException(NoExitException const &Ex);
			virtual ~NoExitException() throw ();
			NoExitException &operator=(NoExitException const &);
			virtual const char * what(void) const throw ();
	};

	class InvalidIndexException : public AVMException
	{
		public:
			InvalidIndexException();
			InvalidIndexException(InvalidIndexException const &Ex);
			virtual ~InvalidIndexException() throw ();
			InvalidIndexException &operator=(InvalidIndexException const &);
			virtual const char * what(void) const throw ();
	};
	class NotInt8Exception : public AVMException
	{
		std::string _msg;
		public:
				NotInt8Exception(std::string const & stackstring, int stacktype);
				NotInt8Exception(NotInt8Exception const &Ex);
				virtual ~NotInt8Exception() throw ();
				NotInt8Exception &operator=(NotInt8Exception const &);
				virtual const char * what(void) const throw() ;
	};
};

#endif
