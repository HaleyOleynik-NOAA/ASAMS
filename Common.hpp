//
//  Common.hpp
//  Catch_at_Age
//
//  Created by Haley  Oleynik  on 3/23/21.
//

#ifndef Common_h
#define Common_h

#include <vector>
#include <cmath>

#define variable double

template <class T>
class modelbase{
protected:
    std::vector<T*> estimable_parameters;
    std::vector<int> phase;
};

namespace caa {

template <class T>
const T exp(const T& x){return std::exp(x);}
}


#endif /* Common_h */
