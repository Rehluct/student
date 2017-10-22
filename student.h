#include <string>
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cctype>
#include <iomanip>
using namespace std;

class Student
{
public:
	void print(ofstream& out1);
	virtual int getfinal()=0;
	char grade();
	string course;
	char gradey;
protected:
	Student(string,string,string);
	Student ();
	string firstname;
	string lastname;
		
	
	double avg;
	int finalExam;
};

class computerScience : public Student
{	
public:
	
	computerScience(string,string,string ,ifstream& infile);
	computerScience(const computerScience& ); //copy
	computerScience();
	int getfinal();
	void finalavg();
private:
	int programGrades[6];
	int	twoTest[2];
	
};

class Biology : public Student
{
public:
	Biology(string,string,string ,ifstream& infile);
	int getfinal();
	void finalavg();

private:
	int labGrade;
	int	threeTest[3];
};

class Theater : public Student
{	
public:
	Theater(string,string,string ,ifstream& infile);
	int getfinal();
	void finalavg();
private:
	int participation;
	int midterm;
};

