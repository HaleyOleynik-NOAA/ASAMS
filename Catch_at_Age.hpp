//
//  Catch_at_Age.hpp
//  Catch_at_Age
//
//

#ifndef Catch_at_Age_h
#define Catch_at_Age_h

#include "Survey.hpp"
#include "Fleet.hpp"
#include "Population.hpp"
#include <vector>
#include <map>
#include <set>


namespace asams{
template <class T>
class catch_at_age:public model_base<T>{
public:
    // vectors
    std::set<fleet<T>*> fleet_master;
    std::set<survey<T>*> survey_master;
    std::map<int, std::vector<fleet<T>*> > fleets_m;
    std::map<int, std::vector<survey<T>*> > surveys_m;
    population<T>* population_m;
    int nyears;
    
    void compute_derived_quantities() {
        population_m->prepare();
        population_m->calculate_initial_numbers_at_age();
        for(int y=0;y<nyears;y++){
            population_m->calculate_growth();
            population_m->calculate_maturity(y);
            population_m->calculate_mortality(y, fleets_m[y]);
            population_m->calculate_numbers_at_age(y);
            population_m->calculate_spawning_stock_biomass(y);
            population_m->calculate_recruitment(y);
            population_m->calculate_catch_at_age(y);
            population_m->calculate_survey_numbers_at_age(y);

        }
    }
    T likelihood(){                // objective function
        T total_likelihood;
    }
};
}


#endif /* Catch_at_Age_h */

