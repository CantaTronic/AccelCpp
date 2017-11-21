
#include <iostream>

using std::cout;
using std::endl;

int main(){
	for (int i=1; i!=10; i++){
		for (int j=i;j!=10;j++)
			cout<<i<<" * "<<j<<" = "<<i*j<<endl;
	}
	return 0;
}
