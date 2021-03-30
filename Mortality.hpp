//
//  Mortality.hpp
//  Catch_at_Age
//
//

#ifndef Mortality_h
#define Mortality_h

#include "Common.hpp"

#include <iostream>
#include <vector>
#include <map>

namespace mortality{
  
template <class T>
class mortality:public modelbase<T>{
protected:
  typedef typename std::vector<std::vector<T> > matrix;
  typedef typename std::vector<T> vector;
  matrix mortality_m;
    
public:
  
    mortality(int rows = 0, int cols= 0){
        this->mortality_m = matrix(rows, vector(cols));
      }
     
    inline T& operator()(size_t i, size_t j) {    //overloaded operator
      return this->mortality_m[i][j];
    }

};
  
  void test_mortality(){
    mortality<double> natural_mortality(10, 10);
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            natural_mortality(i, j) = i*j;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << natural_mortality(i, j) << "\t";
        }
        std::cout<<"\n";
    }

}
}


#endif /* Mortality_h */
