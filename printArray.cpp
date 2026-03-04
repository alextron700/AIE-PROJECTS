#include <string>
#include <iostream>
/*
fizzbuzz
INPUT: input (int*), size(int)
OUTPUT: NULL(void)
DEPENDS ON: NULL
IN COMPLIANCE WITH 1)
*/
void printArray(int* input, int size)
{ 
    for (int i = 0; i < size; i++)
    {
        if (i + 1 != size)
        {
            std::cout << input[i] << ",";
        }
        else {
            std::cout << input[i];
        }
    }
}
int main()
{
    int array[] = { 3,1,4,1,5,9,2,6,5,3,5 };
    printArray(array,static_cast<int>(sizeof(array) / sizeof(array[0])));
    return 0;
}