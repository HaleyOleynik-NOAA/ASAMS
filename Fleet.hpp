//
//  Fleet.hpp
//  Catch_at_Age
//
//

#ifndef Fleet_h
#define Fleet_h


#include "Common.hpp"
#include "Selectivity.hpp"
#include "Data.hpp"
#include "Mortality.hpp"

namespace fleet{

template<class T>
 class fleet: public model_base<T>{
  public:
    population<T>* population;
    index_data<T>* observed_index_data;
    agecomp_data<T>* observed_agecomp_data;
    
    //derived quantities
    std::vector<T> landings;
    std::vector<T> catch_at_age;
    std::vector<T> z_at_age;
    std::vector<T> derived_index_data;
    std::vector<T> derived_agecomp_data;
    
    //operators
    selectivity_base* selectivity_model;
    std::vector<T> fishing_mortality;
     
     void evaluate(){
         
     }
    
}

}

#endif /* Fleet_h */
