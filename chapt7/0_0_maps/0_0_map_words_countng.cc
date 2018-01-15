
#include <map>
#include <string>
#include <iostream>
#include <fstream>
// #include <algorithm>
 
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::fstream;

// bool sort_by_value (const map<const string, int> a, const map<const string, int> b) {
//   return a.second < b.second;
// }


int main() {
  string s;
  map <string, int> counters;
  
  fstream fin("test.txt");
  while (fin>>s) {
    counters[s]++;
  }
  fin.close();
  
//   sort(counters.begin(),counters.end());
  
  for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); it++) {
    //just printing all the words in counters
//     cout<<(*it).first<<": "<<(*it).second<<endl;
    //printing the worlds, which is repeated several times
    if ((*it).second > 1)
      cout<<(*it).first<<": "<<(*it).second<<endl;
  }
  
  return 0;
}
