//  Survey.hpp
//  Age Structured Assessment Modeling System (ASAMS)

#ifndef Survey_h
#define Survey_h

#include "Common.hpp"
#include "Data.hpp"
#include "Selectivity.hpp"
#include "Data.hpp"

namespace asams{

template<class T>
 class survey: public model_base<T>{
  public:
    index_data<T>* observed_index_data;
    agecomp_data<T>* observed_agecomp_data;
    
    //derived quantities
    std::vector<T> survey_at_age;
    std::vector<T> derived_index_data;
    std::vector<T> derived_agecomp_data;
    
    //operators
    selectivity_base<T>* selectivity_model;
     T q;
     int nyears;
     int nages;
     
     survey(int nyears, int nages ){  // constructor
         this-> nyears = nyears;
         this-> nages = nages;
         survey_at_age.resize(nyears*nages);
         derived_index_data.resize(nyears);
         derived_agecomp_data.resize(nyears*nages);
     }
     
     void prepare(){                                 // reset all values in containers
         
         for(int i = 0; i < nyears; i++){
             derived_index_data[i]=0;
             
             for(int j = 0; j < nages; j++){
                 int index = i*nages+j;
                 survey_at_age[index]=0;
                 derived_agecomp_data[index]=0;
             }
             
         }
     }
     
     T likelihood(){
         
     }
    
 };

}


#endif /* Survey_h */
