
//source file for Student_info-related functions
#include "Student_info.h"
#include "grade.h"
#include <cctype>

using std::istream; using std::string;
using std::cout;    using std::endl;

bool compare (const Student_info &x,const Student_info &y){
    return x.name<y.name;
}

bool compareNum (double a, double b) {
  return a<b;
}

bool read (istream& is, Student_info& s) {
    //read and store the student's name and midterm and final exam grades
    std::string name;
    is >> name;
    if (name != "") {
      s.name = name;
      is>> s.midterm >> s.final;
      std::cout<<std::flush;
      read_hw(is, s.homework); //readandstore all the student's homework grades
      return true;
    }
    return false;
}

void printStudInfo(Student_info& s) {
  /*test function*/
  std::cout<<"name: "<<s.name<<std::endl;
  std::cout<<"midterm: "<<s.midterm<<std::endl;
  std::cout<<"final: "<<s.final<<std::endl;
  printVec(s.homework);
}

void printVec (const doubleCont vect) {
  cout<<"size = "<<vect.size()<<endl;
//   for (vec_sz i = 0; i < vect.size() - 1; i++)
  for (DCiterC it = vect.begin(); it != vect.end(); it++)
    cout<<(*it)<<", ";
  cout<<endl;
//   cout<<vect[vect.size() - 1]<<endl;
  
}

/*
 read homework grades form aninput stream into a'vector'
 */
istream& read_hw(istream& in, doubleCont& hw){
    if (in) {
        //get rid ofprevious contexts
        hw.clear();
        
        //read the homework grades
        double x;
        while (in>>x) 
          hw.push_back(x);
        //clear the stream so that input will work forthe next student
        in.clear();
    }
    return in;
}
