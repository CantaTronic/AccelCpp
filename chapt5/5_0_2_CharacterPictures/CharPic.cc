
#include <iostream>
#include <string>
#include <vector>

using std::string;  using std::vector;
using std::cout;    using std::endl;

string::size_type width (const vector<string> & vect);
vector<string> frame (const vector<string> & vect);
void printVec (const vector<string> & vect);
void testFrame();
vector<string> vcat (const vector<string> & top, const vector<string> & bottom);
void testCat();

int main() {
  testFrame();
  testCat();
  return 0;
}

void testCat() {
  /*Test concatenation*/
  vector<string> first, second, vertAdd;
  first.push_back("Test");
  first.push_back("vector"); 
  first.push_back("one");  
  second.push_back("vector"); 
  second.push_back("test");
  second.push_back("Second");
  vertAdd = vcat (first, second);
  printVec(frame(vertAdd));
}

void testFrame() {
  vector<string> testVect, vect2;
  testVect.push_back("Test");
  testVect.push_back("string");
  cout<<"Without frame: "<<endl;
  printVec(testVect);
  vect2 = frame (testVect);
  cout<<"With frame: "<<endl;
  printVec(vect2);
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

vector<string> vcat (const vector<string> & top, const vector<string> & bottom) {
  /*Make vertical concatenation of two vector<string>'s*/
  vector<string> ret = top;
  ret.insert(ret.end(), bottom.begin(), bottom.end());
  return ret;
}

void printVec (const vector<string> & vect) {
  /*Print out the vector*/
    for (vector<string>::size_type i = 0; i != vect.size(); i++) {
        cout<<vect[i]<<endl;
    }
}
