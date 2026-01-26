/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:02:47 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/19 12:23:39 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <algorithm>

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &toCopy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	std::copy(toCopy.ideas_, toCopy.ideas_ + 100, this->ideas_);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain	&Brain::operator=(Brain const &toCopy)
{
	std::cout << "Brain = operator overload called" << std::endl;
	if (this == &toCopy)
		return (*this);
	std::copy(toCopy.ideas_, toCopy.ideas_ + 100, this->ideas_);
	return (*this);
}
