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
    std::vector<DistributionBase<T>*> parameter_priors;
    std::vector<int> phase;
    
public:
    void register_parameter(T& par, int phase = 1, DistributionBase<T>* prior = new asams::NormalDistribution()){
        estimable_parameters.pushback(&par);
        phase.pushback(phase);
        parameter_priors.pushback(prior);
    }
};

namespace asams {

template <class T>
const T exp(const T& x){return std::exp(x);}

template <class T>
const T log(const T& x){return std::log(x);}

template <class T>
inline const T logistic(const T& a50, const T& slope, const T& age){
    return (1.0) / (1.0 + asams::exp(-1.0 * (age - a50) / slope));
}

}

#endif /* Common_h */
