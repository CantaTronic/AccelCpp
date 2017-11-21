
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::cout;	using std::streamsize;
using std::endl;	using std::setprecision;
using std::cin;		using std::vector;	
using std::string;	using std::domain_error;

double countFinal(string stName){
	cout<<"Counting final grade for student "<<stName<<"..."<<endl;
	cout<<"Please, enter your midterm and final grades: ";
	int midterm, final;
	cin>>midterm>>final;
	
	cout<<"Please enter all your homework grades, "
	"followed by -1: ";

	vector <double> homework;
	int x = 0;
	
	cin>>x;
	while (x > -1){
		homework.push_back(x);
		cin>>x;
	}
	
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();	

	if (size == 0){
		throw domain_error("No grades are provided. Exiting...");
		//return 1;
	}

	sort(homework.begin(), homework.end());

	//calculate the median
	vec_sz mid = size/2;
	double median;	
	median = mid % 2 == 0 ? (homework[mid] + homework [mid - 1])/2 : homework[mid];

	double veryFinal = 0.4*final + 0.2*midterm + 0.4*median;
	//write the result:
	streamsize prec = cout.precision();
	cout<<"Your course grade is: "<<setprecision(3)<<veryFinal<<setprecision(prec)<<endl;

	return veryFinal;
}

int main(){
	cout<<"Enter student's surnames separated by spaces"
	"and followed by 0:"<<endl;
	string snm;
	vector <string> stud;
	
	cin>>snm;
	while (snm != "0"){
		stud.push_back(snm);
		cin>>snm;	
	}
	

	vector <double> grades;
	for (unsigned i = 0; i!= stud.size(); i++)
		grades.push_back(countFinal(stud[i]));
	cout<<"\n"<<string(30,'=')<<endl;
	cout<<"===GROUP RESULTS==="<<endl;

	for (unsigned i = 0; i!= stud.size(); i++)
		cout<<stud[i]<<": "<<grades[i]<<endl;
	return 0;
}
