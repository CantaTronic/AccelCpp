
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>	// begin(v), end(v)

using std::string;	using std::cin;
using std::cout;	using std::endl;
using std::vector;	using std::count;
using std::begin;	using std::end;

int main(){
	string x = "";	//the string to count into
	
	cout<<"Please, enter some text,"
	" followed by 0: "<<endl;

	vector<string> words;
	
	//cin>>x;
	while (x != "0"){
		cin>>x;
		words.push_back(x);		
	}
	words.pop_back();

	typedef vector<string>::size_type vec_sz;
	vec_sz size = words.size();

	if (size == 0) {
		//throw domain_error("Nothing is entered! Exiting...");
		cout<<"Nothing is entered! Exiting..."<<endl;
		return 1;	
	}
	unsigned maxLen = 0;	
	unsigned max_i = 0;
	for (unsigned i = 0; i<size; i++){
		if (words[i].size() > maxLen){
			maxLen = words[i].size();
			max_i = i;
		}
	}
	cout<<"The longest word in phrase is "<<words[max_i]<<" with a "<<maxLen<<" symbols in it."<<endl;
	return 0;
}
