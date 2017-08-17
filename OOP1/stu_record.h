#ifndef _STU_RECORD_
#define _STU_RECORD_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StudentRecord;

class course{
public:
    course() {}
    friend class StudentRecord;
    friend istream& operator>>(istream& in, vector<course>& courses);
    friend istream& operator>>(istream& in, vector<StudentRecord>& s_records);
    friend ostream& operator<<(ostream& out, vector<StudentRecord>& s_records);

private:
    string course_name;
    int score;
};

class StudentRecord{
	public:
	StudentRecord() {}
    friend istream& operator>>(istream& in, vector<course>& courses);
    friend istream& operator>>(istream& in, vector<StudentRecord>& s_records);
    friend ostream& operator<<(ostream& out, vector<StudentRecord>& s_records);

	private:
	int stu_id;
	string name;
    vector<course> courses;
	double avr_score;
};

#endif
