
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

	cout<<"Enter number of pads: ";
	unsigned pad;
	cin>>pad;

	//building message we intend to write
	string greeting = "Hello " + name + "!";

	//the number of rows and columns to write
	const unsigned rows = 2*pad + 3;
	const string::size_type cols = greeting.size() + 2*pad + 2;
	
	cout<<endl;

	//invariant: we have written r rows so far
	for (unsigned r = 0; r != rows; r++){
	string::size_type c = 0;
	
	//invariant: we have c characters written in the current row so far
		while (c != cols){
			//is it time to write the greeting?
			if (r == pad + 1 && c == pad + 1){
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

