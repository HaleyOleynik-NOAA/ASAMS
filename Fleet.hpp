//  Fleet.hpp
//  Age Structured Assessment Modeling System (ASAMS)

#ifndef Fleet_h
#define Fleet_h


#include "Common.hpp"
#include "Selectivity.hpp"
#include "Data.hpp"
#include "Mortality.hpp"

namespace asams{

template<class T>
 class fleet: public model_base<T>{
  public:
    index_data<T>* observed_index_data;
    agecomp_data<T>* observed_agecomp_data;
    
    //derived quantities
    std::vector<T> landings;
    std::vector<T> catch_at_age;
    std::vector<T> z_at_age;
    std::vector<T> derived_index_data;
    std::vector<T> derived_agecomp_data;
    std::vector<T> f_at_age;
     int nyears;
     int nages;
     
    
    //operators
    selectivity_base<T>* selectivity_model;
    std::vector<T> fishing_mortality;
     
     fleet(int nyears, int nages ){  // constructor
         this-> nyears = nyears;
         this-> nages = nages;
         
         landings.resize(nyears);
         catch_at_age.resize(nyears*nages);
         z_at_age.resize(nyears*nages);
         derived_index_data.resize(nyears);
         derived_agecomp_data.resize(nyears*nages);
         fishing_mortality.resize(nyears);
     }
     
     void prepare(){                                 // reset all values in containers
         for(int i = 0; i < nyears; i++){
             landings[i]=0;
             fishing_mortality[i]=0;
             derived_index_data[i]=0;
             
             for(int j = 0; j < nages; j++){
                 int index = i*nages+j;
                 catch_at_age[index]=0;
                 derived_agecomp_data[index]=0;
                 z_at_age[index]=0;
             }
             
         }
     }
     
     T likelihood(){
         
     }
    
 };

}

#endif /* Fleet_h */

