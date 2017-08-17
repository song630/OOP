#include "stu_record.h"
#include <iostream>
#include <iomanip>
using namespace std;

void StudentRecord::SetRecord(int in_id, string in_name, 
                    int in_score1, int in_score2, int in_score3)
{
	stu_id=in_id;
	name=in_name;
	score1=in_score1;
	score2=in_score2;
	score3=in_score3;
	avr_score=(score1+score2+score3)/3.0;
}

void StudentRecord::PrintRecord() const
{
	cout<<left<<setw(5)<<stu_id<<left<<setw(9)<<name<<score1<<"      "//make the string occupy a certain length of space in output
	    <<score2<<"      "<<score3<<"      "<<avr_score<<endl;
}

void Average(const StudentRecord *stu)
{
	double avr_score1=0, avr_score2=0, avr_score3=0;
	for(int i=0; i<=9; i++)
	{
		avr_score1+=stu[i].score1;
		avr_score2+=stu[i].score2;
		avr_score3+=stu[i].score3;
	}
	cout<<"     "<<left<<setw(9)<<"average"<<avr_score1/10.0
	    <<"    "<<avr_score2/10.0<<"    "<<avr_score3/10.0<<endl;
} 

void FindMin(const StudentRecord *stu)
{
	int min_score1=stu[0].score1,
	    min_score2=stu[0].score2,
	    min_score3=stu[0].score3;
	for(int i=1; i<=9; i++)
	{
		if(min_score1>stu[i].score1)
		min_score1=stu[i].score1;
		if(min_score2>stu[i].score2)
		min_score2=stu[i].score2;
		if(min_score3>stu[i].score3)
		min_score3=stu[i].score3;
	}
	cout<<"     "<<"min"<<"      "<<min_score1<<"      "
	    <<min_score2<<"      "<<min_score3<<endl;
}

void FindMax(const StudentRecord *stu)//const: cannot modify the object the pointer points to
{
	int max_score1=stu[0].score1,
	    max_score2=stu[0].score2,
	    max_score3=stu[0].score3;
	for(int i=1; i<=9; i++)
	{
		if(max_score1<stu[i].score1)
		max_score1=stu[i].score1;
		if(max_score2<stu[i].score2)
		max_score2=stu[i].score2;
		if(max_score3<stu[i].score3)
		max_score3=stu[i].score3;
	}
	cout<<"     "<<"max"<<"      "<<max_score1<<"      "
	    <<max_score2<<"      "<<max_score3<<endl;
}
