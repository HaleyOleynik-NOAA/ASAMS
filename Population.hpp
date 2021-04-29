//
//  Population.hpp
//  Catch_at_Age
//
//

#ifndef Population_h
#define Population_h

#include "Common.hpp"
#include "Growth.hpp"
#include "Recruitment.hpp"
#include "Mortality.hpp"
//#include "Survey.hpp"
//#include "Fleet.hpp"


namespace asams{
  
 template <class T>
  class population:public model_base<T>{
    public:
    
    //derived quantities
    std::vector<T> initial_numbers_at_age;
    std::vector<T> recruitment;
    std::vector<T> numbers_at_age;
    std::vector<T> weight_at_age;
    std::vector<T> ssb;
    std::vector<T> abundance;
    std::vector<T> biomass;
    
    //life history submodels
    int nyears;
    int nages;
    std::vector<T> ages;
    growth_base<T>* growth_model;
    recruitment_base<T>* recruitment_model;
    mortality_base<T>* mortality_model;
    
    population(){
      
    }
    
    void initialize(int nyears, int nages){          // initialize function
      
    }
    
    void prepare(){                                 // reset all values in containers
    }
    
    //void calculate_mortality(int year, std::vector<fleet<T>*>& fleets){
    //}
    
    void calculate_maturity(int year){
    }
    
    void calculate_initial_numbers_at_age(){
    }
    
    void calculate_numbers_at_age(int year){
    }
    
    void calculate_growth(int year){
    }
    
    void calculate_spawning_stock_biomass(int year){
    }
    
    void calculate_recruitment(int year){
    }
    
    //void calculate_catch_at_age(int year, std::vector<fleet<T>*>& fleets){
    //}
    
    //void calculate_catch_at_age(int year, std::vector<survey<T>*>& surveys){
    //}
    
  };
}

#endif /* Population_h */
