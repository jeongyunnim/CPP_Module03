#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap mainCharacter("ironMan");
	FragTrap enemy("warMachine");

	std::cout << "\n<Copy constructor test>\n=================================================" << std::endl;
	ClapTrap clapTrapClone(enemy);
	FragTrap scavTrapClone(enemy);
	std::cout << "\n<interactive test>\n=================================================" << std::endl;
	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	enemy.attack("ironMan");
	mainCharacter.takeDamage(enemy.getAttackDamage());
	mainCharacter.beRepaired(100);
	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	mainCharacter.attack("warMachine");
	enemy.takeDamage(mainCharacter.getAttackDamage());
	enemy.attack("ironMan");
	mainCharacter.highFivesGuys();
	mainCharacter.highFivesGuys();
	std::cout << "\n<Assignment operator test>\n=================================================" << std::endl;
	clapTrapClone = mainCharacter;
	scavTrapClone = mainCharacter;
	return (0);
}