
#include "Analysis.h"
#include <algorithm>
#include "grade.h"
#include "median.h"
// #include "average.h"

using std::string;
using std::endl;
using std::cout;

double full_analysis(const studFile& stud, analysisType anType) {
  doubleCont grades; 
  double (*f)(const Student_info& s);
  switch (anType) {
    case kaverage: 
      f = average_grade;
      break;
    case kopt_median:
      f = opt_median;
      break;
    default:
      f = grade_aux;
  }
  transform(stud.begin(), stud.end(), back_inserter(grades), f);
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

void  write_analysis (std::ostream & out, const analysisType anType, studFile& did, studFile& didnt) {
  switch (anType) {
    case kaverage: 
      out<<"Average_grade analysis: "<<endl;
      break;
    case kopt_median:
      out<<"Optimistic median analysis: "<<endl;
      break;
    default:
      out<<"Median analysis: "<<endl;
  }
  out<<"(did) = "<<full_analysis(did, anType)<<", \t(didn't) = "<<full_analysis(didnt, anType)<<endl;
} 
