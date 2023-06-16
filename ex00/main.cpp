#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap mainCharacter("ironMan");
	ClapTrap enemy("warMachine");

	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	enemy.attack("ironMan");
	mainCharacter.takeDamage(enemy.getAttackDamage());
	mainCharacter.beRepaired(10);
	mainCharacter.beRepaired(9);
	mainCharacter.attack("warMachine");
	return (0);
}