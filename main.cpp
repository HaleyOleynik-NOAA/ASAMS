//
//  main.cpp
//  Catch_at_Age
//
//  Created by Haley  Oleynik  on 3/16/21.
//

#include <iostream>
#include "Selectivity.hpp"
#include "Recruitment.hpp"
#include "Mortality.hpp"
#include "Data.hpp"

int main(int argc, const char * argv[]) {
    selectivity::logistic<double> myselectivity(5.0,0.7); //replaces T with double
    std::cout<<myselectivity.evaluate(5.0)<<std::endl;
    
    recruitment::beverton_holt<double> myrecruitment(1000,0.7);
    std::cout<<myrecruitment.evaluate(150,50)<<std::endl;
    
    recruitment::ricker<double> myrecruitment2(1000,0.7);
    std::cout<<myrecruitment2.evaluate(150,50)<<std::endl;
    
    mortality::test_mortality();
    
    data::agecomp_data<double> myagecomp(10,10);
    for(int i = 0; i<myagecomp.imax_m; i++){
        for(int j=0; j<myagecomp.jmax_m; j++){
            myagecomp(i,j)=3.1459;
            std::cout<<myagecomp(i,j)<<std::endl;
        }
    }

    data::index_data<double> d(10);
    std::cout<<d.imax_m<<"\n";
    for(int i =0; i < 10; i++){
        d(i) = 3.1459;
        std::cout<<d(i)<<"\n";
    }
    
    
    return 0;
}
