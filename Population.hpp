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

namespace population{
  
 template <class T>
  class population:public modelbase<T>{
    public:
    
    //derived quantities
    std::vector<T> initial_numbers_at_age;
    std::vector<T> recruitment;
    std::vector<T> numbers_at_age;
    std::vector<T> weight_at_age;
    std::vector<T> ssb;
    std::vectpr<T> abundance;
    std::vectpr<T> biomass;
    
    //life history submodels
    int nyears;
    int nages;
    std::vectpr<T> ages;
    growth_base* growth_model;
    recruitment_base* recruitment_model;
    mortality_base* mortality_model;
    
    population(){
      
    }
    
    
    void initialize(int nyears, int nages){          // initialize function
      
    }
    
    void prepare(){                                 // reset all values in containers
    }
    
    void calculate_mortality(){
    }
    
    void calculate_maturity(){
    }
    
    void calculate_initial_numbers_at_age(){
    }
    
    void calculate_numbers_at_age(){
    }
    
    void calculate_growth(){
    }
    
    void calculate_stock_spawning_biomass(){
    }
    
    void calculate_recruitment(){
    }
    
    void calculate_catch_at_age(){
    }
    
    void calculate_survey_numbers_at_age(){
    }
    
    void evaluate(){
      
    }
  }
}

#endif /* Population_h */
