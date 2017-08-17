#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

int main(void)
{
	int i = 1234;
	ostringstream s1;
	s1 << i;
	s1 << i;
	string s2 = s1.str();
	cout << s2 << endl;

	system("pause");
	return 0;
}