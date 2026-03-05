#include <vector>
#include <cassert>
#include <iostream>
// fast in-place sort
void quickSort(int list[], int len, int min = -2, int max = -2)
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
	quickSort(list, len, min, Pcount - 1);
	quickSort(list, len, Pcount + 1, max);

	return;
}
int binarySearch(int list[], int item,int len, int min = -1, int max = -1)
{
	int LBound;
	int RBound;
	if (max == -1)
	{
		RBound = len - 1; //(sizeof(list) / static_cast<float>(sizeof(list[0]))) - 1;
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
	int middle = LBound + ((RBound - LBound) / 2);
	int midIdx = list[middle];
	if (midIdx != item)
	{
		if (midIdx > item)
		{
			return binarySearch(list, item,len, LBound, middle - 1);
		}
		else
		{
			return binarySearch(list, item,len, middle + 1, RBound);
		}
	}
	else {
		return middle;
	}

}
int main()
{
	int list[] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };
	quickSort(list, 20, -2, -2);
	
	assert(binarySearch(list, 11,20, -1, -1) == 4);
	assert(binarySearch(list, 23, 20, -1, -1) == 8);
	assert(binarySearch(list, 97, 20, -1, -1) == 19);
	assert(binarySearch(list, 88, 20, -1, -1) == -1);
}