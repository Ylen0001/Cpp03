/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:11:56 by ylenoel           #+#    #+#             */
/*   Updated: 2025/03/04 18:02:38 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:

	std::string name;
	
	public:

	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap& other);

	void whoAmI();
	using ScavTrap::attack;
	std::string get_Name() const; // Overriding of ClapTrap::get_Name
};

std::ostream& operator<<(std::ostream& out, const DiamondTrap& DiamondTrap);

#endif