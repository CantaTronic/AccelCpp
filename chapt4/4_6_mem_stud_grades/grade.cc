
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include <iostream>

// double grade (const Student_info& s) {
// //     return grade (s.midterm, s.final, s.homework);
//     Student_info (std::cin, s); 
// }   

double grade (double midterm, double final, const std::vector<double> &hw) {
    if (hw.size() == 0)
        throw std::domain_error ("No homework grades provided!");
    return grade (midterm, final, median(hw));
}

double grade (double midterm, double final, double median) {
    return 0.4*final + 0.2*midterm + 0.4*median;
}
