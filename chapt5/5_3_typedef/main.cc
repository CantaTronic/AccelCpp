
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include "grade.h"
#include "Student_info.h"
#include "contType.h"
#include <fstream>
// #include <stdio.h>  //for color printing
/*see escape settings here: habrahabr.ru/post/94647/
 * \033[33m - yellow
 * \033[32m - green
 * \033[34m - blue
 * \033[36m - cyan
 * \033[0m - return to the color-by-default
 */


using std::cout;        using std::max;	
using std::endl;	using std::domain_error;
using std::sort;	using std::setprecision;
using std::streamsize;	using std::string;
using std::fstream;

int main()
{
        fstream file;
        file.open ("test.txt");
	studFile students;
	Student_info record;
	string::size_type maxlen = 0;	//the lenth of the longest name
	
	//read and store all the students data.
	//Invariant: studnts contains all the student records read so far
	//maxlen contains the length of the longest name in students
	while (read(file, record)) {
		//find lengthoflongestname
		maxlen = max (maxlen, record.name.size());
		students.push_back(record);
	}
	file.close();
	//sort the student records by alphabet
	sort(students.begin(), students.end(), compare);
	
        cout<<"THE FINAL GRADES ARE:"<<endl;
    
	//write the names and grades
	for (iter stud = students.begin(); stud != students.end(); stud++) {
		//write the name, padded on the right to maxlen + 1 characters
		cout<< stud->name <<string(maxlen + 1 - stud->name.size(), ' ');

		//compile and write the grade
		try{
			double final_grade = grade(*stud);
			streamsize prec = cout.precision();
			cout<<setprecision(3)<<final_grade
			<<setprecision(prec);
		} catch (domain_error e) {
			cout<<e.what();
		}
		cout<<endl;
	}
	return 0;
}











