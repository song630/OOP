#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{
    ifstream myfile("D://code_blocks/Projects/OOP4/intest.txt");
    char a;
    myfile.get(a);
    cout << a;
    myfile.get(); // must skip the manip "\n". but getline() does not need to
    // cout << a;
    myfile.get(a);
    cout << a;

    return 0;
}
