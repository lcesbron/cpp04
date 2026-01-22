/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:45:16 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/19 11:55:51 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Dog " << this->type << " constructor called" << std::endl;
}

Dog::Dog(Dog const &toCopy)
{
	this->type = toCopy.type;
	std::cout << "Dog " << this->type << " copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog " << this->type << " destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &toCopy)
{
	this->type = toCopy.type;
	std::cout << "Dog " << this->type << " = operator overload called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "woof" << std::endl;
}
