
//source file for Student_info-related functions
#include "Student_info.h"
#include "grade.h"
#include <iterator>

using std::begin;   using std::end;
using std::istream; using std::vector;

bool compare (const Student_info &x,const Student_info &y){
    return x.name<y.name;
}

bool read (istream& is, Student_info& s) {
    //read and store the student's name and midterm and final exam grades
    double midterm, final;  //in this version these variables are local
    std::string name;
    is >> name;
    if (name != "end") {
        s.name = name;
        is >> midterm >> final;
        std::cout<<std::endl;
//         std::cout<<"midterm = "<< midterm << ", final = " << final<<std::endl;
        std::vector<double> homework;   //local as well
        read_hw(is, homework);      //readandstore all the student's homework grades

//         for (vector<double>::size_type i = 1; i != homework.size(); i++)
//             std::cout<<i<<"\t"<<homework[i]<<std::endl;

        s.courseGrade = grade (midterm, final, homework);

//         std::cout<<"courseGrade = "<<s.courseGrade<<std::endl;
        return true;
    } else {
        return false;
    }
}

/*
 read homework grades form aninput stream into a'vector'
 */
istream& read_hw(istream& in, vector<double>& hw){
    if (in) {
        //get rid ofprevious contexts
        hw.clear();
        
        //read the homework grades
        int x;
        while (x > 0) {
            hw.push_back(x);
            in >> x;
        }
//         for (vector<double>::size_type i = 1; i != hw.size(); i++)
//             std::cout<<i<<"\t"<<hw[i]<<std::endl;
        //clear the stream so that input will work forthe next student
        in.clear();
    }
    return in;
}
