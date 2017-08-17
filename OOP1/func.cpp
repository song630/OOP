#include "stu_record.h"
#include <iomanip>
using namespace std;

istream& operator>>(istream& in, vector<StudentRecord>& s_records)
{
    int in_id;
    string in_name;
    while(1)
    {
		in >> in_id; // input student's id
		if(in_id == -1) // the info of one student is done
			break;
		in >> in_name;  // input student's name
        StudentRecord student; // a new record of one student
        student.stu_id = in_id;
        student.name = in_name;
		cin >> student.courses;

		vector<course>::iterator i; // calculate the average score of one student
		int count = 0;
		student.avr_score = 0.0;
		for(i = student.courses.begin(); i != student.courses.end(); i++)
		{
			student.avr_score += (*i).score;
			count++;
		}
		student.avr_score /= (double)count;
		s_records.push_back(student); // ======after push_back(), any operations about student cannot actually change it
    }
    return in;
}

istream& operator>>(istream& in, vector<course>& courses)
{
	string in_course_name;
	int in_score;
	while(1)
	{
		in >> in_course_name; // input a course's name
		if(in_course_name == "-1")
			break;
		in >> in_score; // input the course's score
		course one_course; // one of the courses of one student
		one_course.course_name = in_course_name;
		one_course.score = in_score;
		courses.push_back(one_course);
	}
	return in;
}

ostream& operator<<(ostream& out, vector<StudentRecord>& s_records)
{
    for(vector<StudentRecord>::iterator iter = s_records.begin();
	          iter != s_records.end(); iter++)
    {
        out << left << setw(4) << (*iter).stu_id << left << setw(8) << (*iter).name; // (*iter) represents one student
		vector<course>::iterator i;
        for(i = (*iter).courses.begin(); i != (*iter).courses.end(); i++)
			out << left << setw(8) << (*i).course_name << left << setw(3) << (*i).score; // (*i) represents one of the courses of one student
		out << left << setw(8) << "average" << left << setw(4) << (*iter).avr_score << endl;
    }
    return out;
}