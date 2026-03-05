#include<cassert>
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a = 50;
	int b = 19;
	int ac = a;
	int bc = b;
	swap(a, b);
	assert(ac != a && bc != b);
}