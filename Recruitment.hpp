//  Recruitment.hpp
//  Age Structured Assessment Modeling System (ASAMS)

#ifndef Recruitment_h
#define Recruitment_h

namespace asams{

template <class T>
class recruitment_base:public model_base<T>{
protected:  //when class inherits from recruitment, can see
    T R0_m;
    T h_m;
    
public:
    virtual T evaluate(const T& SB0, const T& SB)=0;
};

template <class T>
class beverton_holt:public recruitment_base<T>{
    
public:
    
    beverton_holt(){
        
    }
    
    beverton_holt(T R0, T h){  // constructor
        this->R0_m=R0;
        this->h_m=h;
    }
    
    ~ beverton_holt(){    //destructor
        std::cout <<"I just deleted"<<std::endl;
    }
    
    virtual T evaluate(const T& SB0, const T& SB){
        return (0.8*this->R0_m*this->h_m*SB)/(0.2*SB0*(1-this->h_m) + SB*(this->h_m-0.2));
    }
    
};

template <class T>
class ricker:public recruitment_base<T>{
    
public:
    
    ricker(){
        
    }
    
    ricker(T R0, T h){  // constructor
        this->R0_m=R0;
        this->h_m=h;
    }
    
    ~ ricker(){    //destructor
        std::cout <<"I just deleted"<<std::endl;
    }
    
    virtual T evaluate(const T& SB0, const T& SB){
        return SB/(SB0/this->R0_m)*exp(this->h_m*(1-SB/(this->R0_m*(SB0/this->R0_m))));
    }
    
};

}

#endif /* Recruitment_h */
