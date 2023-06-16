#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{

}

ScavTrap::~ScavTrap(void)
{

}

ScavTrap::ScavTrap(const ScavTrap& other)
{

}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{

}

ScavTrap::ScavTrap(const std::string& name)
	:	ClapTrap(name)
	,	_hitPoints(100)
	,	_energyPoints(50)
	,	_attackDamage(20)
{
	std::cout << "String constructor is called. \"I'm ScavTrap. My name is " << _name << "\"" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{

}

void	ScavTrap::takeDamage(unsigned int amount)
{

}

void	ScavTrap::beRepaired(unsigned int amount)
{

}

