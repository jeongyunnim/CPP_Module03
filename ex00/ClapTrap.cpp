#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	:	_name("* NONE *")
	,	_hitPoints(10)
	,	_energyPoints(10)
	,	_attackDamage(0)
{
	std::cout << "Defalt Constructor is called. ClapTrap's name set to \"* None *\"" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	:	_name(name)
	,	_hitPoints(10)
	,	_energyPoints(10)
	,	_attackDamage(0)
{
	std::cout << "String constructor is called. He said, \"Helloooo I'm ClapTrap call me " << _name << "\"" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "Assignment operator called.\nname: " << _name << " -> " << rhs._name \
				<< "\nhit points: " << _hitPoints << " -> " << rhs._hitPoints \
				<< "\nenergy points: " << _energyPoints << " -> " << rhs._energyPoints \
				<< "\nattack damage: " << _attackDamage << " -> " << rhs._attackDamage << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	:	_name(other._name)
	,	_hitPoints(other._hitPoints)
	,	_energyPoints(other._energyPoints)
	,	_attackDamage(other._attackDamage)
{
	std::cout << "Copy constructor is called. He said, \"Helloooo I'm ClapTrap!! call me " << _name << "\"" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor is called. <ClapTrap> Shut down the system" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << "points of damage!" << " He said, \"I'm sorry\" "<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints - amount > 0)
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << "points of damage!" << "Now, Claptrap's HP is" << _hitPoints << " He said, \"Ooooch!!\""<< std::endl;
	}
	else
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " lose all of hit points.." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints - amount > 0)
	{
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repairs " << amount << "points!" << "Now, Claptrap's HP is" << _hitPoints << " He said, \"I'm back!\""<< std::endl;
	}
	else
	{
		std::cout << "Not enough energy point. your energy point is " << _energyPoints << std::endl;
	}
}
