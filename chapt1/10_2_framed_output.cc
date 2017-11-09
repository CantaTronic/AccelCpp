
#include <iostream>
#include <string>

/*
This program asks for user's name and then prints greeting framed into asterisks ('*').
*/

using std::cout; 		using std::cin;
using std::endl;		using std::string;

int main(){
	cout<<"Please, enter your name: ";
	string name;
	cin>>name;
	string greeting = "Hello, " + name + "! Nice to see you.";
	string spaces(greeting.size(),' ');
	string second = '*' + spaces + '*';

	string first(second.size(), '*');

	cout<<first<<endl;
	cout<<second<<endl;
	cout<<"*"<<greeting<<"*"<<endl;
	cout<<second<<endl;
	cout<<first<<endl;
	return 0;
}

