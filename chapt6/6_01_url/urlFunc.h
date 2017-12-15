
#ifndef urlFunc_h
#define urlFunc_h

/*Special functions providing url search*/

string::iterator url_begin(string::const_iterator b, string::const_iterator e) {
  string::iterator ret;
  return ret;
}

string::iterator url_end (string::const_iterator b, string::const_iterator e) {
  string::iterator ret;
  return ret;
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
