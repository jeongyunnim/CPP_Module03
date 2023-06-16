#include "ScavTrap.hpp"

std::string	ScavTrap::getName(void) const
{
	return (_name);
}

int	ScavTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

int	ScavTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

int	ScavTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}

ScavTrap::ScavTrap(void)
	:	_name("* NONE *")
	,	_hitPoints(100)
	,	_energyPoints(50)
	,	_attackDamage(20)
{
	std::cout << "[ScavTrap]Defalt Constructor is called. ScavTrap's name set to \"* None *\"" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap]Destructor is called. <" << _name << "> Shut down the system" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	:	_name(other._name)
	,	_hitPoints(other._hitPoints)
	,	_energyPoints(other._energyPoints)
	,	_attackDamage(other._attackDamage)
{
	std::cout << "[ScavTrap]Copy constructor is called. \"" << _name << " is ready.\"" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "[ScavTrap]Assignment operator called.\nname: " << _name << " -> " << rhs._name \
				<< "\nhit points: " << _hitPoints << " -> " << rhs._hitPoints \
				<< "\nenergy points: " << _energyPoints << " -> " << rhs._energyPoints \
				<< "\nattack damage: " << _attackDamage << " -> " << rhs._attackDamage << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

ScavTrap::ScavTrap(const std::string& name)
	:	_name(name)
	,	_hitPoints(100)
	,	_energyPoints(50)
	,	_attackDamage(20)
{
	std::cout << "[ScavTrap]String constructor is called. \"I'm ScavTrap. My name is " << _name << "\"" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
		std::cout << "[ScavTrap]Attack failed: Not enough energy point or hit point. [energy point]: " << _energyPoints << " [hit point]: " << _hitPoints << std::endl;
	else
	{
		_energyPoints -= 1;
		std::cout << "[ScavTrap]ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << " [EP]: " << _energyPoints << std::endl;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
	{
		std::cout << "[ScavTrap]ScavTrap " << _name << " takes " << "zero damage! " << "[HP]: " << _hitPoints << std::endl;
		return ;
	}
	if (_hitPoints - amount > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "[ScavTrap]ScavTrap " << _name << " takes " << amount << " points of damage! " << "[HP]: " << _hitPoints << ".\n" << _name << ": \"Where is revenge mode...\""<< std::endl;
	}
	else
	{
		_hitPoints = 0;
		std::cout << "[ScavTrap]ScavTrap " << _name << " lose all of hit points.." << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints >= static_cast<int>(amount) && _hitPoints > 0)
	{
		_energyPoints -= amount;
		_hitPoints += amount;
		std::cout << "[ScavTrap]ScavTrap " << _name << " repairs " << amount << " points!" << " [HP]: " << _hitPoints << " [EP]: " << _energyPoints << std::endl;
	}
	else
	{
		std::cout << "[ScavTrap]Repair faild: Not enough energy point or hit point. [energy point]: " << _energyPoints << "[hit point]: " << _hitPoints << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "[ScavTrap]" << _name << "'s Gate Keeper mode on." << std::endl;
}
