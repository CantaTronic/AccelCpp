
#include "Analysis.h"
#include <algorithm>
#include "grade.h"
#include "median.h"
// #include "average.h"

using std::string;
using std::endl;
using std::cout;

double full_analysis(const studFile& stud, string name/*="median"*/) {
  doubleCont grades; 
//   double (*f)(const Student_info& s);
  if (name == "median") {
    transform(stud.begin(), stud.end(), back_inserter(grades), grade_aux);
  };
  if (name == "average") {
    transform(stud.begin(), stud.end(), back_inserter(grades), average_grade);
  };
  if (name == "opt_median"){
    transform(stud.begin(), stud.end(), back_inserter(grades), opt_median);
  }
  return median(grades); 
}

double median_analysis(const studFile& stud) {
    doubleCont grades; 
//     double f(const Student_info& s)
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

void  write_analysis (std::ostream & out, const string an_name/*, double analysis (const studFile&)*/, studFile& did, studFile& didnt) {
  out<<an_name<<"(did) = "<<full_analysis(did, an_name)<<", \t"<<an_name<<"(didn't) = "<<full_analysis(didnt, an_name)<<endl;
} 
