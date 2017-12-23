
#include "Analysis.h"
#include <algorithm>
#include "grade.h"

using std::string;

double median_analysis(const studFile& stud) {
    doubleCont grades;  
    transform(stud.begin(), stud.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

void  write_analysis (istream & is, const string an_name, double analysis (const studFile&), studFile& did, studFile& didnt) {
  out<<an_name<<"(did) = "<<analysis(did)<<", \t"<<an_name<<"(didn't) = "<<analysis(didnt)<<endl;
} 
