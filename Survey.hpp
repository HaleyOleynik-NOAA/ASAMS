//
//  Survey.hpp
//  Catch_at_Age
//
//  Created by Haley  Oleynik  on 3/16/21.
//

#ifndef Survey_h
#define Survey_h

#include "Common.hpp"
#include "Data.hpp"
#include "Selectivity.hpp"
#include "Population.hpp"
#include "Data.hpp"

namespace asams{

template<class T>
 class survey: public model_base<T>{
  public:
    population<T>* population;
    index_data<T>* observed_index_data;
    agecomp_data<T>* observed_agecomp_data;
    
    //derived quantities
    std::vector<T> survey_at_age;
    std::vector<T> derived_index_data;
    std::vector<T> derived_agecomp_data;
    
    //operators
    selectivity_base<T>* selectivity_model;
     T q;
     
     T likelihood(){
         
     }
    
 };

}


#endif /* Survey_h */


