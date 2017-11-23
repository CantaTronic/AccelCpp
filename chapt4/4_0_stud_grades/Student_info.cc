
//source file for Student_info-related functions
#include "Student_info.h"

using std::istream; using std::verctor;

bool compare (const Student_info &x,const Student_info &y){
    return x.name<y.name;
}

istream& read (istream& is, Student_info& s) {
    //read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;
    
    rad_hw(is, s.homework); //readandstore all the student's homework grades
    return is;
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
        while (in >> x)
            hw.push_back(x);
        
        //clear the stream so that input will work forthe next student
        in.clear();
    }
    return in;
}