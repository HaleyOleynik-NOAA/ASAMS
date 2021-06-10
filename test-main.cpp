#include "Common.hpp"
#include "catch_amalgamated.hpp""
using namespace asams;

TEST_CASE( "Logistic of 100 is 1 (fail)", "[single-file]" ) {
  logistic(5,2) logisticCurve;
  
  REQUIRE( logisticCurve(100) == 1 );
}