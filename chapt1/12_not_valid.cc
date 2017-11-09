
#include <string>

using std::string;

/*This program is NOT valid because operator "+" is binary, and it cause problem, 
if we want to get string results, but the first two arguments in row are NOT strings */

int main(){
	string exclam = "!";
	string message = "Hello" + "world" + exclam + " But it doesn't work, through...(";
	return 0;
}

