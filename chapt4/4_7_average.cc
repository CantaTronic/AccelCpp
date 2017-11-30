
#include <iostream>
#include <vector>
#include <iomanip>

using std::cout;	using std::setprecision;
using std::endl;	using std::vector;

int main() {
	vector<double> my_vect;
        const unsigned sz = 10;
        //fill the vector
	for (unsigned i = 0; i < sz; i++){
		my_vect.push_back(i + (double)(i)/sz);
		cout<<i<<"\t"<<my_vect[i]<<endl;
	}
	
	//count the average
	double avr = 0.0;
	for (unsigned i = 0; i < sz; i++) {
          avr += my_vect[i];
        }
        avr /= sz;
        cout<<"The average is "<<avr<<endl;
	return 0;
}
