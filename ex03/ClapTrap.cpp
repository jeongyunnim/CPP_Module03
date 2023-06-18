#include "ClapTrap.hpp"

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

int			ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

int			ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

int			ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}

void		ClapTrap::setName(std::string name)
{
	_name = name;
}

void		ClapTrap::setHitPoints(int hitPoints)
{
	_hitPoints = hitPoints;
}

void		ClapTrap::setEnergyPoints(int energyPoints)
{
	_energyPoints = energyPoints;
}

void		ClapTrap::setAttackDamage(int attackDamage)
{
	_attackDamage = attackDamage;
}

ClapTrap::ClapTrap(void)
	:	_name("* NONE_clap_name *")
	,	_hitPoints(10)
	,	_energyPoints(10)
	,	_attackDamage(0)
{
	std::cout << "[ClapTrap]Defalt Constructor is called. ClapTrap's name set to \"* None *\"" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[ClapTrap]Destructor is called. <" << _name << "> Shut down the system" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	:	_name(name + "_clap_name")
	,	_hitPoints(10)
	,	_energyPoints(10)
	,	_attackDamage(0)
{
	std::cout << "[ClapTrap]String constructor is called. He said, \"Helloooo I'm ClapTrap call me " << _name << "\"" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "[ClapTrap]Assignment operator called.\nname: " << _name << " -> " << rhs._name \
				<< "\nhit points: " << _hitPoints << " -> " << rhs._hitPoints \
				<< "\nenergy points: " << _energyPoints << " -> " << rhs._energyPoints \
				<< "\nattack damage: " << _attackDamage << " -> " << rhs._attackDamage << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& other)
	:	_name(other._name + "_clap_name")
	,	_hitPoints(other._hitPoints)
	,	_energyPoints(other._energyPoints)
	,	_attackDamage(other._attackDamage)
{
	std::cout << "[ClapTrap]Copy constructor is called. He said, \"Helloooo I'm ClapTrap!! call me " << _name << "\"" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
		std::cout << "[ClapTrap]Attack failed: Not enough energy point or hit point. [energy point]: " << _energyPoints << " [hit point]: " << _hitPoints << std::endl;
	else
	{
		_energyPoints -= 1;
		std::cout << "[ClapTrap]ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << " [EP]: " << _energyPoints << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
	{
		std::cout << "[ClapTrap]ClapTrap " << _name << " takes " << "zero damage! " << "[HP]: " << _hitPoints << std::endl;
		return ;
	}
	else if (_hitPoints - amount > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "[ClapTrap]ClapTrap " << _name << " takes " << amount << " points of damage! " << "[HP]: " << _hitPoints << ".\n" << _name << ": \"Ooooch!!\""<< std::endl;
	}
	else
	{
		_hitPoints = 0;
		std::cout << "[ClapTrap]ClapTrap " << _name << " lose all of hit points.." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints >= static_cast<int>(amount) && _hitPoints > 0)
	{
		_energyPoints -= amount;
		_hitPoints += amount;
		std::cout << "[ClapTrap]ClapTrap " << _name << " repairs " << amount << " points!" << " [HP]: " << _hitPoints << " [EP]: " << _energyPoints << std::endl;
	}
	else
	{
		std::cout << "[ClapTrap]Repair faild: Not enough energy point or hit point. [energy point]: " << _energyPoints << "[hit point]: " << _hitPoints << std::endl;
	}
}
