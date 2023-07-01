#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap mainCharacter("ironMan");
	ScavTrap enemy("warMachine");

	std::cout << "\n<Copy constructor test>\n=================================================" << std::endl;
	ClapTrap clapTrapClone(enemy);
	ScavTrap scavTrapClone(enemy);
	std::cout << "\n<interactive test>\n=================================================" << std::endl;
	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	enemy.attack("ironMan");
	mainCharacter.beRepaired(10);
	mainCharacter.beRepaired(40);
	mainCharacter.beRepaired(33);
	mainCharacter.guardGate();
	mainCharacter.guardGate();
	std::cout << "\n<Assignment operator test>\n=================================================" << std::endl;
	clapTrapClone = mainCharacter;
	scavTrapClone = mainCharacter;
	return (0);
}