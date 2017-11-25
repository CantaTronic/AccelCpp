
#include <iostream>
#include <iomanip>
#include <string>

using std::endl;    using std::cout;
using std::setw;    using std::cin;

int main() {
    cout<<"Please, enter the biggest number: "<<endl;
    int i_max;
    cin>>i_max;
    int n = std::to_string(i_max).size() + 3;
//     cout<<"size = "<<n<<endl;
    cout<<"i"<<setw(n)<<"i^2"<<endl;
    for (int i = i_max - 10; i != i_max; i++) {
        cout<<i<<setw(n)<<i*i<<endl;
    }    
    return 0;
}
