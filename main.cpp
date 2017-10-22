#include "student.h"
#include <fstream> 
#include <iostream> 
#include <cstdlib>
#include <cctype>

 using namespace std;
 
 int main()
{
	int size;
	ifstream fin;
	ofstream out1;
	string file,ofile,fname,lname,major,csr;
	int num;
	
	cout<<"Please enter the name of the input file."<<endl;
	cout<<"Filename: ";
	cin >> file;
	cout<<"\n\n";

	
	cout<<"Please enter the name of the output file. "<<endl;
	cout<<"Filename: ";
	cin>>ofile;
	
	fin.open(file.c_str());
	out1.open(ofile.c_str());
	
	if (!fin)			// if the open failed
   {
      cout << "Attempt to open file failed\n";
      exit(1);
   }
   
   
   if (!out1)			// if the open failed
   {
      cout<< "Attempt to write file failed\n";
      exit(1);
   }
   
   
   fin>>size;
   
   
   //Biology bio;
   //Theater	* arts;
   
   
  Student ** list = new Student* [size];
   

	for(int i =0; i <size; i++)
	{
		char g;
		fin.ignore();
	   getline(fin, fname, ',');
	   fin.ignore();
	   getline(fin, lname,'\n');
	   getline(fin, major,' ');
	   if (!(isdigit(fin.peek())))
	   {
		   getline(fin, csr,' '); 
		   major = major+" "+csr;
	   }
	   
	   if ( major == "Computer Science")
	   {
		   list[i] = new computerScience(fname,lname,major,fin);
		  
	   }
	   if (major == "Biology")
	   {
		   list[i] = new Biology(fname,lname,major,fin);
	   }
	   if (major == "Theater")
	   {
		   list[i] = new Theater(fname,lname,major,fin);
	   }
	  
	}
	
	fin.close();
	
	out1<<"\n\nStudent Grade Summary"<<"\n--------------------- "<<endl;
	
	int count =0;
	for(int i =0; i <size; i++)
	{
		if (list[i]-> course == "Biology" && count == 0)
		{
		count = 1;
		out1<<"\nBIOLOGY CLASS"<<endl;
		out1<<setw(41)<<left<<"\nStudent"<<setw(10)<<"Final"<<setw(10)<<"Final"<<setw(5)<<"Letter"<<endl;
		out1<<setw(41)<<left<<"Name"<<setw(10)<<"Exam"<<setw(10)<<"Avg"<<setw(5)<<"Grade"<<endl;
		out1<<"-------------------------------------------------------------------"<<endl;
		}
		if (list[i]-> course == "Biology")
		{
			list[i]->print(out1);
		}
	}
	
	 
	count =0;
	for(int i =0; i <size; i++)
	{
		if (list[i]-> course == "Theater"&& count == 0)
		{
			count = 1;
		out1<<"\nTHEATER CLASS"<<endl;
		out1<<setw(41)<<left<<"\nStudent"<<setw(10)<<"Final"<<setw(10)<<"Final"<<setw(5)<<"Letter"<<endl;
		out1<<setw(41)<<left<<"Name"<<setw(10)<<"Exam"<<setw(10)<<"Avg"<<setw(5)<<"Grade"<<endl;
		out1<<"-------------------------------------------------------------------"<<endl;
		}
		if (list[i]-> course == "Theater")
		{
			list[i]->print(out1);
		}
	}
	   
	count =0;
	for(int i =0; i <size; i++)
	{
		if (list[i]-> course == "Computer Science"&& count == 0)
		{
			count = 1;
		out1<<"\nCOMPUTER SCIENCE CLASS"<<endl;
		out1<<setw(41)<<left<<"\nStudent"<<setw(10)<<"Final"<<setw(10)<<"Final"<<setw(5)<<"Letter"<<endl;
		out1<<setw(41)<<left<<"Name"<<setw(10)<<"Exam"<<setw(10)<<"Avg"<<setw(5)<<"Grade"<<endl;
		out1<<"-------------------------------------------------------------------"<<endl;
		}
		if (list[i]-> course == "Computer Science")
		{
			list[i]->print(out1);
		}
	}

	int alpha =0;
	int bravo=0;
	int charlie =0;
	int delta=0;
	int fox =0;
	for(int i =0; i <size; i++)
	{
		if(list[i]->gradey == 'A')
		{
			alpha++;
			cout<<list[i]->gradey<<alpha<<endl;
		}
		
		if(list[i]->gradey == 'B')
		{
			bravo++;
			cout<<list[i]->gradey<<bravo<<endl;
		}
		
		if(list[i]->gradey == 'C')
		{
			charlie++;
			cout<<list[i]->gradey<<charlie<<endl;
		}
		
		if(list[i]->gradey == 'D')
		{
			delta++;
			cout<<list[i]->gradey<<delta<<endl;
		}
		if(list[i]->gradey == 'F')
		{
			fox++;
			cout<<list[i]->gradey<<fox<<endl;
		}

	}
	
	out1<<"\n\nOVERALL GRADE DISTRIBUTION"<<endl;
	
	out1<<"\nA:  "<<alpha<<endl;
	out1<<"B:  "<<bravo<<endl;
	out1<<"C:  "<<charlie<<endl;
	out1<<"D:  "<<delta<<endl;
	out1<<"F:  "<<fox<<endl;
   

	 
 }