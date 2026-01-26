/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:17:27 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/20 17:01:44 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void)
{
	this->type_ = "ice";
}

Ice::Ice(Ice const & toCopy)
{
	this->type_ = toCopy.type_;
}

Ice::~Ice(void) {}

Ice	&Ice::operator=(Ice const & toCopy)
{
	this->type_ = toCopy.type_;
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria	*ret = new Ice;

	ret->setType(this->type_);
	return (ret);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
