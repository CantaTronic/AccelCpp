
#ifndef hw_cont_h
#define hw_cont_h

#include "container.h"

#ifdef LIST
#include <list>

typedef std::list<double> doubleCont;
typedef std::list<double>::size_type vec_sz;
typedef std::list<double>::const_iterator DCiterC;

#endif

#ifdef VECT 
  #include <vector>

  typedef std::vector<double> doubleCont;
  typedef std::vector<double>::size_type vec_sz;
  typedef std::vector<double>::const_iterator DCiterC;
#endif

#endif
