
#ifndef testFunc_h
#define testFunc_h

#include <iostream>
#include <vector>
#include <string>

using std::cout;  using std::vector;
using std::endl;  using std::string;

void printVec (const vector<string> & vec) {
/*Control print of vectors*/
    for (vector<string>::const_iterator it = vec.begin(); it != vec.end(); it++) {
      cout<<(*it)<<endl;
    }
}

#endif
