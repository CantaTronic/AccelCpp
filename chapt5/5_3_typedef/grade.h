
#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include "hw_cont.h"
#include <vector>
#include <list>

double grade(double, double, double);
double grade (double, double, const doubleCont&);
// double grade (double, double, const std::vector<double>&);
// double grade (double, double, const std::list<double>&);
double grade(const Student_info&);

#endif
