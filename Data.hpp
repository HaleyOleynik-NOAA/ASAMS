//
//  Data.hpp
//
//
//

#ifndef Data_h
#define Data_h

#include <vector>

namespace data{

 template <class T>
   class data_base{
     public:
     std::vector<T> data_m;
     int imax_m;
     int jmax_m;
     
     data_base(int imax, int jmax = 1)
       :imax_m(imax), jmax_m(jmax){
       data_m.resize(imax * jmax+1);
       std::fill(this->data_m.begin(), this->data_m.end(), T());
     }
     
     
      T& operator ()(int i, int j = 1){
       return data_m[i * jmax_m + j];   // dimension folding
     }
     
     
   };
               
 template <class T>
   class index_data:public data_base<T>{
     public:
     
     index_data(int nyears):data_base<T>(nyears){
     }
     
   };
     
 template <class T>
   class agecomp_data:public data_base<T>{
     public:
     
     agecomp_data(int nyears, int nage):data_base<T>(nyears, nage){
     }
     
   };

}

#endif /* Data_h */
