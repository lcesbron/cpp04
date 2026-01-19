/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:21:00 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/19 11:50:54 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*brain_;
	public:
		Dog(void);
		Dog(Dog const &toCopy);
		Dog	&operator=(Dog const &toCopy);
		~Dog(void);
		void	makeSound(void) const;
};

#endif
