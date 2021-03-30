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

int main(int argc, const char * argv[]) {
    selectivity::logistic<double> myselectivity(5.0,0.7); //replaces T with double
    std::cout<<myselectivity.evaluate(5.0)<<std::endl;
    
    recruitment::beverton_holt<double> myrecruitment(1000,0.7);
    std::cout<<myrecruitment.evaluate(150,50)<<std::endl;
    
    recruitment::ricker<double> myrecruitment2(1000,0.7);
    std::cout<<myrecruitment2.evaluate(150,50)<<std::endl;
    
    mortality::test_mortality();
    
    return 0;
}
