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
	std::cout << "Dog " << this->type << " constructor called" << std::endl;
	this->type = "Dog";
	this->brain_ = new Brain;
}

Dog::Dog(Dog const &toCopy)
{
	std::cout << "Dog " << this->type << " copy constructor called" << std::endl;
	this->type = toCopy.type;
	this->brain_ = new Brain;
	*this->brain_ = *toCopy.brain_;
}

Dog::~Dog(void)
{
	std::cout << "Dog " << this->type << " destructor called" << std::endl;
	delete this->brain_;
}

Dog	&Dog::operator=(Dog const &toCopy)
{
	std::cout << "Dog " << this->type << " = operator overload called" << std::endl;
	if (this == &toCopy)
		return (*this);
	this->type = toCopy.type;
	*this->brain_ = *toCopy.brain_;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "woof" << std::endl;
}
