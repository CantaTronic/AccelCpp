
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main(){
	std::string sent[6] = {"This", "is", "my", "simple", "tab", "experiment"};

	for (int i=0; i<6; i++){
		for (int j=0; j<i;j++)	
			cout<<"\t";
		cout<<sent[i]<<endl;
	}
	return 0;
}

