/**
 * Selectivity.hpp
 *
 * Selectivity module for the Age Structured Assessment Modeling System (ASAMS).
 * ASAMS is a group project for the National Oceanic and Atmospheric Administration,
 * Office Of Science and Technology, NOAA Fisheries, National Modeling Team
 * C++ study group.
 *
 *  Created by Haley  Oleynik  on 3/16/21.
 */

#ifndef Selectivity_h
#define Selectivity_h

#include "Common.hpp"



/**
 * Selecivity namespace.
 */
namespace selectivity{


/**
 * Selectivity base class. Inherits from modelbase.
 */
template <class T>
class selectivity_base:public modelbase<T>{
protected:
    
public:
    /**
     *virtual function required to be overloaded by
     *all children of selectivity_base.
     */
    virtual T evaluate(const T& age)=0;
};


/**
 *Logistic selectivity implementation. Inherits from selectivity_base.
 */
template <class T>
class logistic:public selectivity_base<T>{
    
public:
    T a50_m; // m means member of class
    T slope_m;
    
    /*
     *default constructor.
     */
    logistic(){
        
    }
    
    /*
     *Constructor that takes parameters.
     */
    logistic(T a50, T slope){  // constructor
        this->a50_m=a50;
        this->slope_m=slope;
    }
    
    /*
     * destructor. used to release any memory
     this class puts on the heap.
     */
    ~ logistic(){    //destructor
        std::cout <<"I just deleted"<<std::endl;
    }
    
    /**
     *Logistic mplementation of the virtual evaluate function. Required to be overloaded.
     *Same look as selectivity_base, different behavior....polymorphism.
     */
    virtual T evaluate(const T& age){
        return (1.0) / (1.0 + caa::exp(-1.0 * (age - a50_m) / slope_m));
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
    /*
     *Constructor that takes parameters.
     */
    doublelogistic(T alpha_asc, T beta_asc,T alpha_desc,T beta_desc){
        this->alpha_asc_m=alpha_asc;
        this->beta_asc_m=beta_asc;
        this->alpha_desc_m=alpha_desc;
        this->beta_desc_m=beta_desc;
    }
    /*
     * destructor. used to release any memory
     this class puts on the heap.
     */
    ~doublelogistic(){
        std::cout <<"I just deleted"<< std::endl;
    }
    
    /**
     *Logistic mplementation of the virtual evaluate function. Required to be overloaded.
     *Same look as selectivity_base, different behavior....polymorphism.
     */
    virtual T evaluate(const T& age){
        return (1.0/ (1.0+caa::exp(-beta_asc_m * (age - alpha_asc_m)))) * (1.0- (1.0/ (1.0+caa::exp(-beta_desc_m * (age - alpha_desc_m)))));
    }
};

}//end selectivity namespace

#endif /* Selectivity_h */
