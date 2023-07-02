#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap ironMan("ironMan");
	DiamondTrap warMachine("warMachine");
	ScavTrap	scavTrapClone("scav test");
	FragTrap	fragTrapClone("frag test");

	std::cout << "\n<Copy constructor test>\n=================================================" << std::endl;
	ClapTrap	clapTrapClone(warMachine);
	DiamondTrap	diamondTrapClone(warMachine);
	std::cout << "\n<interactive test>\n=================================================" << std::endl;
	ironMan.attack("warMachine");
	warMachine.takeDamage(ironMan.getAttackDamage());
	warMachine.attack("ironMan");
	ironMan.takeDamage(warMachine.getAttackDamage());
	ironMan.beRepaired(100);
	ironMan.attack("warMachine");
	warMachine.takeDamage(ironMan.getAttackDamage());
	ironMan.attack("warMachine");
	warMachine.takeDamage(ironMan.getAttackDamage());
	ironMan.attack("warMachine");
	warMachine.takeDamage(ironMan.getAttackDamage());
	ironMan.attack("warMachine");
	warMachine.takeDamage(ironMan.getAttackDamage());
	warMachine.attack("ironMan");
	ironMan.guardGate();
	ironMan.highFivesGuys();
	ironMan.whoAmI();
	std::cout << "\n<Assignment operator test>\n=================================================" << std::endl;
	clapTrapClone = ironMan;
	diamondTrapClone = ironMan;
	scavTrapClone = diamondTrapClone;
	fragTrapClone = diamondTrapClone;
	return (0);
}