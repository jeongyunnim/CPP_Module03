#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	:	ClapTrap("* NONE *")
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "[ScavTrap]Defalt Constructor is called. ScavTrap's name set to \"* None *\"" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap]Destructor is called. <" << getName() << "> Shut down the system" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	:	ClapTrap(other.getName())
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "[ScavTrap]Copy constructor is called. \"" << getName() << " is ready.\"" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "[ScavTrap]Assignment operator called.\nname: " << getName() << " -> " << rhs.getName() \
				<< "\nhit points: " << getHitPoints() << " -> " << rhs.getHitPoints() \
				<< "\nenergy points: " << getEnergyPoints() << " -> " << rhs.getEnergyPoints() \
				<< "\nattack damage: " << getAttackDamage() << " -> " << rhs.getAttackDamage() << std::endl;
	setName(rhs.getName());
	setHitPoints(rhs.getHitPoints());
	setEnergyPoints(rhs.getEnergyPoints());
	setAttackDamage(rhs.getAttackDamage());
	return (*this);
}

ScavTrap::ScavTrap(const std::string& name)
	:	ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "[ScavTrap]String constructor is called. \"I'm ScavTrap. My name is " << getName() << "\"" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoints() <= 0 || getHitPoints() <= 0)
		std::cout << "[ScavTrap]Attack failed: Not enough energy point or hit point. [energy point]: " << getEnergyPoints() << " [hit point]: " << getHitPoints() << std::endl;
	else
	{
		getEnergyPoints() -= 1;
		std::cout << "[ScavTrap]ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << " [EP]: " << getEnergyPoints() << std::endl;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
	{
		std::cout << "[ScavTrap]ScavTrap " << getName() << " takes " << "zero damage! " << "[HP]: " << getHitPoints() << std::endl;
		return ;
	}
	if (getHitPoints() - amount > 0)
	{
		getHitPoints() -= amount;
		if (getHitPoints() < 0)
			getHitPoints() = 0;
		std::cout << "[ScavTrap]ScavTrap " << getName() << " takes " << amount << " points of damage! " << "[HP]: " << getHitPoints() << ".\n" << getName() << ": \"Where is revenge mode...\""<< std::endl;
	}
	else
	{
		getHitPoints() = 0;
		std::cout << "[ScavTrap]ScavTrap " << getName() << " lose all of hit points.." << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() >= static_cast<int>(amount) && getHitPoints() > 0)
	{
		getEnergyPoints() -= amount;
		getHitPoints() += amount;
		std::cout << "[ScavTrap]ScavTrap " << getName() << " repairs " << amount << " points!" << " [HP]: " << getHitPoints() << " [EP]: " << getEnergyPoints() << std::endl;
	}
	else
	{
		std::cout << "[ScavTrap]Repair faild: Not enough energy point or hit point. [energy point]: " << getEnergyPoints() << "[hit point]: " << getHitPoints() << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "[ScavTrap]" << getName() << "'s Gate Keeper mode on." << std::endl;
}
