/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:42:52 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/19 11:51:01 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain	*brain_;
	public:
		Cat(void);
		Cat(Cat const &toCopy);
		Cat	&operator=(Cat const &toCopy);
		~Cat(void);
		void	makeSound(void) const;
};

#endif
