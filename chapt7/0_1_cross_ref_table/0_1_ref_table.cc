
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;
using std::istream;
using std::find_if;

/*
 This code generates a cross-reference table according the input.
 I.e., using it, we can find each line in the text, which refers to the word in the text 
 */

bool is_space(char ch) {
  return isspace(ch);
}

bool is_not_space(char ch) {
  return !isspace(ch);
}

vector<string> split(const string & str) {
  vector<string> ret;
  typedef string::const_iterator iter;
  iter i = str.begin();
  iter j;
  while (i != str.end()) {
    //look for the first non-space character
    i = find_if(i, str.end(), is_not_space);
    //look for the end of non-space characters sequence
    j = find_if(i, str.end(), is_space);
    //append ret vector
    if (i != str.end()){
      ret.push_back(string(i,j));
    }
    i = j;
  }

  return ret;
}

// map<string, vector<int> > xref (istream &in, vector<string> find_word(const &string) = split) {
//   
//   int line_number = 0;
//   map<string, vector<int> > ret;
//   
// }

void test_isspase(){
  cout<<"'a' is NOT spase:"<<is_space('a')<<endl;
  cout<<"' ' is spase:"<<is_space(' ')<<endl;
}

int main() {
  test_isspase();
  return 0;
}
