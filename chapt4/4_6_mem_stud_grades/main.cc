
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
// #include <stdio.h>  //for color printing
/*see escape settings here: habrahabr.ru/post/94647/
 * \033[33m - yellow
 * \033[32m - green
 * \033[34m - blue
 * \033[36m - cyan
 * \033[0m - return to the color-by-default
 */


using std::cin;		using std::cout;
using std::endl;	using std::domain_error;
using std::sort;	using std::setprecision;
using std::streamsize;	using std::string;
using std::max;		using std::vector;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;	//the lenth of the longest name
	string pat = "Surname midterm_grade final_grade all_homework_grades_separated_by_spaces";
    string ast = string(pat.size()+3,'*');
	
	cout<<ast<<"\n\t\tWelcome to our grade calculating program! \n"<<endl;
    cout<<"Please, enter an information about every student using the next pattern: \n\n"
    "\033[33mSurname\033[0m \033[32mmidterm_grade \033[0m\033[33m\033[34mfinal_grade \033[33m"
    "\033[36mall_homework_grades_separated_by_spaces \033[0m\n\n"
    "To finish data entering press \' sign.\n"<<ast<<endl;
	
	//read and store all the students data.
	//Invariant: studnts contains all the student records read so far
	//maxlen contains the length of the longest name in students
	while (read(cin, record)) {
		//find length of longest name
		maxlen = max (maxlen, record.name.size());
		students.push_back(record);
	}
	
	//sort the student records by alphabet
	sort(students.begin(), students.end(), compare);
	
    cout<<"THE FINAL GRADES ARE:"<<endl;
    
	//write the names and grades
	for (vector<Student_info>::size_type i = 0; i != students.size(); i++) {
		//write the name, padded on the right to maxlen + 1 characters
		cout<< students[i].name
		<<string(maxlen + 1 - students[i].name.size(), ' ');

// 		//compile and write the grade
// 		try{
// 			grade(students[i]);
			streamsize prec = cout.precision();
			cout<<setprecision(3)<<students[i].courseGrade
			<<setprecision(prec);
// 		} catch (domain_error e) {
// 			cout<<e.what();
// 		}
		cout<<endl;
	}
	return 0;
}











