/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:56:12 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/20 17:00:15 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	this->type_ = "cure";
}

Cure::Cure(Cure const & toCopy)
{
	this->type_ = toCopy.type_;
}

Cure::~Cure(void) {}

Cure	&Cure::operator=(Cure const & toCopy)
{
	this->type_ = toCopy.type_;
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria	*ret = new Cure;

	ret->setType(this->type_);
	return (ret);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
