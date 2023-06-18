#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
public:

	ScavTrap(void);
	~ScavTrap(void);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& rhs);
	ScavTrap(const std::string& name);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void guardGate(void);

private:

};