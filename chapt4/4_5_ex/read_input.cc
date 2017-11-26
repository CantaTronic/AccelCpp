
#include "read_input.h"

using std::vector; 
using std::istream; 
using std::string;  

vector<string> read_words(istream &in){
    string tmp;
    vector<string> vect;
    in>>tmp;
    while (tmp != "0") {
        vect.push_back(tmp);
        in>>tmp;
    }
    return vect;
}
