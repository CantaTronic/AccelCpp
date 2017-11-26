
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using std::endl;    using std::cout;
using std::setw;    using std::cin;
using std::streamsize;  using std::setprecision;    //for work with precision 

int main() {
    cout<<"Please, enter the biggest number: "<<endl;
    int i_max;
    cin>>i_max;
    int n = 2*(std::to_string(i_max*i_max).size() + 3);
    cout<<"i"<<setw(n)<<"i^2"<<endl;
    streamsize sz = cout.precision();
    for (int i = i_max - 10; i != i_max; i++) {
        cout<<i<<setw(n)<<sqrt((double)(i))<<setprecision(5)<<endl;
    }    
    cout<<setprecision(sz);
    return 0;
}
