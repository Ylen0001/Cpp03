/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:06:13 by ylenoel           #+#    #+#             */
/*   Updated: 2025/03/04 15:10:30 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/colors.hpp"
#include <iostream>	

int main(void)
{
	ScavTrap Scavy("Scavy");
	
	std::cout << C_TEAL;
	std::cout << "Scavy has " << Scavy.get_attackDamage() << " attack damage stat, ";
	std::cout << Scavy.get_energyPoint() << " energy points and " << Scavy.get_hitPoints() <<
	" hit points" << std::endl; 
	Scavy.attack("Roger");
	Scavy.takeDamage(3);
	Scavy.beRepaired(2);
	Scavy.guardGate();
	std::cout << C_RESET;

	return (0);
}