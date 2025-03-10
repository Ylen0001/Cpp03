/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:13:11 by ylenoel           #+#    #+#             */
/*   Updated: 2025/03/10 11:25:37 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/DiamondTrap.hpp"
#include "../includes/colors.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default"), ScavTrap("Default"), FragTrap("Default"), name("Default")
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;

	std::cout << C_PASTEL_BLUE "Default constructor called!" C_RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name(name)
{
	this->hitPoints = FragTrap::hitPoints;
	this->set_energyPoints(50);
	this->attackDamage = FragTrap::attackDamage;

	std::cout << C_PASTEL_BLUE "DiamondTrap " << this->name << " is born!" << C_RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << C_BRIGHT_RED "DiamondTrap destructor called!" C_RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	std::cout << C_PASTEL_BLUE "DiamondTrap copy constructor called!" C_RESET << std::endl;
	this->name = other.name;
	this->energyPoints = other.energyPoints;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << C_PASTEL_BLUE "DiamondTrap copy assignement called!" C_RESET << std::endl;
	this->attackDamage = other.get_attackDamage();
	this->energyPoints = other.get_energyPoint();
	this->hitPoints = other.get_hitPoints();
	this->name = other.get_Name();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const DiamondTrap& DiamondTrap)
{
	out << DiamondTrap.get_Name() << std::endl;
	out << DiamondTrap.get_energyPoint() << std::endl;
	out << DiamondTrap.get_hitPoints() << std::endl;
	out << DiamondTrap.get_attackDamage() << std::endl;
	return (out);
}

std::string DiamondTrap::get_Name() const
{
	return this->name;
}

void DiamondTrap::whoAmI()
{
	std::cout << C_PASTEL_BLUE "I am " << this->name << " and my ClapTrap name is " << this->ClapTrap::get_Name() << "!" C_RESET << std::endl;
}