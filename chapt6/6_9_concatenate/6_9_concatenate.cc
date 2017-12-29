
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::fstream;
using std::cout;
using std::endl;

vector<string> getVectorFromFile(string fname){
    fstream file;
    file.open (fname);
    string word;
    vector<string> ret;
    while (file>>word) {
        ret.push_back(word);
    }
    file.close();
    return ret;
}

void printVec (const vector<string> & vect) {
  /*Print out the vector*/
    for (vector<string>::size_type i = 0; i != vect.size(); i++) {
        cout<<vect[i]<<endl;
    }
}

int main (){
    vector<string> my_vector = getVectorFromFile("test_vect_conc.txt");
    printVec(my_vector);
    string res;
    for (vector<string>::const_iterator it = my_vector.begin(); it != my_vector.end(); it++) {
      copy((*it).begin(), (*it).end(), back_inserter(res));
    }
    cout<<"Result: "<<res<<endl;
    return 0;
}
