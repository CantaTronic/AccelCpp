 
#ifndef Analysis_h
#define Analysis_h

#include <iostream>
#include <string>
#include "contType.h"
#include "anTypes.h"

using std::string;

double full_analysis(const studFile& stud, analysisType anType = kmedian);

double median_analysis(const studFile&);

double average_analysis(const studFile&);

double opt_median_analysis(const studFile&);

void  write_analysis (std::ostream &, const analysisType anType, /*double analysis (const studFile&),*/ studFile& , studFile&);

#endif
 
