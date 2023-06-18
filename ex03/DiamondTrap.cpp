#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	:	ClapTrap("* NONE *")
	,	ScavTrap("* NONE *")
	,	FragTrap("* NONE *")
{
	name = "* NONE *";
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "[DiamondTrap]Defalt Constructor is called. DiamondTrap's name set to \"* None *\"" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "[DiamondTrap]Destructor is called. <" << getName() << "> Shut down the system" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	:	ClapTrap(other.getName())
	,	ScavTrap(other.getName())
	,	FragTrap(other.getName())
{
	name = other.name;
	setName(other.getName());
	setHitPoints(other.getHitPoints());
	setEnergyPoints(other.getEnergyPoints());
	setAttackDamage(other.getAttackDamage());
	std::cout << "[DiamondTrap]Copy constructor is called. \"Update complete. DiamondTrap <" << getName() << ">\"" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "[DiamondTrap]Assignment operator called.\nname: " << getName() << " -> " << rhs.getName() \
				<< "\nhit points: " << getHitPoints() << " -> " << rhs.getHitPoints() \
				<< "\nenergy points: " << getEnergyPoints() << " -> " << rhs.getEnergyPoints() \
				<< "\nattack damage: " << getAttackDamage() << " -> " << rhs.getAttackDamage() << std::endl;
	setName(rhs.getName());
	setHitPoints(rhs.getHitPoints());
	setEnergyPoints(rhs.getEnergyPoints());
	setAttackDamage(rhs.getAttackDamage());
	return (*this);
}

DiamondTrap::DiamondTrap(const std::string& pName)
	:	ClapTrap(pName)
	,	ScavTrap(pName)
	,	FragTrap(pName)
	,	name(pName)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "[DiamondTrap]String constructor is called. \"Update complete. DiamondTrap <" << getName() << ">\"" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	std::cout << "[DiamondTrap] ";
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
	{
		std::cout << "[DiamondTrap]DiamondTrap " << getName() << " takes " << "zero damage! " << "[HP]: " << getHitPoints() << std::endl;
		return ;
	}
	if (getHitPoints() - amount > 0)
	{
		setHitPoints(getHitPoints() - amount);
		if (getHitPoints() < 0)
			setHitPoints(0);
		std::cout << "[DiamondTrap]DiamondTrap " << getName() << " takes " << amount << " points of damage! " << "[HP]: " << getHitPoints() << ".\n" << getName() << ": \"Danger Danger...\""<< std::endl;
	}
	else
	{
		setHitPoints(0);
		std::cout << "[DiamondTrap]DiamondTrap " << getName() << " lose all of hit points.." << std::endl;
	}
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() >= static_cast<int>(amount) && getHitPoints() > 0)
	{
		setEnergyPoints(getEnergyPoints() - amount);
		setHitPoints(getHitPoints() + amount);
		std::cout << "[DiamondTrap]DiamondTrap " << getName() << " repairs " << amount << " points!" << " [HP]: " << getHitPoints() << " [EP]: " << getEnergyPoints() << std::endl;
	}
	else
	{
		std::cout << "[DiamondTrap]Repair faild: Not enough energy point or hit point. [energy point]: " << getEnergyPoints() << " [hit point]: " << getHitPoints() << std::endl;
	}
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "[DiamondTrap] Diamond trap name: " << name << ", Clap trap name: " << getName() << std::endl;
}
