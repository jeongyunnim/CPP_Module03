#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{
public:

	FragTrap(void);
	~FragTrap(void);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& rhs);
	FragTrap(const std::string& name);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void highFivesGuys(void);

};