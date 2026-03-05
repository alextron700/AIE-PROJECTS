#include <string>
#include <iostream>
struct Mob {
	std::string name;
	int health;
	int damage;
	int attackSkill;
};
enum atkSkill {
	RANGED,
	MELEE
};
void battleTurn(Mob& A, Mob& B)
{
	if (A.damage > B.damage)
	{
		int dmg = rand() % A.damage;
		switch (A.attackSkill)
		{
		case RANGED:
			std::cout << A.name << "dealt " << dmg << " with a ranged attack to " << B.name << std::endl;
			B.health -= dmg;
			break;
		case MELEE:
			std::cout << A.name << "dealt " << dmg << " with a melee attack to " << B.name << std::endl;
			B.health -= dmg;
			break;
		}
	}
	return;
}
int main()
{
	int round = 0;
	Mob Orc;
	Orc.name = " Orc ";
	Orc.health = 45;
	Orc.damage = 12;
	Orc.attackSkill = MELEE;
	Mob ranger;
	ranger.name = " Noel the hunter ";
	ranger.health = 32;
	ranger.damage = 13;
	ranger.attackSkill = RANGED;
	while ((Orc.health > 0 && ranger.health > 0))
	{
		std::cout << "round " << round++;
		battleTurn(ranger, Orc);
		std::cout << "round " << round++;
		battleTurn(Orc, ranger);
		if (round > 50)
		{
			break;
		}
	}
	std::cout << ranger.health << std::endl;
	std::cout << Orc.health << std::endl;
	return 0;
}