#include "Common.hpp"
#include "catch_amalgamated.hpp"

template< typename T>
TEMPLATE_TEST_CASE( "Logistic of 100 is 1 (fail)", "[single-file]" ) {
  asams::logistic<T> logisticCurve(5,2);
  
  REQUIRE( logisticCurve.evaluate(100) == 1 );
}
