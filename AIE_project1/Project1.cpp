#include <iostream>
#include <cassert>
#include <vector>
#include <string>
int linearSearch(int list[], int item, int size)
{
	int outcome = -1;
	for (int i = 0; i < size; i++)
	{
		if (list[i] == item)
		{
			outcome = i;
		}
	}
	if (item == 3)
	{
		assert(outcome == 2);
	}
	if (item == 7)
	{
		assert(outcome == 11);
	}
	if (item == 67)
	{
		assert(outcome == 0);
	}
	if (item == 88)
	{
		assert(outcome == -1);
	}
	return outcome;
}
void quickSort(int list[],int len, int min = -2, int max = -2)
{
	if (min == -2)
	{
		min = 0;
	}
	if (max == -2)
	{
		max = len - 1;
	}
	if (min >= max)
	{
		return;
	}
	int pivot = list[min];
	
	int Pcount = min; // how many times the pivot has moved
	for (int i = min + 1; i <= max; i++)
	{
		if (list[i] < pivot)
		{ // [2,1] pivot = 2, i = 1, temp = 1,
			Pcount++;
			std::swap(list[i], list[Pcount]);
			
		}
	}
	std::swap(list[min], list[Pcount]);
	quickSort(list, min, Pcount - 1);
	quickSort(list, Pcount + 1, max);
	
	return;
}
int binarySearch(int list[], int item, int min = -1, int max = -1)
{
	int LBound;
	int RBound;
	if (max == -1)
	{
		RBound = (sizeof(list)/sizeof(list[0])) - 1;
	}
	else
	{
		RBound = max;
	}
	if (min == -1)
	{
		LBound = 0;
	}
	else 
	{
		LBound = min;
	}
	if (LBound > RBound)
	{
		return -1;
	}
	int middle =LBound + ((RBound - LBound)/2);
	int midIdx = list[middle];
	if (midIdx != item)
	{
		if (midIdx > item)
		{
			return binarySearch(list, item, LBound, middle -1);
		}
		else
		{
			return binarySearch(list, item, middle + 1, RBound);
		}
	}
	else {
		return middle;
	}

}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
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
			std::cout << A.name << "dealt " << dmg << " with a ranged attack to " << B.name<<std::endl;
			B.health -= dmg;
			break;
		case MELEE:
			std::cout << A.name << "dealt " << dmg << " with a melee attack to " << B.name<<std::endl;
			B.health -= dmg;
			break;
		}
	}
	return;
}


int main()
{
	int round = 0;
	int linsearch[] = {67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29};
	linearSearch(linsearch, 3,20);
	linearSearch(linsearch, 7,20);
	linearSearch(linsearch, 67,20);
	linearSearch(linsearch, 88,20);
	quickSort(linsearch, -2, -2);
	for (int i = 0; i < 13; i++)
	{
		std::cout << linsearch[i] << " ,";
	}
	for (int i = 0; i < 12; i++)
	{
		assert(linsearch[i] <= linsearch[i + 1]);
	}
	int item = 3;
	int idx = binarySearch(linsearch, item, -1, -1);
	if (item == 11)
	{
		assert(idx == 4);
	}
	if (item == 23)
	{
		assert(idx == 8);
	}
	if (item == 97)
	{
		assert(idx == 19);
	}
	if (item == 88)
	{
		assert(idx == -1);
	}
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