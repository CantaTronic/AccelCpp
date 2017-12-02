
//source file for Student_info-related functions
#include "Student_info.h"
#include "grade.h"

using std::istream; using std::vector;

bool compare (const Student_info &x,const Student_info &y){
    return x.name<y.name;
}

bool fgrade (const Student_info & s) {
  return grade(s) < 60;
}
//the first variant: need a lot of memory
// vector<Student_info> extract_fails(vector<Student_info>& students)  {
//   vector<Student_info> fail, pass;
//   
//   for (vector<Student_info>::size_type i = 0; i != students.size(); i++)  {
//     if (fgrade(students[i])) {
//       fail.push_back(students[i]);
//     } else {
//       pass.push_back(students[i]);
//     }
//   }
//   students = pass;
//   return fail;
// }

// //the second variant, then we try to use more optimal data structure 
// vector<Student_info> extract_fails(vector<Student_info>& students)  {
//   vector<Student_info> fail;
//   vector<Student_info>::size_type i = 0;
//   
//   // invariante elements [0, i) of students represent passing grades
//   while (i != students.size()) {
//     if (fgrade(students[i])) {
//       fail.push_back(students[i]);
//       students.erase(students.begin() + i);
//     } else 
//         i++;
//   }
//   return fail;
// }

//the third variant, even more based on iterators
vector<Student_info> extract_fails(vector<Student_info>& students)  {
  vector<Student_info> fail;
  vector<Student_info>::iterator iter = students.begin();
  while(iter != students.end()) {
    if (fgrade(*iter)){
      fail.push_back(*iter);
      iter = students.erase(iter);
    } else
      iter++;
  }
  return fail;
}

bool read (istream& is, Student_info& s) {
    //read and store the student's name and midterm and final exam grades
    std::string name;
    is >> name; 
    if (name != "end") {
      s.name = name;
      is>> s.midterm >> s.final;
      std::cout<<std::flush;
      read_hw(is, s.homework); //readandstore all the student's homework grades
      return true;
    }
    return false;
}

/*
 read homework grades form aninput stream into a'vector'
 */
istream& read_hw(istream& in, vector<double>& hw){
    if (in) {
        //get rid ofprevious contexts
        hw.clear();
        
        //read the homework grades
        double x;
        in>>x;
        while (x != 0){
            hw.push_back(x);
            in >> x;
        }
        //clear the stream so that input will work forthe next student
        in.clear();
    }
    return in;
}
