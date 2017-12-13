
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
void testOneWord();
void testHasAsDs();
vector<string> loadDict(string);
void printVec (const vector<string> &);
string::size_type LongestWord(const vector<string> &);
void testLongest();

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
//   testAscendor();
//   testDescendor();
//   testHasAsDs();
  testLongest();
  return 0; 
}

string::size_type LongestWord(const vector<string> & dict) {
  /*Looking for longest word with ascendors/descendors in dictionary*/
  string::size_type maxlen = 0;
  if (dict.empty()) {
      cout<<"Dictionary is empty"<<endl;
  } else {
      for (vector<string>::const_iterator word = dict.begin(); word != dict.end(); word++) {
        if (hasAsDs(*word) && ((*word).size() > maxlen) ) {
//         if (vect[i].size() > maxlen ) {
          maxlen = word -> size();
        }
      }
  }
  return maxlen;
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

void testHasAsDs() {
//   testOneWord();
  vector<string> testDict = loadDict("text.txt");
//   printVec(testDict);
  int has = 0;
  int no_has = 0;
  for (vector<string>::const_iterator it = testDict.begin(); it != testDict.end(); it++) {
    if (hasAsDs(*it)) {
      has++;
    } else {
      no_has++;
    }
  }
  cout<<"Dictionary size: "<<testDict.size()<<endl;
  cout<<"Have ascendors/descendors: "<<has<<endl;
  cout<<"Don't have them: "<<no_has<<endl;
}

void testOneWord() {
  string test1 = "test";
  if (hasAsDs(test1)) {
    cout <<"Word "<<test1<<" has ascendors or descendors"<<endl; 
  }
}

void testLongest() {
  vector<string> testVec;
  string test = "my_string";
  testVec.push_back(test);
  cout<<"Test Long: "<<LongestWord(testVec)<<" == "<<test.size()<<endl;
//     EXPECT_EQ(LongestWord(testVec), test.size());
  
}

void testAscendor() {
  for (char c = 'a'; c <= 'z'; c++) {
    if (ascendor(c)) {
      cout<<c<<" is ascendor"<<endl;
    }
  }
}

void printVec (const vector<string> & vect) {
  /*Print out the vector*/
    for (vector<string>::size_type i = 0; i != vect.size(); i++) {
        cout<<vect[i]<<endl;
    }
}

void testDescendor() {
  for (char c = 'a'; c <= 'z'; c++) {
    if (descendor(c)) {
      cout<<c<<" is descendor"<<endl;
    }
  }
}
