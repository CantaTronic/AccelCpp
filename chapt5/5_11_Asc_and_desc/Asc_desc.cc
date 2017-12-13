
#include <iostream>
#include <algorithm>
#include <string>
/*A program for determine, if word have ascendors ("tall" letters: b, d, f, h, k, l, t)
 and descendors ("long tail" letters: j, g, p, q, y )*/

using std::string;
using std::cout;    using std::endl;

void testAscendor();
void testDescendor();

bool ascendor (char c) {
  /*check if char c is ascendor*/
  static string asc_list = "b d f h k l t";
  return (find(asc_list.begin(),asc_list.end(), c) != asc_list.end());
}

bool descendor (char c) {
  /*check if char c is ascendor*/
  static string desc_list = "j g p q y";
  return (find(desc_list.begin(),desc_list.end(), c) != desc_list.end());
}

int main () {
  testAscendor();
  testDescendor();
  return 0; 
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
