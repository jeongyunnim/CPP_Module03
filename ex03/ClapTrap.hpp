#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
public:

	std::string	getName(void) const;
	int			getHitPoints(void) const;
	int			getEnergyPoints(void) const;
	int			getAttackDamage(void) const;
	void		setName(std::string name);
	void		setHitPoints(int hitPoints);
	void		setEnergyPoints(int energyPoints);
	void		setAttackDamage(int attackDamage);

	ClapTrap(void);
	~ClapTrap(void);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& rhs);
	ClapTrap(const std::string& name);

	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);
	std::string	ClapTrap::name(void) const;

private:

	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

};