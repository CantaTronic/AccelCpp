
#ifndef contType_h
#define contType_h

#include "Student_info.h"
#include "container.h"

#ifdef VECT 
  #include <vector>
  typedef std::vector<Student_info> studFile;
  typedef std::vector<Student_info>::iterator iter;
  typedef std::vector<Student_info>::const_iterator iterC;
#endif

#ifdef LIST
  #include <list>
  typedef std::list<Student_info> studFile;
  typedef std::list<Student_info>::iterator iter;
  typedef std::list<Student_info>::const_iterator iterC;
#endif

#endif
