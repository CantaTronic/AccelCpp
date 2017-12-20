
#include <stdexcept>
#include "grade.h"
#include "median.h"

double grade_aux(const Student_info& s) {
  try {
    return grade(s);
  } catch (std::domain_error) {
    return grade(s.midterm, s.final, 0);
  }
}

double grade (const Student_info& s) {
    return grade (s.midterm, s.final, s.homework);
}   

double grade (double midterm, double final, const doubleCont &hw) {
    if (hw.size() == 0)
        throw std::domain_error ("No homework grades provided!");
    return grade (midterm, final, median(hw));
}

double grade (double midterm, double final, double median) {
    return 0.4*final + 0.2*midterm + 0.4*median;
}
