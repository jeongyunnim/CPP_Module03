# CPP_Module03

## Introduction

이번 모듈의 목표는 목적지향 프로그래밍에 대한 소개이다.
코드를 단순하게 유지하기 위해 C++98 표준을 준수한다.

### Exercise 00: Aaaaand... OPEN!

먼저 클래스를 구현해야 한다. 기본이지!

ClapTrap 클래스.
private:
- name
    : 생성자 파라미터로 전달받은 문자열.
- Hit points (10)
    : ClapTrap의 체력 HP
- Energy points (10)
- Attack damage (0)

public:
- void attack(const std::string& target);
- void takeDamage(unsigned int amount);
- void beRepaired(unsigned int amount);

ClapTrap이 공격할 때, 그 타겟은 <attack damage>만큼 hit point를 잃는다.(ClapTrack은 오타인듯)
ClapTrap이 스스로 수리를 하면 <amount>만큼 hit point를 회복한다.
공격과 수리에는 각각 1 에너지 포인트가 소모된다. 
에너지 포인트가 없으면 아무것도 할 수 없다.

각 멤버 함수들은 어떤 일이 일어났는지 출력을 해야한다. 다음은 attack() 함수의 출력 예시이다.
`ClapTrap <name> attacks <target>, causing <damage> points of damage!`
생성자와 소멸자 또한 메세지를 표출해야 한다.

### Exercise 01: Serena, my love!

ClapTrap으로는 절대 충분하지 않기 때문에, 그 파생로봇 ScavTrap을 만들 것이다.
ScavTrap은 Claptrap의 생성자와 소멸자를 상속받을 것이다. 그러나 생성자와 소멸자, attack은 다른 메세지를 출력해야한다.
결국 ClapTrap은 그 개별성을 알아야 한다.

테스트에서 생성자와 소멸자를 잘 보여줘야 한다. ScavTrap이 생성될 때, 프로그램은 ClapTrap을 생성하면서 시작할 것이다. 소멸자는 반대의 순서로 진행된다. 왜일까?

ScavTrap 은 ClapTrap의 속성을 사용하여(결국 ClapTrap을 업데이트 한다) 초기화 해야한다.
- name
    : 생성자의 파라미터로 전달받은 문자열.
- Hit points (100)
    : ClapTrap의 체력 HP
- Energy points (50)
- Attack damage (20)

ScavTrap은 특별한 능력이 있다.
- void  guardGate();

Scavtrap의 멤버함수는 guard keeper 모드로 전환되었다는 메세지를 출력해야한다.

### Exercise 02: Repetitive work

ClapTrap을 만드는 것이 점점 신경쓰이기 시작했을 것이다.
ClapTrap을 상속한 FragTrap 클래스를 구현하라. ScavTrap을 만드는 것과 비슷하지만, 생성자와 소멸자 메세지는 달라야 한다.
테스트에 적절한 생성/소멸자의 흐름을 잘 보여주어야 한다. FragTrap이 만들어졌을 때, 프로그램은 ClapTrap을 만들면서 시작할 것이고, 소멸은 그 역순일 것이다.

ClapTrap과 같은 특성을 가지고 있다. 하지만 다른 값을 가진다.
- name
    : 생성자의 파라미터로 전달받은 문자열.
- Hit points (100)
    : ClapTrap의 체력 HP
- Energy points (100)
- Attack damage (30)

FragTrap은 특별한 능력이 있다.
- void highFivesGuys(void);

이 멤버함수는 표준출력으로 긍정적인 하이파이브를 표출한다.

### Exercise 03: Now it's weird!

이 에제에서는 몬스터를 만들 것이다.
반 FragTrap 반 ScavTrap인 ClapTrap이며 DiamondTrapd이라고 부를 것이다.
FragTrap과 ScavTrap을 반 씩 상속받을 것이다. 너무 위험하지!

DiamondTrap 클래스는 private 변수로 name을 가진다. 이 속성에 ClapTrap의 기본 클래스에 있는 것과 동일한 변수 이름을 지정한다.
더 명확하게 하기 위한 두 개의 예시가 있다.
만약 ClapTrap의 변수가 `name`이라면  DiamondTrap의 이름에 'name'을 지정한다.
만약 ClapTrap의 변수가 `_name`이라면  DiamondTrap의 이름에 '_name'을 지정한다.

해당 특성과 멤버 함수는 부모 클래스 중 하나에서 선택된다.

- name
    : 생성자의 파라미터로 전달받은 문자열.
- ClapTrap::name
    : 생성자의 파라미터 + "_clap_name" 접미사
- Hit points (fragTrap)
    : ClapTrap의 체력 HP
- Energy points (ScavTrap)
- Attack damage (FragTrap)
- void attack() (ScavTrap)

추가적으로 두 클래스의 특별 능력을 사용할 수 있고, DiamondTrap의 고유 능력을 사용할 수 있다.
- void whoAmI();

이 멤버 함수는 해당 기계의 이름과 ClapTrap 이름을 표출한다.
물론 ClapTrap의 하위 오브젝트는 한 번만 생성된다. (여기에는 트릭이 있다)

Do you know the -Wshadow and -Wno-shadow compiler flags?
