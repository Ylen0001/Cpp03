/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:14:11 by ylenoel           #+#    #+#             */
/*   Updated: 2025/03/04 15:02:37 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/colors.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Default Clappy"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << C_COLOMBIA_BLUE << name << " constructor called !" << C_RESET << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << C_DUSTY_RED "Default destructor called !" C_RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << C_QUARTZ << "ClapTrap " << this->name << " is created!" << C_RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy constructor called!" << std::endl;
	this->attackDamage = other.get_attackDamage();
	this->name = other.get_Name();
	this->energyPoints = other.get_energyPoint();
	this->hitPoints = other.get_hitPoints();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const ClapTrap& claptrap)
{
	out << claptrap.get_Name() << std::endl;
	out << claptrap.get_energyPoint() << std::endl;
	out << claptrap.get_hitPoints() << std::endl;
	out << claptrap.get_attackDamage() << std::endl;
	return (out);
}

/* GETTERS */

std::string	ClapTrap::get_Name(void) const
{
	return (this->name);
}

unsigned int ClapTrap::get_hitPoints(void) const
{
	return(this->hitPoints);	
}

unsigned int	ClapTrap::get_energyPoint(void) const
{
	return(this->energyPoints);	
}

unsigned int	ClapTrap::get_attackDamage(void) const
{
	return(this->attackDamage);
}

/* SETTERS */

void ClapTrap::set_Name(const std::string name)
{
	this->name = name;
}

void ClapTrap::set_hitPoints(const unsigned int hitPoints)
{
	this->hitPoints = hitPoints;
}

void ClapTrap::set_energyPoints(const unsigned int energyPoints)
{
	this->energyPoints = energyPoints;
}

void ClapTrap::set_attackDamage(const unsigned int attackDamage)
{
	this->attackDamage = attackDamage;
}

/* Members functions */

void ClapTrap::attack(const std::string& target)
{
	if(energyPoints > 0)
	{
		energyPoints -= 1;
		std::cout << name << " attacks " << target << 
		", causing " << attackDamage << " points of damage!" << 
		std::endl; 
	}
	else
	{
		std::cout << "ClapTrap's discharged. Can't attack !" << std::endl;
	}
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << name << " took " << amount << " damages!" << std::endl;
	if(hitPoints - amount <= 0)
	{
		std::cout << "ClapTrap's out! He needs to repair!" << std::endl;
		hitPoints = 0;
	}
	else
		hitPoints -= amount;
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(energyPoints <= 0)
	{
		std::cout << name << " has no energy left to repair himself!" << std::endl; 
	}
	else
	{
		energyPoints -= 1;
		if(hitPoints + amount >= INT_MAX)
		{
			std::cout << "Overflow! " << name << "'s overcharged and could explode if he heals himself now!" << std::endl;
			return;
		}
		hitPoints += amount;
		std::cout << name << " is healing himself for " << amount << " hit points!" << std::endl;
		std::cout << "He has now " << hitPoints << " Hit Points left!" << std::endl;
	}
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	if(amount < UINT_MAX)
	{
		attackDamage = amount;
		std::cout << name << " has found a new weapon! Upgrading his damages to " << attackDamage << std::endl;
	}
	else
	{
		std::cout << "This new weapon is too heavy to handle! Poor Claptrap can't hold it !" << std::endl;
	}
}