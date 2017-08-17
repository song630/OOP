#include "basic.h"
#include "data_file.cpp"
using namespace std;

// extern int top;

int main(int argc, char *argv[])
{
    if(!argv[1] || !argv[2])
    {
        cout << "Invalid input.\n";
        exit(1);
    }
    recover_data();
    int d1 = argv[1][8], d2 = argv[1][9], // day
        d3 = argv[2][8], d4 = argv[2][9];
    int day1 = 10 * d1 + d2, day2 = 10 * d3 + d4;
    if(d1 > d2) // the former date should be no larger than the latter
    {
        cout << "Invalid input.\n";
        exit(1);
    }
    for(int i = 0; i < Record.total; i++)
    {
        int d5 = (Record.record_by_date[i].get_date())[8],
            d6 = (Record.record_by_date[i].get_date())[9];
        int day = d5 * 10 + d6;
        if(day >= day1 && day <= day2)
            cout << Record.record_by_date[i].get_name() << endl;
    }

    return 0;
}
