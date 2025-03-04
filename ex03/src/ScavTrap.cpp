/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:52:23 by ylenoel           #+#    #+#             */
/*   Updated: 2025/03/04 15:04:15 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/colors.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->set_hitPoints(100);
	this->set_Name(name);
	this->set_attackDamage(20);
	this->set_energyPoints(50);
	std::cout << C_TEAL << "ScavTrap " << this->get_Name() << " is created!" << C_RESET << std::endl; 
}

ScavTrap::~ScavTrap()
{
	std::cout << C_DEEP_RED << "ScavTrap " << this->get_Name() << " is destroyed!" << C_RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy constructor called!" << std::endl;
	this->attackDamage = other.get_attackDamage();
	this->name = other.get_Name();
	this->energyPoints = other.get_energyPoint();
	this->hitPoints = other.get_hitPoints();
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << this->get_Name() << " blasts " << target << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << this->name << " is now in Gate keeper mode!" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const ScavTrap& scavTrap)
{
	out << scavTrap.get_Name() << std::endl;
	out << scavTrap.get_energyPoint() << std::endl;
	out << scavTrap.get_hitPoints() << std::endl;
	out << scavTrap.get_attackDamage() << std::endl;
	return (out);
}