#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	:	ClapTrap("* NONE *")
{
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
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
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

DiamondTrap::DiamondTrap(const std::string& name)
	:	ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "[DiamondTrap]String constructor is called. \"Update complete. DiamondTrap <" << getName() << ">\"" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	if (getEnergyPoints() <= 0 || getHitPoints() <= 0)
		std::cout << "[DiamondTrap]Attack failed: Not enough energy point or hit point. [energy point]: " << getEnergyPoints() << " [hit point]: " << getHitPoints() << std::endl;
	else
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "[DiamondTrap]DiamondTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << " [EP]: " << getEnergyPoints() << std::endl;
	}
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

void	DiamondTrap::highFivesGuys(void)
{
	if (getEnergyPoints() <= 0 || getHitPoints() <= 0)
		std::cout << "[DiamondTrap]High five guys failed: Not enough energy point or hit point. [energy point]: " << getEnergyPoints() << " [hit point]: " << getHitPoints() << std::endl;
	else
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "[DiamondTrap]" << getName() << "\"Let's Hiiiiiiigh fiiiiiiiive guys!!!!!!\"" << std::endl;
	}
}
