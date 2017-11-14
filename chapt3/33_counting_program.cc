
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
	" followed 0: "<<endl;

	vector<string> words;
	
	//cin>>x;
	while (x != "0"){
		cin>>x;
		words.push_back(x);		
	}

	typedef vector<string>::size_type vec_sz;
	vec_sz size = words.size();

	if (size == 0) {
		//throw domain_error("Nothing is entered! Exiting...");
		cout<<"Nothing is entered! Exiting..."<<endl;
		return 1;	
	}

	//control print:
	for (unsigned i = 0; i<size; i++){
		cout<<"words["<<i<<"] = "<<words[i]<<endl;
	}

	//the simplest case: 
	//count how many "text" words are in vector
	cout<<count(begin(words), end(words), "text")<<endl;

	return 0;
}
