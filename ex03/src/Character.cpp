/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:25:00 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/20 18:30:33 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	this->name_ = "default_character_name";
	this->slot_ = 0;
}

Character::Character(std::string name)
{
	this->name_ = name;
	this->slot_ = 0;
}

Character::Character(Character const & toCopy)
{
	this->name_ = toCopy.name_;
	this->slot_ = 0;
	while (this->slot_ < toCopy.slot_)
	{
		this->inv_[slot_] = toCopy.inv_[slot_]->clone();
		++this->slot_;
	}
}

Character::~Character(void)
{
	while (this->slot_ >= 1)
	{
		delete this->inv_[slot_ - 1];
		--this->slot_;
	}
}

Character	&Character::operator=(Character const & toCopy)
{
	if (this != &toCopy)
	{
		this->name_ = toCopy.name_;
		while (this->slot_ > 0)
		{
			delete this->inv_[slot_ - 1];
			--this->slot_;
		}
		while (this->slot_ < toCopy.slot_)
		{
			this->inv_[slot_] = toCopy.inv_[slot_]->clone();
			++this->slot_;
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->name_);
}

void Character::equip(AMateria* m)
{
	if (this->slot_ <= 3)
	{
		this->inv_[slot_] = m;
		++slot_;
	}
}

void Character::unequip(int idx)
{
	if (this->slot_ > idx)
	{
		for (int i = idx; i < 3; i++)
		{
			this->inv_[i] = this->inv_[i + 1];
		}
		--this->slot_;
	}
}

AMateria*	Character::unequipSavePointer(int idx)
{
	AMateria*	ret;

	if (this->slot_ > idx)
	{
		ret = this->inv_[idx];
		this->unequip(idx);
		return (ret);
	}
	return (NULL);
}

void Character::use(int idx, ICharacter& target)
{
	this->inv_[idx]->use(target);
}
