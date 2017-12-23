
#include "Analysis.h"
#include <algorithm>
#include "grade.h"
#include "median.h"

using std::string;
using std::endl;
using std::cout;

double median_analysis(const studFile& stud) {
    doubleCont grades;  
    transform(stud.begin(), stud.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

void  write_analysis (std::ostream & out, const string an_name, double analysis (const studFile&), studFile& did, studFile& didnt) {
  out<<an_name<<"(did) = "<<analysis(did)<<", \t"<<an_name<<"(didn't) = "<<analysis(didnt)<<endl;
} 
