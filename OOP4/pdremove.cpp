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
        const string file_name = Record.record_by_date[i].get_name();
        for(; i < Record.total - 1; i++) // all transfer forward
        {
            Record.record_by_date[i].set_date( Record.record_by_date[i + 1].get_date() );
            Record.record_by_date[i].set_title( Record.record_by_date[i + 1].get_name() );
        }
        Record.total--;
        remove(file_name.c_str());
        save_modification();
    }

    return 0;
}
