/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:44:36 by jblancha          #+#    #+#             */
/*   Updated: 2017/02/12 20:28:42 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stack.class.hpp"

Stack::Stack(void)
{
}

Stack::~Stack(void)
{
	for (size_t i=0;i<_tab.size();++i)
	{
		delete this->getTop(); 
		this->pop();	
	}
}

Stack::Stack(Stack const &stack)
{
	*this = stack;
}

Stack &Stack::operator=(Stack const &)
{
	return(*this);
}

void Stack::push(IOperand const * iop)
{
	_tab.push_back(iop);
}

IOperand const * Stack::pop(void)
{
	if (this->isEmpty())
		throw(Stack::SizeEmptyException());
	IOperand const * iop = this->getTop();
	_tab.pop_back();
	return(iop);
}

IOperand const * Stack::at(size_t i)
{
	return (_tab.at(i));
}

IOperand const * Stack::getTop(void)
{
	if (this->isEmpty())
		throw(Stack::SizeEmptyException());
	return(_tab.back());
}

bool Stack::isEmpty(void)
{
	return(_tab.empty());
}

size_t Stack::getSize(void)
{
	return(_tab.size());
}

Stack::SizeEmptyException::SizeEmptyException(void)  
{
}

Stack::SizeEmptyException::SizeEmptyException(SizeEmptyException const &Ex)  : AVMException(Ex)
{
		*this = Ex; 
}

Stack::SizeEmptyException &Stack::SizeEmptyException::operator=(SizeEmptyException const &)  
{
		return (*this); 
}

Stack::SizeEmptyException::~SizeEmptyException(void) throw () 
{
}

