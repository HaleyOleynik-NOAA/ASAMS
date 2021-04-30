//  Population.hpp
//  Age Structured Assessment Modeling System (ASAMS)

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
    std::vector<T> mortality;
    
    //life history submodels
    int nyears;
    int nages;
    std::vector<T> ages;
    growth_base<T>* growth_model;
    recruitment_base<T>* recruitment_model;
    mortality_base<T>* mortality_model;
    
    population(){
      
    }
    
      population(int nyears, int nages ){  // constructor
          this-> nyears = nyears;
          this-> nages = nages;
          initial_numbers_at_age.resize(nages);
          recruitment.resize(nyears);
          numbers_at_age.resize(nyears*nages);
          weight_at_age.resize(nyears*nages);
          ssb.resize(nyears);
          abundance.resize(nyears);
          biomass.resize(nyears);
          mortality.resize(nyears*nages);
      }
    
    void prepare(){                                 // reset all values in containers
        std::fill(initial_numbers_at_age.begin(), initial_numbers_at_age.end(),0);
        
        for(int i = 0; i < nyears; i++){
            recruitment[i]=0;
            ssb[i]=0;
            abundance[i]=0;
            biomass[i]=0;
            
            for(int j = 0; j < nages; j++){
                int index = i*nages+j;
                numbers_at_age[index]=0;
                weight_at_age[index]=0;
                mortality[index]=0;
            }
            
        }
    }
    
    void calculate_mortality(int year, std::vector<fleet<T>*>& fleets){
        
    }
    
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
    
    void calculate_catch_at_age(int year, std::vector<fleet<T>*>& fleets){
    }
    
    void calculate_survey_numbers_at_age(int year, std::vector<survey<T>*>& surveys){
    }
    
  };
}

#endif /* Population_h */
