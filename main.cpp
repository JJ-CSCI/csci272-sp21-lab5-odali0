//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real 
{
  protected:
  double a;
  public:
  
   Real (double realValue){
    a = realValue;
   }

   Real(){}

  double GetReal() const{ 
    return a;
    }

  Real operator+ (double num){
    return num + a;
    }
};

class Complex:protected Real
{
  protected:
  double rv1;
  //double rv2;
  public:
  Complex(double r, double v){
    Real() = r;
    rv1 = v;
  }

  Complex(){}
  
  double GetImaginary() const{
    return rv1;
   }

   Complex operator+ (double numb){
     return rv1 + numb;
   }
};

class Surreal:protected Complex
{
  protected:
  double rv2;

  public:

  Surreal(double x, double y, double z){

    Real() =x;
    Complex() = y;
    rv2 = z;

  }

  double GetSurreal(){
    return rv2;
  }

  Surreal operator+(double number){
    return rv2+number;
  }
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
        REQUIRE( r.GetSurreal() == 32.0 );
    }
}
//------------------------------
