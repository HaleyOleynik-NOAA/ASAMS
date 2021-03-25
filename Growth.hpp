//
//  Growth.hpp
//  Catch_at_Age
//
//  Created by Haley  Oleynik  on 3/16/21.
//

#ifndef Growth_h
#define Growth_h

namespace growth{

template <class T>
class growth_base:public modelbase<T>{
protected:
    T R0_m;
    T h_m;
    
public:
    virtual T evaluate(const T& SB0, const T& SB)=0;
};

}


#endif /* Growth_h */
