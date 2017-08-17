#include "func.cpp"
#include <cstdlib>
using namespace std;

int main(void)
{
    vector<StudentRecord> s_records;
	cout << "Enter records of students:" << endl;
	cin >> s_records; // type in -1 to end input of one student's courses
	                  // type in -1 again to end input of all students'info
    cout << s_records;

	system("pause");
	return 0;
}