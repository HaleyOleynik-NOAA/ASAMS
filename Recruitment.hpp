/**
 * Recruitment.hpp
 *
 * Recruitment module for the Age Structured Assessment Modeling System (ASAMS).
 * ASAMS is a group project for the National Oceanic and Atmospheric Administration,
 * Office Of Science and Technology, NOAA Fisheries, National Modeling Team
 * C++ study group.
 *
 *  Created by Haley  Oleynik  on 3/16/21.
 */

#ifndef Recruitment_h
#define Recruitment_h


/*
 * recruitment namespace
 */
namespace recruitment{


/**
 * Recruitment base class. Inherits from modelbase.
 */
template <class T>//T can be any type, double float, variable, etc.
class recruitment_base:public modelbase<T>{
protected:  //when class inherits from recruitment, can see
    //member fields common to all that inherit from recruitment_base
    T R0_m;
    T h_m;
    
public:
    /**
     *virtual function required to be overloaded by
     *all children of recruitment_base.
     */
    virtual T evaluate(const T& SB0, const T& SB)=0;
};


/**
 *Beverton-Holt implementation. Inherits from recruitment_base.
 */
template <class T>//T can be any type, double float, variable, etc.
class beverton_holt:public recruitment_base<T>{
    
public:
    
    /*
     *Default constructor
     */
    beverton_holt(){
        
    }
    
    /**
     *Constructor that takes arguments
     */
    beverton_holt(T R0, T h){  // constructor
        this->R0_m=R0;
        this->h_m=h;
    }
    
    /**
     * Destructor
     */
    ~ beverton_holt(){    //destructor
        std::cout <<"I just deleted"<<std::endl;
    }
    
    /**
     *Beverton-Holt implementation of the virtual evaluate function. Required to be overloaded.
     *Same look as recruitment_base, different behavior....polymorphism.
     */
    virtual T evaluate(const T& SB0, const T& SB){
        return (0.8*this->R0_m*this->h_m*SB)/(0.2*SB0*(1-this->h_m) + SB*(this->h_m-0.2));
    }
    
};

/**
 *Ricker implementation. Inherits from recruitment_base.
 */
template <class T>//T can be any type, double float, variable, etc.
class ricker:public recruitment_base<T>{
    
public:
    
    /*
     *Default constructor
     */
    ricker(){
        
    }
    
    /**
     *Constructor that takes arguments
     */
    ricker(T R0, T h){  // constructor
        this->R0_m=R0;
        this->h_m=h;
    }
    
    /**
     * Destructor
     */
    ~ ricker(){    //destructor
        std::cout <<"I just deleted"<<std::endl;
    }
    
    /**
     *Ricker implementation of the virtual evaluate function. Required to be overloaded.
     *Same look as recruitment_base, different behavior....polymorphism.
     */
    virtual T evaluate(const T& SB0, const T& SB){
        return SB/(SB0/this->R0_m)*exp(this->h_m*(1-SB/(this->R0_m*(SB0/this->R0_m))));
    }
    
};

}//end of recruitment namespace

#endif /* Recruitment_h */
