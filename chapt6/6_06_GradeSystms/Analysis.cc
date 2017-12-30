
#include "Analysis.h"
#include <algorithm>
#include "grade.h"
#include "median.h"

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

//add func for ex. 8, ch. 6
studFile extract_fails(studFile& students){
  studFile fail;
  iter it = students.begin();
  while(it != students.end()) {
    if (fgrade(*it)){
      fail.push_back(*it);
      it = students.erase(it);
    } else
      it++;
  }
  return fail;
}
