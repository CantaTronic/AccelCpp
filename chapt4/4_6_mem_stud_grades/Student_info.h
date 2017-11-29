
#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

//Students_info.h

#include <iostream>
#include <string>
#include <vector>

/*
 In this exercise Student_info is rewritten to calculate 
 grades immediately and store only the final grade.
 */

struct Student_info {
// public:
	std::string name;
    double courseGrade;
//     Student_info (std::istream& is, Student_info& s);    //constructor
// 	double midterm, final;
// 	std::vector<double> homework;
};

bool compare (const Student_info&, const Student_info&);
bool read (std::istream&, Student_info&);
std::istream& read_hw (std::istream&,std::vector<double>&);

#endif
