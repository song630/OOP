#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

int main()
{
	char s1[6] = "12345";
	cout << "s1 = " << s1 << "\n";

	char *s2 = new char[6];
	s2 = "12345\0";
	cout << "s2 = " << s2 << "\n";
	cout << strlen(s2) << "\n";

	char *s3 = new char[5];
	s3 = strcpy(s3, s2);
	cout << "s3 = " << s3 << "\n";

	cout << strcmp(s1, s2) << "\n";
	cout << strlen("1111\0") << "\n";

	char s4[6] = "123";
	cout << "s4 = " << s4 << "\n";
	cout << "length of s4 = " << strlen(s4) << "\n";

	system("pause");
	return 0;
}