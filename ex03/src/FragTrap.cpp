/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:13:09 by ylenoel           #+#    #+#             */
/*   Updated: 2025/03/04 15:49:59 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include "../includes/colors.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->set_Name(name);
	this->set_attackDamage(30);
	this->set_energyPoints(100);
	this->set_hitPoints(100);
	std::cout << C_PASTEL_PURPLE << "FragTrap " << this->get_Name() << " appears!" << C_RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << C_DEEP_RED << "FragTrap " <<  this->name << " exploded!" << C_RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Copy constructor called!" << std::endl;
	this->attackDamage = other.get_attackDamage();
	this->energyPoints = other.get_energyPoint();
	this->hitPoints = other.get_hitPoints();
	this->name = other.get_Name();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const FragTrap& FragTrap)
{
	out << FragTrap.get_Name() << std::endl;
	out << FragTrap.get_energyPoint() << std::endl;
	out << FragTrap.get_hitPoints() << std::endl;
	out << FragTrap.get_attackDamage() << std::endl;
	return (out);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << C_PASTEL_PURPLE << "Heeey guys, high fiveeeees !" << C_RESET << std::endl;
}