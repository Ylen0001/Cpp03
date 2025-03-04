/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:44:50 by ylenoel           #+#    #+#             */
/*   Updated: 2025/03/04 16:31:36 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:

	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& other);


	void attack(const std::string& target);
	void guardGate();
	
};

std::ostream& operator<<(std::ostream& out, const ScavTrap& scavTrap);



#endif