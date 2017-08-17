#include "out_of_bounds.h"
#include "templateVector.h"
#include "function.cpp"
using namespace std;

int main()
{
	Vector<int> v1(5); // the type must be specified in <>
	for(int i = 0; i <= 4; i++)
		v1[i] = i;
	cout << v1 << "\n";
	Vector<int> v2(v1);
	cout << v2 << "\n";
	cout << v2.size() << "\n";
	int total_size = v2.inflate(3);
	for(int i = 5; i <= 7; i++)
		v2[i] = i;
	cout << total_size << "\n";
	cout << v2 << "\n";
	Vector<short> v3(6);
	v2[0] = v3[6];

	system("pause");
	return 0;
}