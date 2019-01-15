/**
 * @file mytestsuite.h
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief 
 * @version 0.1
 * @date 2019-01-14
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include "SimpleDemo/romannumber.hxx"

#include  <limits>

using namespace SimpleDemo;

class MyTestSyite1: public CxxTest::TestSuite
{
    public:

    void testValidNumber()
    {
        TS_ASSERT_EQUALS(getRoman(1),"I");
        TS_ASSERT_EQUALS(getRoman(2),"II");
        TS_ASSERT_EQUALS(getRoman(3),"III");
        TS_ASSERT_EQUALS(getRoman(4),"IV");
        TS_ASSERT_EQUALS(getRoman(5),"V");
        TS_ASSERT_EQUALS(getRoman(6),"VI");
        TS_ASSERT_EQUALS(getRoman(7),"VII");
        TS_ASSERT_EQUALS(getRoman(8),"VIII");
        TS_ASSERT_EQUALS(getRoman(9),"IX");
        TS_ASSERT_EQUALS(getRoman(10),"X"); 
        TS_ASSERT_EQUALS(getRoman(11),"XI");
        TS_ASSERT_EQUALS(getRoman(22),"XXII");
        TS_ASSERT_EQUALS(getRoman(33),"XXXIII");
        TS_ASSERT_EQUALS(getRoman(44),"XLIV");
        TS_ASSERT_EQUALS(getRoman(55),"LV");
        TS_ASSERT_EQUALS(getRoman(66),"LXVI");
        TS_ASSERT_EQUALS(getRoman(77),"LXXVII");
        TS_ASSERT_EQUALS(getRoman(88),"LXXXVIII");
        TS_ASSERT_EQUALS(getRoman(99),"XCIX");
        TS_ASSERT_EQUALS(getRoman(100),"C");  
        TS_ASSERT_EQUALS(getRoman(111),"CXI");
        TS_ASSERT_EQUALS(getRoman(222),"CCXXII");
        TS_ASSERT_EQUALS(getRoman(333),"CCCXXXIII");
        TS_ASSERT_EQUALS(getRoman(444),"CDXLIV");
        TS_ASSERT_EQUALS(getRoman(555),"DLV");
        TS_ASSERT_EQUALS(getRoman(666),"DCLXVI");
        TS_ASSERT_EQUALS(getRoman(777),"DCCLXXVII");
        TS_ASSERT_EQUALS(getRoman(888),"DCCCLXXXVIII");
        TS_ASSERT_EQUALS(getRoman(999),"CMXCIX");
        TS_ASSERT_EQUALS(getRoman(1000),"M");   
        TS_ASSERT_EQUALS(getRoman(1111),"MCXI");
        TS_ASSERT_EQUALS(getRoman(2222),"MMCCXXII");
        TS_ASSERT_EQUALS(getRoman(3333),"MMMCCCXXXIII");
        TS_ASSERT_EQUALS(getRoman(4444),"MMMMCDXLIV");
        TS_ASSERT_EQUALS(getRoman(5555),"MMMMMDLV");
        TS_ASSERT_EQUALS(getRoman(6666),"MMMMMMDCLXVI");
        TS_ASSERT_EQUALS(getRoman(7777),"MMMMMMMDCCLXXVII");
        TS_ASSERT_EQUALS(getRoman(8888),"MMMMMMMMDCCCLXXXVIII");
        TS_ASSERT_EQUALS(getRoman(9999),"MMMMMMMMMCMXCIX");
        TS_ASSERT_EQUALS(getRoman(10000),"MMMMMMMMMM");
        TS_ASSERT_EQUALS(getRoman(std::numeric_limits<std::uint16_t>::max()),"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXXXV");
    }

    void testZero()
    {
        TS_ASSERT_THROWS(getRoman(0),std::runtime_error);
    }
};