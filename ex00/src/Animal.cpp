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

#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "default_animal";
	std::cout << "Animal " << this->type << " constructor called" << std::endl;
}

Animal::Animal(Animal const &toCopy)
{
	this->type = toCopy.type;
	std::cout << "Animal " << this->type << " copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal " << this->type << " destructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &toCopy)
{
	this->type = toCopy.type;
	std::cout << "Animal " << this->type << " = operator overload called" << std::endl;
	return (*this);
}

void	Animal::makeSound(void)
{
	std::cout << "AAAAAAAAAAAA" << std::endl;
}
