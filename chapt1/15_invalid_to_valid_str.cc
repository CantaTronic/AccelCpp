
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
There are the first "from-book" incorrect lines in the comments.
The task was to fix all bugs and make program work properly.
Bugs, of course, are about C++ scopes and the proper way to use them.

*/

int main(){
	{string s = "a string";
	/*{*/string x = s + ", really";
	cout<<s<<endl;/*}*/
	cout<<x<<endl;
	}
	return 0;
}

