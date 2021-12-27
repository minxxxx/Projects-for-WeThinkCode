/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:03:51 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/12 20:19:39 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_CLASS_HPP
# define STACK_CLASS_HPP

#include "IOperand.class.hpp"
#include "AVMException.hpp"
#include <string>
#include <vector>

class Stack
{
private:

	std::vector<IOperand const *> _tab;

public:
	Stack();
	Stack(Stack const &stack);
	~Stack();
	Stack	&operator=(Stack const &stack);

	void push (IOperand const * iop);
	IOperand const * at (size_t);
	IOperand const * pop (void);
	IOperand const * getTop (void);
	bool isEmpty(void);
	size_t  getSize(void);
	void print (void);

	class SizeEmptyException : public AVMException
	{
	public:
		SizeEmptyException();
		SizeEmptyException(SizeEmptyException const &Ex);
		virtual ~SizeEmptyException() throw ();
		SizeEmptyException &operator=(SizeEmptyException const &);
		virtual const char * what(void) const throw ()
		{
			return "SizeEmpty : Stack is Empty ";
		}
	};

};

#endif
