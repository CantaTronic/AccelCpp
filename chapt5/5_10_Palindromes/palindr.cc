
/*A program, which is looking for palindromes in the dictionary*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cout;    using std::endl;
using std::string;  using std::vector;
using std::fstream;

vector<string> loadDict(string dictName);

bool isPalidnrom (const string & s) {
  return equal(s.begin(), s.end(), s.rbegin());
}

void sayPal(const string s);

void testSimple();

int main() {
  vector<string> myDict = loadDict("../5_11_Asc_and_desc/text.txt");
  unsigned count = 0;
  for (vector<string>::const_iterator it = myDict.begin(); it != myDict.end(); it++) {
    if (isPalidnrom(*it)) {
      sayPal(*it);
      count++;
    }
  }
  cout<<"There are "<<count<<" palindromes in dictionary."<<endl;
//   testSimple();
  
  return 0;
}

vector<string> loadDict(string dictName) {
  /*load the dictionary*/
  fstream dict;
  dict.open(dictName);
  vector<string> ret;
  string tmp;
  while (dict>>tmp) {
    ret.push_back(tmp);
  }
  dict.close();
  return ret;
}

void sayPal(const string s) {
  cout<<s;
  if (isPalidnrom(s)) {
    cout<<" is a palindrom"<<endl;
  } else {
    cout<<" is NOT a palindrom"<<endl;
  }
}

void testSimple() {
  sayPal("level");
  sayPal("ray");
  sayPal("t");
}
