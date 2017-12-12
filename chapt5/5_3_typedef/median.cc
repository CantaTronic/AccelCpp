
//source file forthe median.h
#include <algorithm>
#include <stdexcept>
#include "hw_cont.h"
#include "Student_info.h"

using std::domain_error;    using std::sort; 

//compute the median of a vector<double>
double median (doubleCont vec) {
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
/*    
//     sort(vec.begin(), vec.end());
    vec.sort(compare);*/
    
//     vec_sz mid = size/2;
//      size%2 == 0 ? (vec[mid] + vec [mid -1])/2 : vec[mid];
    
    return 0.5;
}
