
#ifndef urlFunc_h
#define urlFunc_h

#include <cctype>   //for isalnum()
#include <algorithm>  //for find_if
#include <string>
#include <vector>

using std::string;    using std::vector;

/*Special functions providing url search*/

bool not_url_char(char c) {
  const string url_char = "~;/?:@=&$-_.+!*'(),";    //special url symbols
  return !(isalnum(c) || (find(url_char.begin(), url_char.end(), c) != url_char.end()));
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
  return find_if (b, e, not_url_char);
}

// string::iterator url_begin (string::const_iterator b, string::const_iterator e) {
//   string::iterator ret;
//   return ret;
// }


vector<string> findUrl(const string & str){
  /*General function for finding urls in text.
   It's assumed that all text in the file was read into one
   string str*/
  vector<string> ret;
  typedef string::const_iterator iter;
  iter b = str.begin();
  iter e = str.end();
  iter after;
  while (b != e) {
    //look for the url strart
//     b = url_begin(b, e);
    
    if (b != e) {
        // lookfor the url end
        after = url_end(b, e);

        //     save url into vector
        ret.push_back(string(b, after));
        b = after;
    }
  }
  return ret;
}

#endif
