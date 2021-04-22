//
//  Survey.hpp
//  Catch_at_Age
//

#ifndef Survey_h
#define Survey_h

#include "Common.hpp"
#include "Data.hpp"
#include "Selectivity.hpp"

namespace survey{

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
    selectivity_base* selectivity_model;
    T q
     
     T likelihood(){
         
     }
    
}

}


#endif /* Survey_h */


