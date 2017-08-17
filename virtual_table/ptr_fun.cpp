#include <iostream>
#include <cstdlib>
using namespace std;

int foo(int x);
int (*fun)(int); // (int) is better than (int x)

int main(void)
{
	int result;
	fun = foo; // fun = &foo also works
	result = (*fun)(2);
	cout << result << endl;

	system("pause");
	return 0;
}

int foo(int x)
{
	return x;
}