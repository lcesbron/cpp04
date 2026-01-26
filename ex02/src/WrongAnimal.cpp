/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:21:30 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/19 11:55:40 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
{
	this->type = "default_Wronganimal";
	std::cout << "WrongAnimal " << this->type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &toCopy)
{
	this->type = toCopy.type;
	std::cout << "WrongAnimal " << this->type << " copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal " << this->type << " destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &toCopy)
{
	this->type = toCopy.type;
	std::cout << "WrongAnimal " << this->type << " = operator overload called" << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WWWWWWWWWWWWWWWW" << std::endl;
}
