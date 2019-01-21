/**
 * @file test_RomanNumber.h
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief CxxTest testsuite for roman numbers
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include "roman/RomanNumber.hxx"

#include <map>
#include <string>

using namespace roman;

using std::map;
using std::string;

class test_RomanNumber : public CxxTest::TestSuite
{
public:
    void test_constructors(void)
    {
        for (const auto testdata : valid_values_)
        {
            RomanNumber rm(testdata.first);
            TS_ASSERT_EQUALS(rm.getValue(),testdata.first);
            TS_ASSERT(rm.isValid());
        }
        RomanNumber rm(invalid_value_);
        TS_ASSERT_EQUALS(rm.getValue(),invalid_value_);
        TS_ASSERT(!rm.isValid());
    }

    void test_toString(void)
    {
        for (const auto testdata : valid_values_)
        {
            RomanNumber rm(testdata.first);
            TS_ASSERT_EQUALS(rm.toString(),testdata.second);
        }
        RomanNumber rm{0};
        TS_ASSERT(rm.toString().empty());
    }

    void test_assignment(void)
    {
        RomanNumber myNumber(7);
        TS_ASSERT_EQUALS(myNumber.toString(),"vii");
        for (const auto testdata : valid_values_)
        {
            myNumber = RomanNumber(testdata.first);
        }
    }

    void test_comparisom(void)
    {
        RomanNumber myNumber1(1234);
        RomanNumber myNumber2(1234);
        TS_ASSERT(myNumber1==myNumber2);
        myNumber1 = 2345;
        RomanNumber myNumber3(2345);
        TS_ASSERT(myNumber1==myNumber3);
        TS_ASSERT(!(myNumber2==myNumber1));
    }

    void test_minus(void)
    {
        RomanNumber num1(47), num2(46);
        num1 -= num2;
        TS_ASSERT_EQUALS(num1.getValue(),1);
        TS_ASSERT_THROWS(num1-=num2,std::range_error);
        TS_ASSERT_EQUALS(0,(num2-=46).getValue());

        auto res = RomanNumber(10)-RomanNumber(5);
        TS_ASSERT(res==5);
        TS_ASSERT_THROWS(res = RomanNumber(5)-RomanNumber(10),std::range_error);
    }



private:
    map<uint16_t,string> valid_values_ = {
        {1,"i"},{2,"ii"},{3,"iii"},{4,"iv"},{5,"v"},{6,"vi"},{7,"vii"},{8,"viii"},{9,"ix"},{10,"x"},
        {11,"xi"},{22,"xxii"},{33,"xxxiii"},{44,"xliv"},{55,"lv"},{66,"lxvi"},{77,"lxxvii"},{88,"lxxxviii"},{99,"xcix"},{100,"c"},
        {111,"cxi"},{222,"ccxxii"},{333,"cccxxxiii"},{444,"cdxliv"},{555,"dlv"},{666,"dclxvi"},{777,"dcclxxvii"},{888,"dccclxxxviii"},{999,"cmxcix"},{1000,"m"},
        {1111,"mcxi"},{2222,"mmccxxii"},{3333,"mmmcccxxxiii"},{4444,"mmmmcdxliv"},{5555,"mmmmmdlv"},{6666,"mmmmmmdclxvi"},
        {7777,"mmmmmmmdcclxxvii"},{8888,"mmmmmmmmdccclxxxviii"},{9999,"mmmmmmmmmcmxcix"},{10000,"mmmmmmmmmm"}};
    int invalid_value_ = 0;
};