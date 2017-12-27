
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::cout;	using std::endl;
using std::vector;

template <class T>
void printVec (const vector<T> & vect);

int main() {
	vector<int> u(10, 100);
	vector<int> v;
	copy(u.begin(), u.end(), back_inserter(v));  //this is how I fixed the issue below
//         copy(u.begin(), u.end(), v.begin());  /*this is line from the textbook, it give as a seqfault, because there is no actual element here - the vector is empty*/
        cout<<"u = ";
        printVec(u);
        cout<<"v = ";
        printVec(v);
	return 0;
}

template <class T>
void printVec (const vector<T> & vect){
  if (!vect.empty()) {
    cout<<(*vect.begin());
  }
  for (auto it = vect.begin()+1; it != vect.end(); it++) {
    cout<<", "<<(*it);
  }
  cout<<endl;
}
