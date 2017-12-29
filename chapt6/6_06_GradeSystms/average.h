
#ifndef average_h
#define average_h

#include "hw_cont.h"
#include <numeric>

double average(const doubleCont vec) {
  return accumulate(vec.begin(), vec.end(), 0.0)/vec.size();
}

#endif
