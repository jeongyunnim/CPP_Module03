#include <iostream>
#include <string>

class ClapTrap
{
public:

	ClapTrap(void);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& rhs);
	~ClapTrap(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:

	std::string	name;
	int			hitPoint;
	int			energyPoints;
	int			attackDamage;

};