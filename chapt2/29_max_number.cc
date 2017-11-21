
#include <iostream>
#include <algorithm>

using std::cin;		using std::cout;
using std::endl;	using std::max;

int main(){
	cout<<"Please, enter two numbers:"<<endl;
	int num1, num2;
	cin>>num1>>num2;
	cout<<"The biggest number is "<<max(num1, num2)<<endl;
	
	return 0;
}

