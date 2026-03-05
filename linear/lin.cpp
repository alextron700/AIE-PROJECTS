#include <cassert>
#include<iostream>
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
	return outcome;
}

int main()
{
	int list[] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };
	assert(linearSearch(list, 3, 20) == 2);
	assert(linearSearch(list, 7, 20) == 11);
	assert(linearSearch(list, 67, 20) == 0);
	assert(linearSearch(list, 88, 20) == -1);
	return 0;
}