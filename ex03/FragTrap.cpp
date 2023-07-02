#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "[FragTrap]Defalt Constructor is called. FragTrap's name set to \"* None *\"" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FragTrap]Destructor is called. <" << _name << "> Shut down the system" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	:	ClapTrap(other._name)
{
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "[FragTrap]Copy constructor is called. \"Update complete. FragTrap <" << _name << "> kill kill kill kill\"" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "[ScavTrap]Assignment operator called.\nname: " << _name << " -> " << rhs._name \
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

FragTrap::FragTrap(const std::string& name)
	:	ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "[FragTrap]String constructor is called. \"Update complete. FragTrap <" << _name << "> kill kill kill kill\"" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
		std::cout << "[FragTrap]Attack failed: Not enough energy point or hit point. [energy point]: " << _energyPoints << " [hit point]: " << _hitPoints << std::endl;
	else
	{
		_energyPoints -= 1;
		std::cout << "[FragTrap]FragTrap " << _name << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << " [EP]: " << _energyPoints << std::endl;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
	{
		std::cout << "[FragTrap]FragTrap " << _name << " takes " << "zero damage! " << "[HP]: " << _hitPoints << std::endl;
		return ;
	}
	if (_hitPoints - amount > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "[FragTrap]FragTrap " << _name << " takes " << amount << " points of damage! " << "[HP]: " << _hitPoints << "." << std::endl;
	}
	else
	{
		_hitPoints = 0;
		std::cout << "[FragTrap]FragTrap " << _name << " lose all of hit points.." << std::endl;
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints >= static_cast<int>(amount) && _hitPoints > 0)
	{
		_energyPoints -= amount;
		_hitPoints += amount;
		std::cout << "[FragTrap]FragTrap " << _name << " repairs " << amount << " points!" << " [HP]: " << _hitPoints << " [EP]: " << _energyPoints << std::endl;
	}
	else
	{
		std::cout << "[FragTrap]Repair faild: Not enough energy point or hit point. [energy point]: " << _energyPoints << " [hit point]: " << _hitPoints << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
		std::cout << "[FragTrap]High five guys failed: Not enough energy point or hit point. [energy point]: " << _energyPoints << " [hit point]: " << _hitPoints << std::endl;
	else
	{
		_energyPoints -= 1;
		std::cout << "[FragTrap]" << _name << "\"Let's Hiiiiiiigh fiiiiiiiive guys!!!!!!\"" << std::endl;
	}
}
