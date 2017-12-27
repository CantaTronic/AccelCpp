
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using std::string;  using std::vector;
using std::cout;    using std::endl;

string::size_type width (const vector<string> & vect);
vector<string> frame (const vector<string> & vect);
void printVec (const vector<string> & vect);
void testFrame();
vector<string> vcat (const vector<string> & top, const vector<string> & bottom);
vector<string> hcat (const vector<string> & left, const vector<string> & right);
void testCat();

int main() {
//   testFrame();
  testCat();
//   std::vector<string> test1;
//   cout<<"Init size: "<<test1.size()<<endl;
// //   cout<<"This will not work: "<<test1[0]<<endl;
//   test1.push_back("test");
//   printVec(frame(test1));
  return 0;
}

void testCat() {
  /*Test concatenation*/
  vector<string> first, second, vertAdd;
  first.push_back("Test");
  first.push_back("vector"); 
  first.push_back("one"); 
  second.push_back("Second");
  second.push_back("test");
  second.push_back("vector"); 
  cout<<"Test vcat:"<<endl;
  vertAdd = vcat (first, second);
  printVec(frame(vertAdd));
  cout<<"Test hcat:"<<endl;
  vertAdd = hcat (first, second);
  printVec(frame(vertAdd));
  
  second.push_back("check out bad case"); 
  cout<<"Bad test hcat:"<<endl;
  vertAdd = hcat (first, second);
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
  string::size_type maxlen = 0;
  for (vector<string>::const_iterator it = vect.begin(); it != vect.end(); it++) {
    if ((*it).size() > maxlen ) {
      maxlen = (*it).size();
    }
  }
  return maxlen;
}

vector<string> frame (const vector<string> & vect) {
  vector<string> ret;
  string::size_type maxlen = width(vect);
  string border(maxlen + 4,'*');
  ret.push_back(border);
  for (vector<string>::const_iterator it = vect.begin();  it != vect.end(); it++) {
    string tmp = "* " + *it + string(maxlen - (*it).size() + 1, ' ') + '*';
    ret.push_back(tmp);
  }
  ret.push_back(border);
  return ret;
}

//the iterator version 1.0
// vector<string> hcat (const vector<string> & left, const vector<string> & right) {
//   vector<string> ret;
//   typedef vector<string>::size_type vsize;
//   vsize width1 = width(left) + 1;
//   vsize edge = (left.size() > right.size())?left.size():right.size();
//   for (vsize i = 0; i != edge; i++) {
//     string tmp = left[i] + string(width1 - left[i].size(),' ') + right[i];
//     ret.push_back(tmp);
//   }
// }

vector<string> hcat (const vector<string> & left, const vector<string> & right) {
  vector<string> ret;
  typedef vector<string>::const_iterator vit;
  vector<string>::size_type width1 = width(left) + 1;
  vit i = left.begin(), j = right.begin();
  while (i != left.end() || j != right.end()) {
    string tmp;
    //add to tmp the whole line in left
    if (i != left.end()) {
      tmp = (*i);
      i++;
    }
    tmp += string(width1 - tmp.size(), ' ');
    if (j!= right.end()) {
      tmp += (*j);
      j++;
    }
    ret.push_back(tmp);
  }
  return ret;
}

vector<string> vcat (const vector<string> & top, const vector<string> & bottom) {
  /*Make vertical concatenation of two vector<string>'s*/
  vector<string> ret = top;
  copy(bottom.begin(), bottom.end(), back_inserter(ret));
  return ret;
}

void printVec (const vector<string> & vect) {
  /*Print out the vector*/
    for (vector<string>::size_type i = 0; i != vect.size(); i++) {
        cout<<vect[i]<<endl;
    }
}
