#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
public:

	std::string	getName(void) const;
	int			getHitPoints(void) const;
	int			getEnergyPoints(void) const;
	int			getAttackDamage(void) const;

	ScavTrap(void);
	~ScavTrap(void);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& rhs);
	ScavTrap(const std::string& name);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:

	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

};