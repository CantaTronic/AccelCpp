
#include "Analysis.h"
#include <algorithm>
#include "grade.h"
#include "median.h"
// #include "average.h"

using std::string;
using std::endl;
using std::cout;

double median_analysis(const studFile& stud) {
    doubleCont grades;  
    transform(stud.begin(), stud.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

double average_analysis(const studFile& stud){
    doubleCont grades;  
    transform(stud.begin(), stud.end(), back_inserter(grades), average_grade);
    return median(grades);
}

double opt_median_analysis(const studFile& stud){
  doubleCont grades;  
  transform(stud.begin(), stud.end(), back_inserter(grades), opt_median);
  return median(grades);
}

void  write_analysis (std::ostream & out, const string an_name, double analysis (const studFile&), studFile& did, studFile& didnt) {
  out<<an_name<<"(did) = "<<analysis(did)<<", \t"<<an_name<<"(didn't) = "<<analysis(didnt)<<endl;
} 
