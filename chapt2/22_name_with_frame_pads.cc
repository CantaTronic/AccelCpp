
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

int main(){
	cout<<"Please, enter your first name: ";
	string name;
	cin>>name;

	//building message we intend to write
	string greeting = "Hello " + name + "!";

	//the number of pads suppounding the greeting
	const int top_pad = 1;
	const int bottom_pad = 3;
	const int left_pad = 2;
	const int right_pad = 4;

	//the number of rows and columns to write
	const int rows = top_pad + bottom_pad + 3;
	const string::size_type cols = greeting.size() + left_pad + right_pad + 2;
	
	cout<<endl;

	//invariant: we have written r rows so far
	for (int r = 0; r != rows; r++){
	string::size_type c = 0;
	
	//invariant: we have c characters written in the current row so far
		while (c != cols){
			//is it time to write the greeting?
			if (r == top_pad + 1 && c == left_pad + 1){
				cout<<greeting;
				c += greeting.size();
		
			} else {
				//are we on the border?
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) 
					cout<<"*";
				else 
					cout<<" ";
				c++;
			}

		}
		cout<<endl;	
	}	
	return 0;
}

