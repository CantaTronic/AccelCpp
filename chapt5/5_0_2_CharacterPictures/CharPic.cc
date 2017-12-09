
#include <iostream>
#include <string>
#include <vector>

using std::string;  using std::vector;
using std::cout;    using std::endl;

string::size_type width (const vector<string> & vect);

int main() {
  
  return 0;
}

string::size_type width (const vector<string> & vect) {
  /*Retrun the length of te longest stringin the vector of strings*/
  string::size_type maxlen = vect[0].size();
  vector<string>::size_type sz = vect.size();
  for (vector<string>::size_type i = 1; i != sz; i++) {
    if (vect[i].size() > maxlen ) {
      maxlen = vect[i].size();
    }
  }
  return maxlen;
}
