#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap mainCharacter("ironMan");
	DiamondTrap enemy("warMachine");

	std::cout << "\n<Copy constructor test>\n=================================================" << std::endl;
	ClapTrap clapTrapClone(enemy);
	DiamondTrap diamondTrapClone(enemy);
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
	mainCharacter.guardGate();
	mainCharacter.highFivesGuys();
	mainCharacter.whoAmI();
	std::cout << "\n<Assignment operator test>\n=================================================" << std::endl;
	clapTrapClone = mainCharacter;
	diamondTrapClone = mainCharacter;
	return (0);
}