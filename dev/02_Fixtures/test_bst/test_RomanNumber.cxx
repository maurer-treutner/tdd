/**
 * @file test_romannumber.cxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Boost test suite for roman::RomanNumber
 * @version 0.1
 * @date 2019-01-15
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include "roman/RomanNumber.hxx"

#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE "RomanNumber"

#include <boost/test/unit_test.hpp>

#include <map>
#include <string>

using namespace roman;

using std::map;
using std::string;

using namespace roman;

struct RomanNumberFixture
{
    RomanNumberFixture()=default;
    virtual ~RomanNumberFixture()=default;

    void setup(){}
    void teardown(){}

    map<uint16_t,string> valid_values_ = {
        {1,"i"},{2,"ii"},{3,"iii"},{4,"iv"},{5,"v"},{6,"vi"},{7,"vii"},{8,"viii"},{9,"ix"},{10,"x"},
        {11,"xi"},{22,"xxii"},{33,"xxxiii"},{44,"xliv"},{55,"lv"},{66,"lxvi"},{77,"lxxvii"},{88,"lxxxviii"},{99,"xcix"},{100,"c"},
        {111,"cxi"},{222,"ccxxii"},{333,"cccxxxiii"},{444,"cdxliv"},{555,"dlv"},{666,"dclxvi"},{777,"dcclxxvii"},{888,"dccclxxxviii"},{999,"cmxcix"},{1000,"m"},
        {1111,"mcxi"},{2222,"mmccxxii"},{3333,"mmmcccxxxiii"},{4444,"mmmmcdxliv"},{5555,"mmmmmdlv"},{6666,"mmmmmmdclxvi"},
        {7777,"mmmmmmmdcclxxvii"},{8888,"mmmmmmmmdccclxxxviii"},{9999,"mmmmmmmmmcmxcix"},{10000,"mmmmmmmmmm"}};
    int invalid_value_ = 0;
};


BOOST_FIXTURE_TEST_SUITE(test_RomanNumber,RomanNumberFixture)

    BOOST_AUTO_TEST_CASE(test_constrouctors)
    {
        for (const auto testdata : valid_values_)
        {
            RomanNumber rm(testdata.first);
            BOOST_TEST(rm.getValue()==testdata.first);
            BOOST_TEST(rm.isValid());
        }
        RomanNumber rm(invalid_value_);
        BOOST_TEST(rm.getValue()==invalid_value_);
        BOOST_TEST(!rm.isValid());

    }

BOOST_AUTO_TEST_SUITE_END()