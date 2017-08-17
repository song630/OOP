#ifndef _BASIC_H_
#define _BASIC_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#define MAX_CAPACITY 20
using namespace std;

class Diary {
public:
    Diary() {}
    void set_date(const string &_date) {
        date = _date; // automatically converted to inline if defined inside class
    }
    void set_title(const string &_title) {
        file_name = _title;
    }
    string get_date() const {
        return date;
    }
    string get_name() const {
        return file_name;
    }
    void init();
    void show_content() const;
    bool remove_diary();
    ~Diary() {}

private:
    string date;
    string file_name;
};

struct DiaryRecord {
    DiaryRecord(): total(0) {} // initialize the number of diaries to 0
    int total;
    Diary record_by_date[MAX_CAPACITY];
};

struct DiaryRecord Record;

#endif
