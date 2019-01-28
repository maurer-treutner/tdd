//
// Please declare class Fraction for fractional arithmethic
//
// It shall have the following functions:
//      Defaultconstructor: -> value = 0/1
//      Constructor from two ints (numerator,denominator) with automatic cancaling
//      function cancel for cancelation
//      operators +=,-=,*=,/=,+,-,*,/
//      function to get a floating point number
// 

#include <cstdint>

namespace frac
{

class Fraction
{
public:
    using ValueType = uint64_t;

    Fraction();

private:
    ValueType num_=0; // numerator
    ValueType den_=1; // denominator
};

};