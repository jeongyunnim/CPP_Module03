#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	:	ClapTrap("* NONE *")
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "[FragTrap]Defalt Constructor is called. FragTrap's name set to \"* None *\"" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FragTrap]Destructor is called. <" << getName() << "> Shut down the system" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	:	ClapTrap(other.getName())
{
	setHitPoints(getHitPoints());
	setEnergyPoints(getEnergyPoints());
	setAttackDamage(getAttackDamage());
	std::cout << "[FragTrap]Copy constructor is called. \"Update complete. FragTrap <" << getName() << "> kill kill kill kill\"" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "[FragTrap]Assignment operator called.\nname: " << getName() << " -> " << rhs.getName() \
				<< "\nhit points: " << getHitPoints() << " -> " << rhs.getHitPoints() \
				<< "\nenergy points: " << getEnergyPoints() << " -> " << rhs.getEnergyPoints() \
				<< "\nattack damage: " << getAttackDamage() << " -> " << rhs.getAttackDamage() << std::endl;
	setName(rhs.getName());
	setHitPoints(rhs.getHitPoints());
	setEnergyPoints(rhs.getEnergyPoints());
	setAttackDamage(rhs.getAttackDamage());
	return (*this);
}

FragTrap::FragTrap(const std::string& name)
	:	ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "[FragTrap]String constructor is called. \"Update complete. FragTrap <" << getName() << "> kill kill kill kill\"" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (getEnergyPoints() <= 0 || getHitPoints() <= 0)
		std::cout << "[FragTrap]Attack failed: Not enough energy point or hit point. [energy point]: " << getEnergyPoints() << " [hit point]: " << getHitPoints() << std::endl;
	else
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "[FragTrap]FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << " [EP]: " << getEnergyPoints() << std::endl;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
	{
		std::cout << "[FragTrap]FragTrap " << getName() << " takes " << "zero damage! " << "[HP]: " << getHitPoints() << std::endl;
		return ;
	}
	if (getHitPoints() - amount > 0)
	{
		setHitPoints(getHitPoints() - amount);
		if (getHitPoints() < 0)
			setHitPoints(0);
		std::cout << "[FragTrap]FragTrap " << getName() << " takes " << amount << " points of damage! " << "[HP]: " << getHitPoints() << ".\n" << getName() << ": \"Danger Danger...\""<< std::endl;
	}
	else
	{
		setHitPoints(0);
		std::cout << "[FragTrap]FragTrap " << getName() << " lose all of hit points.." << std::endl;
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() >= static_cast<int>(amount) && getHitPoints() > 0)
	{
		setEnergyPoints(getEnergyPoints() - amount);
		setHitPoints(getHitPoints() + amount);
		std::cout << "[FragTrap]FragTrap " << getName() << " repairs " << amount << " points!" << " [HP]: " << getHitPoints() << " [EP]: " << getEnergyPoints() << std::endl;
	}
	else
	{
		std::cout << "[FragTrap]Repair faild: Not enough energy point or hit point. [energy point]: " << getEnergyPoints() << " [hit point]: " << getHitPoints() << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	if (getEnergyPoints() <= 0 || getHitPoints() <= 0)
		std::cout << "[FragTrap]High five guys failed: Not enough energy point or hit point. [energy point]: " << getEnergyPoints() << " [hit point]: " << getHitPoints() << std::endl;
	else
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "[FragTrap]" << getName() << "\"Let's Hiiiiiiigh fiiiiiiiive guys!!!!!!\"" << std::endl;
	}
}
