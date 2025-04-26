#include <iostream>

static int arr[100];

static int fib(int a)
{

	if (a == 0)
	{
		return 0;
	}
	if (a == 1)
	{
		return 1;
	}

	if (arr[a]) {}
	else
	{
		arr[a] =  fib(a - 1) + fib(a - 2);	
	}
	return arr[a];
}

int main() 
{	
	std :: cout << fib(150);
}
