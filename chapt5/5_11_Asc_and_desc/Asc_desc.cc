
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
/*A program for determine, if word have ascendors ("tall" letters: b, d, f, h, k, l, t)
 and descendors ("long tail" letters: j, g, p, q, y )*/

using std::string;  using std::vector;
using std::cout;    using std::endl;
using std::fstream;

void testAscendor();
void testDescendor();
void testHasAsDs();
vector<string> loadDict(string);

bool ascendor (char c) {
  /*check if char c is ascendor*/
  static string asc_list = "b d f h k l t";
  return (find(asc_list.begin(),asc_list.end(), c) != asc_list.end());
}

bool descendor (char c) {
  /*check if char c is descendor*/
  static string desc_list = "j g p q y";
  return (find(desc_list.begin(),desc_list.end(), c) != desc_list.end());
}

bool hasAsDs(string word) {
  /*Check, if word has ascendors or descendors*/
  return (find_if(word.begin(), word.end(), ascendor) != word.end() || find_if(word.begin(), word.end(), descendor) != word.end());
}

int main () {
  testAscendor();
  testDescendor();
  testHasAsDs();
  return 0; 
}

vector<string> loadDict(string dictName) {
  fstream dict.open(dictName);
  
  dict.close();
}

void testHasAsDs() {
  string test1 = "test";
  if (hasAsDs(test1)) {
    cout <<"Word "<<test1<<" has ascendors or descendors"<<endl; 
  }
}

void testAscendor() {
  for (char c = 'a'; c <= 'z'; c++) {
    if (ascendor(c)) {
      cout<<c<<" is ascendor"<<endl;
    }
  }
}

void testDescendor() {
  for (char c = 'a'; c <= 'z'; c++) {
    if (descendor(c)) {
      cout<<c<<" is descendor"<<endl;
    }
  }
}
