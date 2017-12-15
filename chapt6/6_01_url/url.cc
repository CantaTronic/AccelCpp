
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <streambuf>  //stream buffer to control data reading

using std::cout;  using std::vector;
using std::endl;  using std::string;
using std::ifstream;

vector<string> findUrl(const string & str){
  /*General function for finding urls in text.
   It's assumed that all text in the file was read into one
   string str*/
  vector<string> ret;
  typedef string::const_iterator iter;
  iter b = string.begin(), e = string.end();
  while (b != e) {
    //look for the urlstrart
    
//     /lookfor the url end
    
//     save url into vector
    //change b
  }
  return ret;
}

int main() {
  ifstream url_file("test.txt");
  //trying to read all document info one string
  string buf((std::istreambuf_iterator<char>(url_file)), std::istreambuf_iterator<char>());
  cout<<"\t"<<buf<<endl;    //check out

  url_file.close();
  return 0;
}
