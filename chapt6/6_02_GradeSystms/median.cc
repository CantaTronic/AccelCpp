
//source file forthe median.h
#include "hw_cont.h"
#include "Student_info.h"
#include <algorithm>
#include "grade.h"

double median (doubleCont cont) {
  /*Calculate the median in provided container, using iterators*/
   double med;
    auto itr = cont.begin();
    
    if( cont.size() % 2 == 0 ) {     // n is even
        for(cont_sz i = 0 ; i < cont.size() / 2 ; i ++ ) {
            itr++;
        }
        med = ( (double)*itr + *--itr ) / 2;
    } else {  // n is odd
        for(cont_sz i = 0 ; i < cont.size() / 2 ; i ++ ) {
            itr++;
        }
        med= *itr;
    }
    return med;
}

double opt_median(const Student_info& s) {
  /*median of non-zero elements*/
  doubleCont nonzero;
  remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
  if (nonzero.empty()) {
    return grade(s.midterm, s.final, 0);
  } else {
     return grade(s.midterm, s.final, median(nonzero));
  }
}
