/**
 * @file test_RomanNumber.cxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief unit tests for class romannumber based on Goolge
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */
#include "roman/RomanNumber.hxx"

#include "gtest/gtest.h"

#include <map>
#include <functional>

using std::function;
using std::map;
using std::string;
using std::uint16_t;

using roman::RomanNumber;

class test_RomanNumber : public testing::Test
{

    void SetUp() override
    {}

    void TearDown() override
    {}
    
protected:
    
    map<uint16_t,string> valid_values_ = {
        {1,"i"},{2,"ii"},{3,"iii"},{4,"iv"},{5,"v"},{6,"vi"},{7,"vii"},{8,"viii"},{9,"ix"},{10,"x"},
        {11,"xi"},{22,"xxii"},{33,"xxxiii"},{44,"xliv"},{55,"lv"},{66,"lxvi"},{77,"lxxvii"},{88,"lxxxviii"},{99,"xcix"},{100,"c"},
        {111,"cxi"},{222,"ccxxii"},{333,"cccxxxiii"},{444,"cdxliv"},{555,"dlv"},{666,"dclxvi"},{777,"dcclxxvii"},{888,"dccclxxxviii"},{999,"cmxcix"},{1000,"m"},
        {1111,"mcxi"},{2222,"mmccxxii"},{3333,"mmmcccxxxiii"},{4444,"mmmmcdxliv"},{5555,"mmmmmdlv"},{6666,"mmmmmmdclxvi"},
        {7777,"mmmmmmmdcclxxvii"},{8888,"mmmmmmmmdccclxxxviii"},{9999,"mmmmmmmmmcmxcix"},{10000,"mmmmmmmmmm"}};
    int invalid_value_ = 0;


};

/**
 * @brief Check if constructor works as expected. Ok, if valid numbers are constructed with expected values
 */
TEST_F(test_RomanNumber,constructors)
{
    for (const auto testdata : valid_values_)
    {
        RomanNumber rm(testdata.first);
        ASSERT_EQ(rm.getValue(),testdata.first);
        ASSERT_TRUE(rm.isValid());
    }
    RomanNumber rm(invalid_value_);
    ASSERT_EQ(rm.getValue(),invalid_value_);
    ASSERT_FALSE(rm.isValid());
}

/**
 * @brief Check if expected roman numbers are returned by toString
 * 
 */
TEST_F(test_RomanNumber,toString)
{
    for (const auto testdata : valid_values_)
    {
        RomanNumber rm(testdata.first);
        ASSERT_EQ(rm.toString(),testdata.second);
    }
    RomanNumber rm(0);
    ASSERT_TRUE(rm.toString().empty());
}

TEST_F(test_RomanNumber,asignment)
{
    RomanNumber myNumber(7);
    ASSERT_EQ(myNumber.toString(),"vii");
    for (const auto testdata : valid_values_)
    {
        myNumber = RomanNumber(testdata.first);
        ASSERT_EQ(myNumber.getValue(),testdata.first);
        ASSERT_EQ(myNumber.toString(),testdata.second);
    }
}

/**
 * @brief Test if == operator works as expected
 * 
 */
TEST_F(test_RomanNumber,comparison)
{
    RomanNumber myNumber1(1234);
    RomanNumber myNumber2(1234);
    ASSERT_TRUE(myNumber1==myNumber2);
    myNumber1 = 2345;
    RomanNumber myNumber3(2345);
    ASSERT_TRUE(myNumber1==myNumber3);
    ASSERT_FALSE(myNumber2==myNumber1);
}

/**
 * @brief Tests if - and -= operators work as expected.
 * 
 */
TEST_F(test_RomanNumber,minusOp)
{
    RomanNumber num1(47), num2(46);
    num1 -= num2;
    ASSERT_EQ(num1.getValue(),1);
    ASSERT_THROW(num1-=num2,std::range_error);
    ASSERT_EQ(0,(num2-=46).getValue());

    auto res = RomanNumber(10)-RomanNumber(5);
    ASSERT_TRUE(res==5);
    ASSERT_THROW(res = RomanNumber(5)-RomanNumber(10),std::range_error);
}
