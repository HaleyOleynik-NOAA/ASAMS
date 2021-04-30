//  Growth.hpp
//  Age Structured Assessment Modeling System (ASAMS)

#ifndef growth_h
#define growth_h

#include "Common.hpp"
#include <map>
#include <vector>
/*
 * growth namespace
 */
namespace asams{

/**
 * Growth base class. Inherits from modelbase.
 */
template <class T>

class growth_base:public model_base<T>{
protected:

public:
  virtual T evaluate(const T& age)=0;
};

  
  
  template <class T>

class empirical_growth: public growth_base<T>{

  std::vector<std::map<T, T> > growth;
public:
  std::map<T, T> survey_growth;
  std::map<T, T> catch_growth;
  
  enum GROWTH_TYPE{
    SURVEY=0,
    CATCH
  };
    
  
  empirical_growth(){
    growth = {survey_growth,catch_growth};
  }
  
   virtual T evaluate(const T& age, GROWTH_TYPE t) {
     return this->growth[t][age];
   }

};
/**
 *von Bertalanffy implementation. Inherits from growth_base.
 */
template <class T>

class vonBertalanffy: public growth_base<T>{

public:
  T m_Linf;
  T m_K;
  T m_t0;

  /*
   *Default constructor
   */
  vonBertalanffy(){

  }

  /**
   *Constructor that takes arguments
   */
  vonBertalanffy(T Linf, T K, T t0){
    this->m_Linf = Linf;
    this->m_K = K;
    this->m_t0 = t0;
  }

  /**
   * Destructor
   */
  ~ vonBertalanffy(){
    std::cout <<"I just deleted vonBertalanffy object" << std::endl;
  }

  /**
   *von Bertalanffy implementation of the virtual evaluate function. Required to be overloaded.
   */
  virtual T evaluate(const T& age) {
    return m_Linf * (1 - asams::exp(-m_K * (age - m_t0)));
  }

};

}

#endif /*growth_h */
