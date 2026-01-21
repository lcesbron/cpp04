/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:54:06 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/20 14:31:40 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & toCopy);
		~Cure(void);
		Cure	&operator=(Cure const & toCopy);
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
