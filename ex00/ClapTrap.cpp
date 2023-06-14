#include <iostream>
#include <string>

class ClapTrap
{
public:
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
private:
	std::string	name;
	int			hitPoint;
	int			energyPoints;
	int			attackDamage;

};