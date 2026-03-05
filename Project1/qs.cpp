#include <vector>
#include <cassert>
// fast in-place sort
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
	quickSort(list,len, min, Pcount - 1);
	quickSort(list,len, Pcount + 1, max);

	return;
}
int main()
{
	int linsearch[] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };
	quickSort(linsearch , 20, -2, -2);
	for (int i = 0; i < 19; i++)
	{
		assert(linsearch[i] <= linsearch[i + 1]);
	}
}