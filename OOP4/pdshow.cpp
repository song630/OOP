#include "basic.h"
#include "data_file.cpp"
using namespace std;

// extern int top;

int main(int argc, char *argv[])
{
    if(!argv[1])
    {
        cout << "Incomplete input.\n";
        exit(1);
    }
    recover_data();
    int i;
    bool flag = false; // whether the diary can be found
    for(i = 0; i < Record.total; i++)
    {
        if(Record.record_by_date[i].get_date() == argv[1])
        {
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        cout << "The file does not exist.\n";
        exit(1);
    }
    else
    {
        char buf[100];
        string title, path("D://code_blocks/Projects/OOP4/"), path_title;
        title = Record.record_by_date[i].get_name();
        path_title = path + title;
        ifstream infile(path_title.c_str());
        if(!infile)
        {
            cout << "Failed to open.\n";
            exit(1);
        }
        else
            cout << "Succeed.\n";
        while(!infile.eof())
        {
            infile.getline(buf, 80);
            cout << buf << "\n";
        }
        infile.close();
    }

    return 0;
}
