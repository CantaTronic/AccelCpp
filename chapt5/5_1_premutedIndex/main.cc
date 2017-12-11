
#include <iostream>
#include <string>
#include <vector>

using std::string;  using std::cin;
using std::cout;    using std::endl;
using std::vector;

typedef vector<string> str_vec;

void printVec (const vector<string> & vect);
vector<string> rot (const string str);
vector<string> split (const string& s);

int main () {
  //read each line of input
//   cout<<"Enter any number of lines followed by empty line"<<endl;
//   string tmp;
  vector<string> line, rez;
//   while (getline(cin, tmp) &&(tmp != "")) {
//     line.push_back(tmp);
//   }
  string test = "My test string";
  rez = rot(test);
  printVec(rez);
  //generate a set of rotations for every line we have read
  
  return 0;
}

vector<string> rot (const string str) {
  /*take a string and return a vector of rotations*/
  //split string into words
  vector<string> tmp = split(str);
  vector<string> ret;
//   printVec(tmp);
  for(vector<string>::size_type i = 0; i != tmp.size(); i++) {
    string curStr;
    for (vector<string>::size_type j = i; j != tmp.size(); j++)
      curStr += tmp[j] + " ";
    for (vector<string>::size_type j = 0; j < i; j++)
      curStr += tmp[j] + " ";
    ret.push_back(curStr);
  }
//   printVec(ret);
  return ret;
}

vector<string> split (const string& s) {
  /*Split string into words. Return vector of words*/
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

void printVec (const vector<string> & vect) {
  /*Print out the vector*/
    for (vector<string>::size_type i = 0; i != vect.size(); i++) {
        cout<<vect[i]<<endl;
    }
}

