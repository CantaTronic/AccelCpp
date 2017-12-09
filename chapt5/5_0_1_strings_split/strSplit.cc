#include <cctype>
#include <vector>
#include <string>
#include <iostream>
// #include "gtest/gtest.h"   //I'm just too lazyto link this small training project with gtest. Shame on me =))

using std::vector;  using std::string;
using std::cout;    using std::endl;

vector<string> split (const string& s);   //actual function

/*and a bit of funny stuff for testing :)*/
bool operator== (const vector<string> & x, const vector<string> & y); 
void testVectorEquality();
void testSplit();

int main () {
  testVectorEquality();
  testSplit();
  return 0; 
}

void testVectorEquality() {
  vector<string> a(4);
  vector<string> b;
  cout<<"(a==a) is "<<(a==a)<<endl;   //EXPECT_EQ((a==a),1);
  cout<<"(a==b) is "<<(a==b)<<endl;   //EXPECT_EQ((a==b),0);
}

bool operator== (const vector<string> & x, const vector<string> & y){
  if (x.size() != y.size()) {
    return false;
  } else {
    const vector<string>::size_type v_size = x.size();
    bool equal = true; 
    vector<string>::size_type i = 0;
    while (equal && i != v_size) {
      equal = (x[i] == y [i]);
      i++;
    }
    return equal;
  }
}

void testSplit() {
    vector<string> myVect = split("This is a phrase for test splitting");
    vector<string> testVect;
    testVect.push_back("This");
    testVect.push_back("is");
    testVect.push_back("a");
    testVect.push_back("phrase");
    testVect.push_back("for");
    testVect.push_back("test");
    testVect.push_back("splitting");
//     EXPECT_EQ(1,(myVect == testVect));
    if (myVect == testVect) {
      cout<<"Split works"<<endl;
    } else {
      cout<<"Split doesn't work"<<endl;
    }
	
}

vector<string> split (const string& s) {
  vector<string> ret;
  typedef string::size_type string_size;
  string_size i = 0;
  //invariant: we have processed characters [original value of i, i)
  while (i != s.size()) {
    //ignore leading blanks
    //invariant: characters in range [original i, current i) are all spaces
    while (i !=s.size() && isspace(s[i])) { 
      i++;
    }
    //find end of next word
    string_size j = i;
    //invariant: none of the characters in range [original j, current j] is space
    while (j != s.size() && !isspace(s[j])) {
      j++;
    }
      //if we found some nonwhitespace characters
    if (i != j) {
      //copy from s starting at i and taking j-i chars
      ret.push_back(s.substr(i, j-i));
      i = j;
    }
  }
  return ret;
} 
