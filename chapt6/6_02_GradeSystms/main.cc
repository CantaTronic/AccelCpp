
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
#include "container.h"
#include "tests.h"
#include "analysis.h"

using std::cout;        using std::max;	
using std::endl;	using std::domain_error;
using std::sort;	using std::setprecision;
using std::streamsize;	using std::string;
using std::fstream;

string::size_type separate(string fname, studFile& did, studFile& didnt);

int main()
{
       /* fstream file;
        file.open ("test.txt");
	studFile students;
	Student_info record;
// 	string::size_type maxlen = 0;	//the lenth of the longest name
	
	//read and store all the students data.
	//Invariant: studnts contains all the student records read so far
	//maxlen contains the length of the longest name in students
	while (read(file, record)) {
		//find lengthoflongestname
		maxlen = max (maxlen, record.name.size());
		students.push_back(record);
	}
	file.close();
	*/
        studFile did, didnt;
        string::size_type maxlen = separate("test.txt", did, didnt);
        //a bit of control print
        cout<<"did:"<<endl;
        printStudVec(did);
        cout<<"didnt:"<<endl;
        printStudVec(didnt);
        
        cout<<"maxlen: "<<maxlen<<endl;
        
        //analysis:
        write_analysis(std::cout, "median analysis ", median_analysis, did, didnt);
        
        return 0;
        
// 	//sort the student records by alphabet
//         #ifdef VECT
// // 	sort(students.begin(), students.end(), compare);
//         sort(begin(students), end(students), compare);
//         #endif
//         #ifdef LIST
//         students.sort(compare);
//         #endif
//         
//         testAllHW(students);
//         
//         cout<<"THE FINAL GRADES ARE:"<<endl;
//     
// 	//write the names and grades
// 	for (iter stud = students.begin(); stud != students.end(); stud++) {
// 		//write the name, padded on the right to maxlen + 1 characters
// 		cout<< stud->name <<string(maxlen + 1 - stud->name.size(), ' ');
// 
// 		//compile and write the grade
// 		try{
// 			double final_grade = grade(*stud);
// 			streamsize prec = cout.precision();
// 			cout<<setprecision(3)<<final_grade
// 			<<setprecision(prec);
// 		} catch (domain_error e) {
// 			cout<<e.what();
// 		}
// 		cout<<endl;
// 	}
// 	return 0;
}

string::size_type separate(string fname, studFile& did, studFile& didnt) {
    fstream file;
    file.open (fname);
    Student_info record;
    string::size_type maxlen = 0;
    
    while (read(file, record)) {
            //find lengthoflongestname
            maxlen = max (maxlen, record.name.size());
            if (did_all_hw(record)) {
              did.push_back(record);
            } else {
              didnt.push_back(record);  
            }
    }
    file.close();
    if (did.empty()) {
      cout<<"No students, who did all homework"<<endl;
      return 1;
    }
    if (didnt.empty()) {
      cout<<"All students did all homework :)"<<endl;
      return 1;
    }
    return maxlen;
}
