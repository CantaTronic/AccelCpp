
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cout;	using std::streamsize;
using std::endl;	using std::setprecision;
using std::cin;		using std::vector;	

int main(){
	cout<<"Please, enter your midterm and final grades: ";
	int midterm, final;
	cin>>midterm>>final;
	
	cout<<"Please enter all your homework grades, "
	"followed by end-of-file: ";

	vector <double> homework;
	int x = 0;

	while (cin>>x)
		homework.push_back(x);
	
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();	

	if (size == 0){
		cout<<"No grades are provided. Exiting...";
		return 1;
	}

	sort(homework.begin(), homework.end());

	//calculate the median
	vec_sz mid = size/2;
	double median;	
	median = mid % 2 == 0 ? (homework[mid] + homework [mid - 1])/2 : homework[mid];


	//write the result:
	streamsize prec = cout.precision();
	cout<<"Your course grade is: "<<setprecision(3)<<
	0.4*final + 0.2*midterm + 0.4*median<<setprecision(prec)<<endl;

	return 0;
}

