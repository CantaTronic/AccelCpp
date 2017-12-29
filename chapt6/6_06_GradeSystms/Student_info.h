
#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

//Students_info.h

#include <iostream>
#include <string>
#include <vector>
#include "hw_cont.h"

struct Student_info {
	std::string name;
	double midterm, final;
	doubleCont homework;
};

bool compare (const Student_info&, const Student_info&);
bool compareNum (double a, double b);
bool did_all_hw (const Student_info &s);
bool read (std::istream&, Student_info&);
std::istream& read_hw (std::istream&,doubleCont&);
void printStudInfo(const Student_info& s);
void printVec (const doubleCont vect);

#endif
