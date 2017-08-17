#include "basic.h"
#include "data_file.cpp"
using namespace std;

// extern int top;

string titles[] = {"1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt",
                   "7.txt", "8.txt", "9.txt", "10.txt", "11.txt", "12.txt",
                   "13.txt", "14.txt", "15.txt", "16.txt", "17.txt", "18.txt",
                   "19.txt", "20.txt"};

void save_modification(); // store to an external record file

void recover_data(); // read all data into memory at beginning of the program

int main(int argc, char *argv[])
{
    recover_data();
    if(!argv[1]) // no input date
    {
        cout << "Please enter the date as YYYY/MM/DD.\n";
        exit(1); // terminate
    }
    // three branches: no existing files, some exists but one of them has the same date as input,
    // and some exists and none of them has the same date as input.
    string title, path("D://code_blocks/Projects/OOP4/"), path_title;

    if(Record.total == 0) // no file exists
    {
        Diary new_dairy;
        new_dairy.set_date(argv[1]); // store the date===============
        if(top > 19)
        {
            cout << "Out of space.\n";
            exit(1);
        }
        new_dairy.set_title(titles[top++]); // set the title
        Record.record_by_date[Record.total++] = new_dairy; // record it
        title = new_dairy.get_name();
    }
    else // some files already exist
    {
        bool flag = false; // whether there is a piece of diary of the same date
        int i;
        for(i = 0; i <= Record.total; i++)
        {
            if(Record.record_by_date[i].get_date() == argv[1]) // found
            {
                flag = true;
                break;
            }
        }
        if(flag) // found
            title = Record.record_by_date[i].get_name(); // cover the previous file of the same date
        else // not found
        {
            Diary new_dairy;
            new_dairy.set_date(argv[1]); // store the date
            if(top > 19)
            {
                cout << "Out of space.\n";
                exit(1);
            }
            new_dairy.set_title(titles[top++]); // set the title
            Record.record_by_date[Record.total++] = new_dairy; // record it
            title = new_dairy.get_name();
        }
    }
    // begin to write

    path_title = path + title; // merge two strings to get the path
    ofstream myfile(path_title.c_str()); // use c.str() to convert a variable to filename
    if(!myfile)
    {
        cout << "Failed to open.\n";
        exit(1);
    }
    else
        cout << "Succeed.\n";
    string input;
    while(cin >> input) // write dairy
        myfile << input << "\n";
    myfile.close();
    save_modification();

    return 0;
}
