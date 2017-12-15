
#ifndef testFunc_h
#define testFunc_h

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "urlFunc.h"

using std::cout;  using std::vector;
using std::endl;  using std::string;

void printVec (const vector<string> & vec) {
/*Control print of vectors*/
    for (vector<string>::const_iterator it = vec.begin(); it != vec.end(); it++) {
      cout<<(*it)<<endl;
    }
}

void test_not_url_char() {
  const string url_char = "~;/?:@=&$-_.+!*'(),";
  const string test = "abc345&$+ ^";
  cout<<"ch\t! isalnum\tfind\tNUrl"<<endl;
  for (string::const_iterator it = test.begin(); it != test.end(); it++ )
    cout<<(*it)<<"\t"<<!(isalnum(*it))<<"\t\t"<<!(find(url_char.begin(), url_char.end(), *it) != url_char.end())<<"\t"<<not_url_char(*it)<<endl;
}

#endif
