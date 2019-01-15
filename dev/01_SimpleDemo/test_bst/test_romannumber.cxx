/**
 * @file test_romannumber.cxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Boost test suite for romannumber
 * @version 0.1
 * @date 2019-01-15
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include "SimpleDemo/romannumber.hxx"

#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE "RomanNumber"

#include <boost/test/unit_test.hpp>

#include <limits>

using namespace SimpleDemo;

BOOST_AUTO_TEST_CASE(TestValid)
{
    BOOST_CHECK_EQUAL(getRoman(1),"I");
    BOOST_CHECK_EQUAL(getRoman(2),"II");
    BOOST_CHECK_EQUAL(getRoman(3),"III");
    BOOST_CHECK_EQUAL(getRoman(4),"IV");
    BOOST_CHECK_EQUAL(getRoman(5),"V");
    BOOST_CHECK_EQUAL(getRoman(6),"VI");
    BOOST_CHECK_EQUAL(getRoman(7),"VII");
    BOOST_CHECK_EQUAL(getRoman(8),"VIII");
    BOOST_CHECK_EQUAL(getRoman(9),"IX");
    BOOST_CHECK_EQUAL(getRoman(10),"X"); 
    BOOST_CHECK_EQUAL(getRoman(11),"XI");
    BOOST_CHECK_EQUAL(getRoman(22),"XXII");
    BOOST_CHECK_EQUAL(getRoman(33),"XXXIII");
    BOOST_CHECK_EQUAL(getRoman(44),"XLIV");
    BOOST_CHECK_EQUAL(getRoman(55),"LV");
    BOOST_CHECK_EQUAL(getRoman(66),"LXVI");
    BOOST_CHECK_EQUAL(getRoman(77),"LXXVII");
    BOOST_CHECK_EQUAL(getRoman(88),"LXXXVIII");
    BOOST_CHECK_EQUAL(getRoman(99),"XCIX");
    BOOST_CHECK_EQUAL(getRoman(100),"C");  
    BOOST_CHECK_EQUAL(getRoman(111),"CXI");
    BOOST_CHECK_EQUAL(getRoman(222),"CCXXII");
    BOOST_CHECK_EQUAL(getRoman(333),"CCCXXXIII");
    BOOST_CHECK_EQUAL(getRoman(444),"CDXLIV");
    BOOST_CHECK_EQUAL(getRoman(555),"DLV");
    BOOST_CHECK_EQUAL(getRoman(666),"DCLXVI");
    BOOST_CHECK_EQUAL(getRoman(777),"DCCLXXVII");
    BOOST_CHECK_EQUAL(getRoman(888),"DCCCLXXXVIII");
    BOOST_CHECK_EQUAL(getRoman(999),"CMXCIX");
    BOOST_CHECK_EQUAL(getRoman(1000),"M");   
    BOOST_CHECK_EQUAL(getRoman(1111),"MCXI");
    BOOST_CHECK_EQUAL(getRoman(2222),"MMCCXXII");
    BOOST_CHECK_EQUAL(getRoman(3333),"MMMCCCXXXIII");
    BOOST_CHECK_EQUAL(getRoman(4444),"MMMMCDXLIV");
    BOOST_CHECK_EQUAL(getRoman(5555),"MMMMMDLV");
    BOOST_CHECK_EQUAL(getRoman(6666),"MMMMMMDCLXVI");
    BOOST_CHECK_EQUAL(getRoman(7777),"MMMMMMMDCCLXXVII");
    BOOST_CHECK_EQUAL(getRoman(8888),"MMMMMMMMDCCCLXXXVIII");
    BOOST_CHECK_EQUAL(getRoman(9999),"MMMMMMMMMCMXCIX");
    BOOST_CHECK_EQUAL(getRoman(10000),"MMMMMMMMMM");
    BOOST_CHECK_EQUAL(getRoman(std::numeric_limits<std::uint16_t>::max()),"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXXXV");
}

BOOST_AUTO_TEST_CASE(TestZero)
{
    BOOST_CHECK_THROW(getRoman(0),std::runtime_error);
}
