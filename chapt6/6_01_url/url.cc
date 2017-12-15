
// #include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "testFunc.h"
#include "urlFunc.h"
#include <streambuf>  //stream buffer to control data reading

/*using std::cout;  */using std::vector;
/*using std::endl;  */using std::string;
using std::ifstream;

int main() {
  ifstream url_file("test.txt");
  //trying to read all document info one string
  string buf((std::istreambuf_iterator<char>(url_file)), std::istreambuf_iterator<char>());
  url_file.close();
//   cout<<"\t"<<buf<<endl;    //check out
  vector<string> tmp;
  tmp.push_back("test vector");
  printVec(tmp);

  return 0;
}
