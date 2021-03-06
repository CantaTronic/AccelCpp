
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include "grade.h"
#include "Student_info.h"
#include "contType.h"
#include <fstream>
#include "Analysis.h"
#include "container.h"
#include "tests.h"

using std::cout;        using std::max;	
using std::endl;	using std::domain_error;
using std::sort;	using std::setprecision;
using std::streamsize;	using std::string;
using std::fstream;

string::size_type separate(string fname, studFile& did, studFile& didnt);

int main()
{
        studFile did, didnt;
        /*string::size_type maxlen = */separate("test.txt", did, didnt);
        
        //do the analysis
        write_analysis (cout, "median", median_analysis, did, didnt);
        write_analysis (cout, "average", average_analysis, did, didnt);
        write_analysis (cout, "opt_median", opt_median_analysis, did, didnt);
        return 0;
}

string::size_type separate(string fname, studFile& did, studFile& didnt) {
    fstream file;
    file.open (fname);
    Student_info record;
    string::size_type maxlen = 0;
    
    while (read(file, record)) {
            //find lengthoflongestname
            maxlen = max (maxlen, record.name.size());
            if (did_all_hw(record)) {
              did.push_back(record);
            } else {
              didnt.push_back(record);  
            }
    }
    file.close();
    if (did.empty()) {
      cout<<"No students, who did all homework"<<endl;
      return 1;
    }
    if (didnt.empty()) {
      cout<<"All students did all homework :)"<<endl;
      return 1;
    }
    return maxlen;
}

