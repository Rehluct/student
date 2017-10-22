#include "student.h"


Student::Student(string l,string f,string major)
{
	lastname = l;
	firstname = f;
	course = major;
	
};
Student::Student()
{
	lastname = " ";
	firstname = " ";
	course = " ";
};

computerScience::computerScience(string l,string f,string major,ifstream& infile):Student(l,f,major)
{
		
	for (int i = 0; i < 6; i++)
	{
		infile >> programGrades[i];
		infile.ignore();
	}
	infile >> twoTest[0];
	infile.ignore();
	infile >> twoTest[1];
	infile.ignore();
	infile >> finalExam;
	finalavg();
};



computerScience::computerScience(const computerScience& cs) //copy
:Student(cs.lastname,cs.firstname,cs.course)
{
	for (int i = 0; i < 6; i++)
	{
		 programGrades[i]= cs.programGrades[i]+1;
	}
	
};


Biology::Biology(string l,string f,string major,ifstream& infile):Student(l,f,major)
{
	infile >>labGrade;
	infile.ignore();
	
	for (int i = 0; i < 3; i++)
	{
		infile >> threeTest[i];
		infile.ignore();
	}
	infile >>finalExam;
	
	finalavg();
};


Theater::Theater(string l,string f,string major,ifstream& infile):Student(l,f,major)
{
	char g;
	infile >>participation>>midterm>>finalExam;
	finalavg();

};


int Theater::getfinal()
{
		return finalExam;
}

int Biology::getfinal()
{
		return finalExam;
}

int computerScience::getfinal()
{
		return finalExam;
}
void computerScience::finalavg()
{
	double sum=0;
	
	for(int i = 0; i< 6;i++)
	{
	sum = programGrades[i] +sum;	
	}
	sum = sum /6;
	
	sum = sum * .3;//26.55 +16+18.2+27.6
	avg = (twoTest[0] * .2)+(twoTest[1] * .2)+(finalExam *.3)+sum;	
}

void Biology::finalavg()
{
	double sum=0;
	for(int i = 0; i< 3;i++)
	{
	sum = (threeTest[i] * .15)+sum;	
	
	}
	avg = (labGrade *.3) +(finalExam * .25)+ sum;
}

void Theater::finalavg()
{
	avg = (participation * .4) + ( midterm *.25) +(finalExam *.35);
}

void Student::print(ofstream& out1)
{	
grade();
out1 << setw(10)<<left<<firstname<<setw(32)<<left<<lastname<<setw(10)<<finalExam<< setw(10)<<setprecision (2) << fixed<< avg<<setw(10)<<gradey<<endl;

}

char Student::grade()
{
	if (avg > 89)
	{
		gradey = 'A';
		return gradey;
	}
	if (avg >79 && avg < 90)
	{
		gradey = 'B';
		return gradey;
	}
	if (avg >69 && avg < 80)
	{
		gradey = 'C';
		return gradey;
	}
	if (avg >59 && avg < 70)
	{
		gradey = 'D';
		return gradey;
	}
	
	if (avg < 59)
	{
		gradey = 'F';
		return gradey;
	}
	
}



