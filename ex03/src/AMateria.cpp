/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:06:22 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/20 16:07:25 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	this->type_ = "default_type";
}

AMateria::AMateria(std::string const & type): type_(type) {}

AMateria::AMateria(AMateria const &toCopy) {(void)toCopy;}

AMateria::~AMateria(void) {}

AMateria	&AMateria::operator=(AMateria const &toCopy) {(void)toCopy; return (*this);}

std::string const & AMateria::getType() const
{
	return (this->type_);
}

void	AMateria::setType(std::string const & newType)
{
	this->type_ = newType;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "Default Materia usage on " << target.getName() << std::endl;
}
