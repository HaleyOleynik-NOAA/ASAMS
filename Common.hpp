//  Common.hpp
//  Age Structured Assessment Modeling System (ASAMS)
// 
//
#ifndef Common_h
#define Common_h

#include <vector>
#include <cmath>

#define variable double

template <class T>
/// A class for a general model framework.
///
/// Provides a framework for a model.
class model_base{
protected:
    std::vector<T*> estimable_parameters;
    std::vector<int> phase;
};

namespace asams {

template <class T>
const T exp(const T& x){return std::exp(x);}

template <class T>
class logistic:public model_base<T>{
    
public:
    T a50_m; // m means member of class
    T slope_m;
    
    logistic(){
        
    }
    
    /// Creates an logistic curve with  \f$ Y = \frac{1.0}{1.0+\mathrm{exp}(-1(age-a_{50})/slope)}\f$.
    ///
    /// @param[in] a50 The inflection age of the logistic curve.
    /// @param[in] slope The logistic curve slope.
    logistic(T a50, T slope){  // constructor
        this->a50_m=a50;
        this->slope_m=slope;
    }
    
    ~ logistic(){    //destructor
        std::cout <<"I just deleted"<<std::endl;
    }
    
    virtual T evaluate(const T& age){
        return (1.0) / (1.0 + asams::exp(-1.0 * (age - a50_m) / slope_m));
    }
    
};

}


#endif /* Common_h */
