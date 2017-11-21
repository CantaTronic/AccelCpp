
#include <iostream>
#include <algorithm>
#include <string>

using std::cout;
using std::endl;
using std::max;
using std::string;

struct Stud_info
{
	string name;
};

int main(){
	string::size_type maxLen = 10;
	Stud_info s;
	s.name = "Sigizmund II";
	cout<<"The max leght is "<<max(s.name.size(),maxLen)<<endl;
	return 0;
}
