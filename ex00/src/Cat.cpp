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

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat " << this->type << " constructor called" << std::endl;
}

Cat::Cat(Cat const &toCopy)
{
	this->type = toCopy.type;
	std::cout << "Cat " << this->type << " copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat " << this->type << " destructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &toCopy)
{
	this->type = toCopy.type;
	std::cout << "Cat " << this->type << " = operator overload called" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}
