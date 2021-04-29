//
//  Selectivity.hpp
//  Catch_at_Age
//
//

#ifndef Selectivity_h
#define Selectivity_h

#include "Common.hpp"

namespace asams{

template <class T>
class selectivity_base:public model_base<T>{
protected:
    
public:
    virtual T evaluate(const T& age)=0;
};

template <class T>
class logistic:public selectivity_base<T>{
    
public:
    T a50_m; // m means member of class
    T slope_m;
    
    logistic(){
        
    }
    
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

template <class T>
class doublelogistic:public selectivity_base<T>{

public:
    T alpha_asc_m;
    T beta_asc_m;
    T alpha_desc_m;
    T beta_desc_m;
    
    doublelogistic(){       // default constructor
        
    }
    
        doublelogistic(T alpha_asc, T beta_asc,T alpha_desc,T beta_desc){
            this->alpha_asc_m=alpha_asc;
            this->beta_asc_m=beta_asc;
            this->alpha_desc_m=alpha_desc;
            this->beta_desc_m=beta_desc;
        }
    
    ~doublelogistic(){
        std::cout <<"I just deleted"<< std::endl;
    }
        virtual T evaluate(const T& age){
            return (1.0/ (1.0+asams::exp(-beta_asc_m * (age - alpha_asc_m)))) * (1.0- (1.0/ (1.0+asams::exp(-beta_desc_m * (age - alpha_desc_m)))));
        }
};
}

#endif /* Selectivity_h */
