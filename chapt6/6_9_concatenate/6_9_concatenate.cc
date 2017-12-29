
#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;
using std::fstream;

vector<string> getVectorFromFile(string fname){
    fstream file;
    file.open (fname);
    string word;
    vector<string> ret;
    while (file>>word) {
        ret.push_back(word);
    }
    file.close();
    return ret;
}

int main (){
	vector<string> my_vector = getVectorFromFile("test_vect_conc.txt");
//         test_vect_conc.txt

	return 0;
}
