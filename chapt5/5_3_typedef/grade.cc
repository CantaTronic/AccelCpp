
#include <stdexcept>
#include "grade.h"
#include "median.h"

double grade (const Student_info& s) {
    return grade (s.midterm, s.final, s.homework);
}   

double grade (double midterm, double final, const doubleCont &hw) {
    if (hw.size() == 0)
        throw std::domain_error ("No homework grades provided!");
    return grade (midterm, final, median(hw));
}

// double grade (double midterm, double final, const std::list<double> &hw) {
//     if (hw.size() == 0)
//         throw std::domain_error ("No homework grades provided!");
//     return grade (midterm, final, median(hw));
// }
// 
// double grade (double midterm, double final, const std::vector<double> &hw) {
//     if (hw.size() == 0)
//         throw std::domain_error ("No homework grades provided!");
//     return grade (midterm, final, median(hw));
// }

double grade (double midterm, double final, double median) {
    return 0.4*final + 0.2*midterm + 0.4*median;
}
