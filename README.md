# CPP_Module03

## Introduction

이번 모듈의 목표는 목적지향 프로그래밍에 대한 소개이다.
코드를 단순하게 유지하기 위해 C++98 표준을 준수한다.

### Exercise 00: Aaaaand... OPEN!

먼저 클래스를 구현해야 한다. 기본이지!

ClapTrap 클래스.
private:
- name
- Hit point
- Energy points
- Attack damage

public:
- void attack(const std::string& target);
- void takeDamage(unsigned int amount);
- void beRepaired(unsigned int amount);

ClapTrack이 공격할 때, 그 타겟은 <attack damage>만큼 hit point를 잃는다.
ClapTrap이 스스로 수리를 하면 <amount>만큼 hit point를 회복한다.
공격과 수리에는 각각 1 에너지 포인트가 소모된다. 
에너지 포인트가 없으면 아무것도 할 수 없다.

각 멤버 함수들은 어떤 일이 일어났는지 출력을 해야한다. 다음은 attack() 함수의 출력 예시이다.
`ClapTrap <name> attacks <target>, causing <damage> points of damage!`
생성자와 소멸자 또한 메세지를 표출해야 한다.

### Exercise 01: Serena, my love!


