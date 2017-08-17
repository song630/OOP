#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, string argv[])
{
    if(argv[1] == "")
        exit(0);
    for(int i = 0; i < argc; i++)
        cout << "argv[" << i << "] = [" << argv << "]\n";
    return 0;
}
