/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:50:54 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/20 14:48:45 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type_;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const &toCopy);
		virtual ~AMateria(void);
		AMateria			&operator=(AMateria const &toCopy);
		std::string 		const & getType() const; //Returns the materia type
		void				setType(std::string const & newType);
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
