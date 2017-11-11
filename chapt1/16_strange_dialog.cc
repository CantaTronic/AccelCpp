
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

/*
It acts pretty predictable, actually, in sense that if you pass it two names, it uses first one for the first output
 and the second one for the senod one.
*/

int main(){
	cout<<"What is your name?"<<endl;
	string name;
	cin>>name;
	cout<<"Hello, "<<name<<endl<<"And what's yours?";
	cin>>name;
	cout<<"Hello, "<<name<<"; nice to meet you too!"<<endl;
	return 0;
}

