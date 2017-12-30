
#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include "hw_cont.h"

double grade_aux(const Student_info& s);
double average_grade(const Student_info& s);
bool fgrade (const Student_info & s);
double grade(double, double, double);
double grade (double, double, const doubleCont&);
double grade(const Student_info&);

#endif
