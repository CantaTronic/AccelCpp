
#ifndef analysis_h
#define analysis_h

#include "Student_info.h"
#include "contType.h"
#include "median.h"
#include <algorithm>
#include <iostream>
#include <string>

double median_analysis(const studFile& stud) {
    doubleCont grades;  
    transform(stud.begin(), stud.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

void write_analysis(std::ostream& out, std::string name, double analysis(const studFile& stud), studFile did, studFile didnt) {
  out<<name<<": median (did) "<<analysis(did)<<" median (didnt) "<<analysis(didnt)<<std::endl;
}

#endif
