#include "../Common.hpp"
#include "catch_amalgamated.hpp"


TEST_CASE( "Logistic of 100 is 1 (fail)", "[single-file]" ) {
  asams::logistic<double> logisticCurve(5,2);
  
  REQUIRE( logisticCurve.evaluate(100) == 1 );
}
