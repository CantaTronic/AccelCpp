
#include <iostream>
#include <iomanip>

using std::endl;    using std::cout;
using std::setw;

int main() {
    cout<<"i"<<setw(7)<<"i^2"<<endl;
    for (int i = 0; i != 10; i++) {
        cout<<i<<setw(7)<<i*i<<endl;
    }    
    return 0;
}
