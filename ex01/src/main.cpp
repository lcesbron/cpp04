/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:48:29 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/19 11:51:08 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#ifndef ZOO_SIZE
# define ZOO_SIZE 4
#endif

static void	testDeepCopy(void)
{
	Cat*	c = new Cat();
	Cat*	ccopy = new Cat(*c);
	Dog*	d = new Dog();
	Dog*	dcopy = new Dog(*d);

	delete c;
	delete d;
	delete ccopy;
	delete dcopy;
}

static void testAssignementOperator(void)
{
	Cat	c;
	Cat	c2;

	c2 = c;
}

static void	fill_zoo(Animal **zoo)
{
	for (size_t i = 0; i < ZOO_SIZE; i++)
	{
		if (i % 2)
			zoo[i] = new Cat();
		else
			zoo[i] = new Dog();
	}
}

static void	sing(Animal **zoo)
{
	for (size_t i = 0; i < ZOO_SIZE; i++)
	{
		zoo[i]->makeSound();
	}
}

int	main(void)
{
	Animal*	zoo[ZOO_SIZE];

	testDeepCopy();
	testAssignementOperator();
	fill_zoo(zoo);
	sing(zoo);
	for (size_t i = 0; i < ZOO_SIZE; i++)
		delete zoo[i];
}
