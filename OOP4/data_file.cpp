#include "basic.h"

extern int top = 0;

void recover_data()
{
    ifstream myfile("D://code_blocks/Projects/OOP4/records.txt");
    if(!myfile)
        cout << "Failed to open, or no previous records.txt.\n";
    else
    {
        cout << "Succeed.\n";
        char num;
        myfile.get(num);
        top = num - '0';
        myfile.get(); // skip "\n"
        myfile.get(num);
        Record.total = num - '0';
        myfile.get(); // skip "\n"
        char buf[30];
        int i = 0;
        while(!myfile.eof())
        {
            Diary new_dairy;
            myfile.getline(buf, 20);
            new_dairy.set_date(buf);
            myfile.getline(buf, 20);
            new_dairy.set_title(buf);
            Record.record_by_date[i++] = new_dairy;
        }
        myfile.close();
    }
}

void save_modification()
{
    ofstream ofile("D://code_blocks/Projects/OOP4/records.txt");
    if(!ofile)
    {
        cout << "Failed to open.\n";
        exit(1);
    }
    else
        cout << "Succeed.\n";
    ofile << top << "\n";
    ofile << Record.total << "\n";
    for(int i = 0; i < Record.total; i++)
    {
        ofile << Record.record_by_date[i].get_date() << "\n";
        ofile << Record.record_by_date[i].get_name() << "\n";
    }
    ofile.close();
}
