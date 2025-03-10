/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:06:13 by ylenoel           #+#    #+#             */
/*   Updated: 2025/03/10 11:17:20 by ylenoel          ###   ########.fr       */
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

	DiamondTrap Roger;
	
	std::cout << "Roger's name pre copy assignement : " << Roger.get_Name() << std::endl;
	Roger = Diamond;
	std::cout << "Roger's name post copy assignement : " << Roger.get_Name() << std::endl;
	
	DiamondTrap Martin(Diamond);
	std::cout << "Copy of Diamond via copy constructor : " << Martin.get_Name() << std::endl;
	Diamond.attack("Enemy");  // Utilise ScavTrap::attack()
	Diamond.whoAmI();  // Affiche ses deux noms
	Diamond.guardGate();  // ScavTrap
	Diamond.highFivesGuys();  // FragTrap
	std::cout << Diamond << std::endl;
	

    return 0;
}