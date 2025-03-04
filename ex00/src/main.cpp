/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:06:13 by ylenoel           #+#    #+#             */
/*   Updated: 2025/03/04 13:34:45 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/colors.hpp"
#include <iostream>	

int main(void)
{
	ClapTrap Clappy;
	ClapTrap Roger("Roger");
	std::cout << C_COLOMBIA_BLUE << std::endl;

	Clappy.attack("Roger");
	Clappy.takeDamage(5);
	std::cout << "Clappy has now : " << Clappy.get_energyPoint() << " energy points available!" << std::endl;
	Clappy.beRepaired(1);
	
	std::cout << C_RESET << C_QUARTZ << std::endl;

	Roger.attack("Clappy");
	Roger.takeDamage(10);
	Roger.beRepaired(8);
	std::cout << C_RESET << std::endl;
	

	return (0);
}