#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int x, y, z;

    char temperatures[3] = {'K', 'F', 'C'};
    char vowels[5] = {'A', 'E', 'I', 'O', 'U'};
    char directions[4] = {'N', 'S', 'E', 'f'};
    char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    cout << "None of these are 'c-strings'.  What if we print with << ?\n";

    cout << "temperatures = " << temperatures << '\n';
	cout << "vowels = " << vowels << '\n';
	cout << "directions = " << directions << '\n';
    cout << "digits = " << digits << '\n';
	
	char buffer[10];
	char buffer1[2];
	cout << "\n\nVowels into buffer"<<endl;
	strcpy(buffer,vowels);
	
	cout<<"Buffer ::"<<buffer<<"  Vowels ::"<<vowels<<endl;
	
	cout << "\n\nVowels into buffer 1 smaller size"<<endl;
	strcpy(buffer1,directions);
	
	cout<<"Buffer ::"<<buffer1<<"  Directions ::"<< directions <<endl;
	
   
   



}