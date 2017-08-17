#ifndef _STU_RECORD
#define _STU_RECORD

#include <string>

class StudentRecord{
	public:
	StudentRecord(): stu_id(0), score1(0), score2(0), score3(0), avr_score(0.0){}
	void SetRecord(int in_id, std::string in_name, int score1, int score2, int score3);
    void PrintRecord() const;
    friend void Average(const StudentRecord *stu);//gain access to private members
    friend void FindMin(const StudentRecord *stu);
    friend void FindMax(const StudentRecord *stu);
    
	private:
	int stu_id;
	std::string name;
	int score1, score2, score3;
	double avr_score;
};

#endif
