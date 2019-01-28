// Please implement Boost.Test unit test for class Fraction
//
#include "frac/Fraction.hxx"

#define BOOST_TEST_DYNLINK

#define BOOST_TEST_MODULE "Fraction"

#include <boost/test/unit_test.hpp>

using namespace frac;

struct FractionFixture
{
    void setup(){}
    void teardown(){}
};

BOOST_FIXTURE_TEST_SUITE(test_Fraction,FractionFixture)

    BOOST_AUTO_TEST_CASE(test_constructors)
    {
        BOOST_TEST((false));
    }

BOOST_AUTO_TEST_SUITE_END()

