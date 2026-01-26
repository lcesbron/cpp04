/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:37:52 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/20 17:09:50 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	this->slot_ = 0;
}

MateriaSource::MateriaSource(MateriaSource const & toCopy)
{
	this->slot_ = 0;
	while (this->slot_ < toCopy.slot_)
	{
		this->inv_[slot_] = toCopy.inv_[slot_]->clone();
		++this->slot_;
	}
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < this->slot_; i++)
	{
		delete this->inv_[i];
	}
}

MateriaSource		&MateriaSource::operator=(MateriaSource const & toCopy)
{
	this->slot_ = 0;
	while (this->slot_ < toCopy.slot_)
	{
		delete this->inv_[slot_];
		this->inv_[slot_] = toCopy.inv_[slot_]->clone();
		++this->slot_;
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria* toLearn)
{
	if (this->isInInv(toLearn))
	{
		return ;
	}
	if (this->slot_ < 4)
	{
		this->inv_[slot_] = toLearn;
		++this->slot_;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->slot_; i++)
	{
		if (this->inv_[i]->getType() == type)
			return (this->inv_[i]->clone());
	}
	return (NULL);
}

bool			MateriaSource::isInInv(AMateria* m) const
{
	for (int i = 0; i < this->slot_; i++)
	{
		if (this->inv_[i] == m)
		{
			return (true);
		}
	}
	return (false);
}
