
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

int main(){
	std::ofstream my_file("04_1_written_hello.cc", std::ofstream::trunc);
	my_file<<"#include <iostream>\n"<<endl;
	my_file<<"using std::cout;"<<endl;
	my_file<<"using std::endl;\n"<<endl;
	my_file<<"int main(){"<<endl;
	my_file<<"\tcout<<\"Hello, world!\"<<endl;"<<endl;
	my_file<<"\treturn 0;"<<endl;
	my_file<<"}"<<endl;
	my_file.close();
	return 0;
}

