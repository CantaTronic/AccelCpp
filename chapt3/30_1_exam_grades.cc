
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using std::cout;	using std::streamsize;
using std::endl;	using std::setprecision;
using std::cin;		

int main(){
	cout<<"Please, enter your midterm and final grades: ";
	int midterm, final;
	cin>>midterm>>final;
	
	cout<<"Please enter all your homework grades, "
	"followed by end-of-file: ";
	
	int count = 0;
	int sum = 0;
	int x = 0;

	while (cin>>x){
		count++;
		sum +=x;
	}

	if (count == 0){
		cout<<"No grades are provided. Exiting...";
		return 1;
	}

	//write the result:
	streamsize prec = cout.precision();
	cout<<"Your course grade is: "<<setprecision(3)<<
	0.4*final + 0.2*midterm + 0.4*sum/count<<setprecision(prec)<<endl;

	return 0;
}

