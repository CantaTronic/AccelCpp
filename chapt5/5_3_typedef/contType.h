
#ifndef contType_h
#define contType_h

#include <vector>
#include <list>
#include "Student_info.h"

// typedef std::vector<Student_info> studFile;
// typedef std::vector<Student_info>::iterator iter;
// typedef std::vector<Student_info>::const_iterator iterC;

typedef std::list<Student_info> studFile;
typedef std::list<Student_info>::iterator iter;
typedef std::list<Student_info>::const_iterator iterC;

#endif
