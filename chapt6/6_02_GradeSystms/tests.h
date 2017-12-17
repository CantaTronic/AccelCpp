
#ifndef tests_h
#define tests_h

#include <iostream>
#include "Student_info.h"
#include "contType.h"

using std::cout;
using std::endl;

/*an ugly hack to not move from GNUMake to cmake just because of gtest*/

void testAllHW(const studFile & vect) {
        cout<<"Test did_all_hw"<<endl;
        for (iterC it = vect.begin(); it != vect.end(); it++) {
          cout<<it->name<<": "<<did_all_hw(*it)<<endl;
        }
}
#endif
