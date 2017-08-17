#include "func.cpp"
using namespace std;

int main(void)
{
	StudentRecord student[10];
	int in_id, in_score1, in_score2, in_score3;
	string in_name;
	cout<<"Enter records of 10 students:"<<endl;
	for(int i=0; i<=9; i++)
	{
		cin>>in_id>>in_name>>in_score1>>in_score2>>in_score3;
		student[i].SetRecord(in_id, in_name, in_score1, in_score2, in_score3);
	}
	cout<<"no"<<"   "<<"name"<<"     "<<"score1"<<" "<<"score2"//print the titles
	    <<" "<<"score3"<<" "<<"average"<<endl;
	for(int i=0; i<=9; i++)
		student[i].PrintRecord();//print record of each student
	Average(student);//calculate and print the average score of score1, 2, and 3
	FindMin(student);//find and print the minimum
	FindMax(student);//find and print the maximum
	system("pause");
}
