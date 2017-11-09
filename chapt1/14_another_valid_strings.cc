
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
This pogram is valid because of accurately included scopes.
And there is no matter if we use ';' at the end of included scope or no.
*/

int main(){
	{const string s = "a string";
	cout<<s<<endl;

	{const string s = "another one string";
	cout<<s<<endl;}}	//cout<<s<<endl;};}	is also valid

	return 0;
}

