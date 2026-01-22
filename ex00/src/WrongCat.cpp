/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:43:35 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/19 11:57:03 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "WrongCat " << this->type << " constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &toCopy)
{
	this->type = toCopy.type;
	std::cout << "WrongCat " << this->type << " copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat " << this->type << " destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &toCopy)
{
	this->type = toCopy.type;
	std::cout << "WrongCat " << this->type << " = operator overload called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "wwwww meow" << std::endl;
}
