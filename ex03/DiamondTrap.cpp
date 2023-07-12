#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	:	ClapTrap()
{
	name = "* NONE *";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "[DiamondTrap]Defalt Constructor is called. DiamondTrap's name set to \"* None *\"" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "[DiamondTrap]Destructor is called. <" << _name << "> Shut down the system" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	:	ClapTrap(other._name)
	,	ScavTrap(other)
	,	FragTrap(other)
{
	std::cout << "[DiamondTrap]Copy constructor is called. \"Update complete. DiamondTrap <" << _name << ">\"" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "[DiamondTrap]Assignment operator called.\nname: " << _name << " -> " << rhs._name \
				<< "\nhit points: " << _hitPoints << " -> " << rhs._hitPoints \
				<< "\nenergy points: " << _energyPoints << " -> " << rhs._energyPoints \
				<< "\nattack damage: " << _attackDamage << " -> " << rhs._attackDamage << std::endl;
	_name.clear();
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

DiamondTrap::DiamondTrap(const std::string& name)
	:	ClapTrap(name)
	,	ScavTrap(name)
	,	FragTrap(name)
{
	this->name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "[DiamondTrap]String constructor is called. \"Update complete. DiamondTrap <" << _name << ">\"" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
	{
		std::cout << "[DiamondTrap]DiamondTrap " << _name << " takes " << "zero damage! " << "[HP]: " << getHitPoints() << std::endl;
		return ;
	}
	if (_hitPoints - amount > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "[DiamondTrap]DiamondTrap " << _name << " takes " << amount << " points of damage! " << "[HP]: " << getHitPoints() << ".\n" << _name << ": \"Danger Danger...\""<< std::endl;
	}
	else
	{
		_hitPoints = 0;
		std::cout << "[DiamondTrap]DiamondTrap " << _name << " lose all of hit points.." << std::endl;
	}
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints >= static_cast<int>(amount) && _hitPoints > 0)
	{
		_energyPoints -= amount;
		_hitPoints += amount;
		std::cout << "[DiamondTrap]DiamondTrap " << _name << " repairs " << amount << " points!" << " [HP]: " << _hitPoints << " [EP]: " << _energyPoints << std::endl;
	}
	else
	{
		std::cout << "[DiamondTrap]Repair faild: Not enough energy point or hit point. [energy point]: " << _energyPoints << " [hit point]: " << _hitPoints << std::endl;
	}
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "[DiamondTrap] Diamond trap name: " << name << ", Clap trap name: " << _name << std::endl;
}
