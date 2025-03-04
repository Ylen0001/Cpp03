/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:06:13 by ylenoel           #+#    #+#             */
/*   Updated: 2025/03/04 17:54:46 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"
#include "../includes/colors.hpp"
#include <iostream>	

int main(void)
{
	DiamondTrap Diamond("Diamond");

	Diamond.attack("Enemy");  // Utilise ScavTrap::attack()
	Diamond.whoAmI();  // Affiche ses deux noms
	Diamond.guardGate();  // ScavTrap
	Diamond.highFivesGuys();  // FragTrap
	std::cout << Diamond << std::endl;
	

    return 0;
}