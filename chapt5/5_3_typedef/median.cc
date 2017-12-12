
//source file forthe median.h
#include <algorithm>
#include <stdexcept>
#include "hw_cont.h"
#include "Student_info.h"
#include <vector>
#include <list>

using std::domain_error;    using std::sort; 

//compute the median of a vector<double>
double median (doubleCont vec) {
// double median (std::vector<double> vec) {
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
#ifdef VECT  
    sort(vec.begin(), vec.end());
    vec_sz mid = size/2;
    return size%2 == 0 ? (vec[mid] + vec [mid -1])/2 : vec[mid];
//     return vec[mid];
#endif
#ifdef LIST
    vec.sort(compareNum);
    return 0.5;
#endif        
}


// double median (std::list<double> mylist) {
//    double med;
//     auto itr = mylist.begin();
//     
//     if( mylist.size() % 2 == 0 ) {     // n is even
//         for( unsigned i = 0 ; i < mylist.size() / 2 ; i ++ ) {
//             itr++;
//         }
//         med = ( (double)*itr + *--itr ) / 2;
//     } else {  // n is odd
//         for( unsigned i = 0 ; i < mylist.size() / 2 ; i ++ ) {
//             itr++;
//         }
//         med= *itr;
//     }
//     return med;
// }
