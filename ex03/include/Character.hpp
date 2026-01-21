/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:19:42 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/20 14:32:16 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		AMateria*	inv_[4];
		int			slot_;
		std::string	name_;
	public:
		Character(void);
		Character(std::string name);
		Character(Character const & toCopy);
		virtual ~Character();
		Character	&operator=(Character const & toCopy);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		AMateria*	unequipSavePointer(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
