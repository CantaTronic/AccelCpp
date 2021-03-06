
#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

//Students_info.h

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare (const Student_info&, const Student_info&);
bool read (std::istream&, Student_info&);
std::istream& read_hw (std::istream&,std::vector<double>&);

bool fgrade (const Student_info& s);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);

vector<std::string> split (const std::string& s);

#endif
