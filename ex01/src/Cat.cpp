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
	std::cout << "Cat " << this->type << " constructor called" << std::endl;
	this->type = "Cat";
	this->brain_ = new Brain;
}

Cat::Cat(Cat const &toCopy)
{
	std::cout << "Cat " << this->type << " copy constructor called" << std::endl;
	this->type = toCopy.type;
	this->brain_ = new Brain;
	*this->brain_ = *toCopy.brain_;
}

Cat::~Cat(void)
{
	std::cout << "Cat " << this->type << " destructor called" << std::endl;
	delete this->brain_;
}

Cat	&Cat::operator=(Cat const &toCopy)
{
	std::cout << "Cat " << this->type << " = operator overload called" << std::endl;
	if (this == &toCopy)
		return (*this);
	this->type = toCopy.type;
	*this->brain_ = *toCopy.brain_;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}
