
//source file forthe median.h
#include "hw_cont.h"
#include "Student_info.h"

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
