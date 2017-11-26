
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "read_input.h"

using std:: cin;    using std::vector;
using std::cout;    using std::endl;
using std::begin;   using std::string;  
using std::end;     using std::count;


int main(){
    cout<<"Enter some text: "<<endl;
    vector<string> my_vect = read_words(cin);
    cout<<"================="<<endl;
    const vector<string>::size_type size = my_vect.size();
    cout<<"There are "<<size<<" words in your text"<<endl;
    for (unsigned i = 0; i<size; i++){
		cout<<"\t"<<my_vect[i]<<": "<<count(begin(my_vect), end(my_vect), my_vect[i])<<endl;
	}

    return 0;
}
