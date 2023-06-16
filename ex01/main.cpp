#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap mainCharacter("ironMan");
	ScavTrap enemy("warMachine");

	std::cout << "\n<Copy constructor test>\n=================================================" << std::endl;
	ClapTrap clone(enemy);
	std::cout << "\n<interactive test>\n=================================================" << std::endl;
	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	enemy.attack("ironMan");
	mainCharacter.takeDamage(enemy.getAttackDamage());
	mainCharacter.beRepaired(10);
	mainCharacter.beRepaired(9);
	mainCharacter.attack("warMachine");
	std::cout << "\n<Assignment operator test>\n=================================================" << std::endl;
	clone = mainCharacter;
	return (0);
}