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

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void	testEachAnimal(void)
{
	Animal		a;
	Dog			d;
	Cat			c;
	WrongAnimal	w;
	WrongCat	wc;

	a.makeSound();
	d.makeSound();
	c.makeSound();
	w.makeSound();
	wc.makeSound();
}

static void	testPolymorphism(void)
{
	Animal*	zoo[3];

	zoo[0] = new Animal();
	zoo[1] = new Dog();
	zoo[2] = new Cat();

	for (int i = 0; i < 3; i++)
	{
		zoo[i]->makeSound();
	}
	for (int i = 0; i < 3; i++)
	{
		delete zoo[i];
	}
}

static void	testWrongPolymorphism(void)
{
	WrongAnimal*	zoo[2];

	zoo[0] = new WrongAnimal();
	zoo[1] = new WrongCat();

	for (int i = 0; i < 2; i++)
	{
		zoo[i]->makeSound();
	}
	for (int i = 0; i < 2; i++)
	{
		delete zoo[i];
	}
}

int	main(void)
{
	testEachAnimal();
	testPolymorphism();
	testWrongPolymorphism();
}
