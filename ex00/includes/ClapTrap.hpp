/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:59:49 by ylenoel           #+#    #+#             */
/*   Updated: 2025/03/10 10:01:38 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>
#include <climits>

class ClapTrap
{
	private:

	std::string 			name;
	unsigned int 			hitPoints;
	unsigned int 			energyPoints;
	unsigned int 			attackDamage;

	public:
	
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);

	std::string		get_Name(void) const;
	unsigned int	get_hitPoints(void) const;
	unsigned int	get_energyPoint(void) const;
	unsigned int	get_attackDamage(void) const;
	void			set_Name(const std::string name);
	void			set_hitPoints(const unsigned int hitPoints);
	void			set_energyPoints(const unsigned int energyPoint);
	void			set_attackDamage(const unsigned int attackDamage);
	void 			attack(const std::string& target);
	void 			takeDamage(unsigned int amount);
	void 			beRepaired(unsigned int amount);
	void 			setAttackDamage(unsigned int amount);
};

std::ostream& operator<<(std::ostream& out, const ClapTrap& claptrap);


#endif