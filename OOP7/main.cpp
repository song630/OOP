// #include "String.h"
// #include "out_of_range.h"
#include "function.cpp"
using namespace std;

int main()
{
	String s1 = "0000"; // test copy Ctor
	cout << "s1 = " << s1 << "\n";
	cout << "length of s1 = " << s1.s_size() << "\n";

	String s2 = s1; // test copy Ctor
	String s3("11111"); // test copy Ctor
	cout << "s2 = " << s2 << "\n";
	cout << "s3 = " << s3 << "\n";

	String s4; // test default Ctor
	cout << "s4.is_empty() = " << s4.is_empty() << "\n";

	String s5(5, '5'); // test Ctor and cout
	cout << "s5 = " << s5 << "\n";

	if(s1 == s2) // test overrode relationship operator
		cout << "s1 = s2\n";
	if(s3 != s5)
		cout << "s3 != s5\n";

	s5 = s3; // test overrode assignment operator
	cout << "s5 = " << s5 << "\n";

	s5[2] = '8'; s5[3] = '9'; // test overrode index operator
	cout << "s5 = " << s5 << "\n";

	s5 += s3; // test overrode recombined operator and arithmetic operator
	cout << "s5 = " << s5 << "\n";
	cout << "s3 + s5 = " << (s3 + s5) << "\n";

	cin >> s2; // test cin
	cout << "s2 = " << s2 << "\n";
	cout << "length of s2 = " << s2.s_size() << "\n";

	system("pause");
	return 0;
}
