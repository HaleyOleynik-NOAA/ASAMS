//  Common.hpp
//  Age Structured Assessment Modeling System (ASAMS)

#ifndef Common_h
#define Common_h

#include <vector>
#include <cmath>

#define variable double

template <class T>
class model_base{
protected:
    std::vector<T*> estimable_parameters;
    std::vector<int> phase;
};

namespace asams {

template <class T>
const T exp(const T& x){return std::exp(x);}
}


#endif /* Common_h */
