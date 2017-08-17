#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{
	char input[100];
	char ch;
	ifstream myfile("D://code_blocks/Projects/OOP4/test1.txt");
	ofstream outfile("D://code_blocks/Projects/OOP4/test1.txt");
	if(!myfile)
		cout << "Failed to open." << endl;
	else
		cout << "Success." << endl;

	while(cin >> input)
		outfile << input << "\n";
	outfile << flush;
	outfile.close();

	system("pause");
	return 0;
}
