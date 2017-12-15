
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

string::const_iterator url_begin (string::const_iterator b, string::const_iterator e) {
  typedef string::const_iterator iter;
  static const string step = "://";   //url separator
  iter i = b;
  //while we can find a separator between elements *i and *e and put it sadress into i
  while (search (i, e, step.begin(), step.end()) != e) {
//     if we found smth(1) and there are still some symbols after separator 
    if ((i != b) && (i + step.size() != e)) {
      //assume we find url
      
      //looking for the beggining of aprotocol name
      iter beg = i;
      while ((beg != b) && isalpha(beg[-1]))
        beg--;
      
      //if there is at least one char (1) and it's apropriate url char (2)
      if (beg != i && !not_url_char(i[step.size()])) 
        return beg; //return iterator to the beggining ofthe url
    }
    i += step.size();
  }
  return e;
}


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
    b = url_begin(b, e);
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
