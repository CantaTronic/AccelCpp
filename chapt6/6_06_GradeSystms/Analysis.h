 
#ifndef Analysis_h
#define Analysis_h

#include <iostream>
#include <string>
#include "contType.h"
#include "anTypes.h"

using std::string;

double full_analysis(const studFile& stud, analysisType anType = kmedian);
void  write_analysis (std::ostream &, const analysisType anType, studFile& , studFile&);
studFile extract_fails(studFile& students);
studFile divide(studFile& students, bool criteria (const Student_info& s));

#endif
 
