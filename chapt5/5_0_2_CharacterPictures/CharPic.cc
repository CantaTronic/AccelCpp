
#include <iostream>
#include <string>
#include <vector>

using std::string;  using std::vector;
using std::cout;    using std::endl;

string::size_type width (const vector<string> & vect);
vector<string> frame (const vector<string> & vect);
void printVec (const vector<string> & vect);

int main() {
  vector<string> testVect, vect2;
  testVect.push_back("Test");
  testVect.push_back("string");
  cout<<"Without frame: "<<endl;
  printVec(testVect);
  vect2 = frame (testVect);
  cout<<"With frame: "<<endl;
  printVec(vect2);
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

vector<string> frame (const vector<string> & vect) {
  vector<string> ret;
  string::size_type maxlen = width(vect);
  string border(maxlen + 4,'*');
  ret.push_back(border);
  for (vector<string>::size_type i = 0;  i != vect.size(); i++) {
    string tmp = "* " + vect[i] + string(maxlen - vect[i].size() + 1, ' ') + '*';
    ret.push_back(tmp);
  }
  ret.push_back(border);
  return ret;
}

void printVec (const vector<string> & vect) {
  /*Print out the vector*/
    for (vector<string>::size_type i = 0; i != vect.size(); i++) {
        cout<<vect[i]<<endl;
    }
}
