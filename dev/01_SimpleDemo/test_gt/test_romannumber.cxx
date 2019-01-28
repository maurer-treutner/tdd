#include "SimpleDemo/romannumber.hxx"
#include <gtest/gtest.h>

#include <limits>

using namespace SimpleDemo;

TEST(RomanNumberTest,testValidNumbers)
{
    ASSERT_EQ(getRoman(1),"I");
    ASSERT_EQ(getRoman(2),"II");
    ASSERT_EQ(getRoman(3),"III");
    ASSERT_EQ(getRoman(4),"IV");
    ASSERT_EQ(getRoman(5),"V");
    ASSERT_EQ(getRoman(6),"VI");
    ASSERT_EQ(getRoman(7),"VII");
    ASSERT_EQ(getRoman(8),"VIII");
    ASSERT_EQ(getRoman(9),"IX");
    ASSERT_EQ(getRoman(10),"X"); 
    ASSERT_EQ(getRoman(11),"XI");
    ASSERT_EQ(getRoman(22),"XXII");
    ASSERT_EQ(getRoman(33),"XXXIII");
    ASSERT_EQ(getRoman(44),"XLIV");
    ASSERT_EQ(getRoman(55),"LV");
    ASSERT_EQ(getRoman(66),"LXVI");
    ASSERT_EQ(getRoman(77),"LXXVII");
    ASSERT_EQ(getRoman(88),"LXXXVIII");
    ASSERT_EQ(getRoman(99),"XCIX");
    ASSERT_EQ(getRoman(100),"C");  
    ASSERT_EQ(getRoman(111),"CXI");
    ASSERT_EQ(getRoman(222),"CCXXII");
    ASSERT_EQ(getRoman(333),"CCCXXXIII");
    ASSERT_EQ(getRoman(444),"CDXLIV");
    ASSERT_EQ(getRoman(555),"DLV");
    ASSERT_EQ(getRoman(666),"DCLXVI");
    ASSERT_EQ(getRoman(777),"DCCLXXVII");
    ASSERT_EQ(getRoman(888),"DCCCLXXXVIII");
    ASSERT_EQ(getRoman(999),"CMXCIX");
    ASSERT_EQ(getRoman(1000),"M");   
    ASSERT_EQ(getRoman(1111),"MCXI");
    ASSERT_EQ(getRoman(2222),"MMCCXXII");
    ASSERT_EQ(getRoman(3333),"MMMCCCXXXIII");
    ASSERT_EQ(getRoman(4444),"MMMMCDXLIV");
    ASSERT_EQ(getRoman(5555),"MMMMMDLV");
    ASSERT_EQ(getRoman(6666),"MMMMMMDCLXVI");
    ASSERT_EQ(getRoman(7777),"MMMMMMMDCCLXXVII");
    ASSERT_EQ(getRoman(8888),"MMMMMMMMDCCCLXXXVIII");
    ASSERT_EQ(getRoman(9999),"MMMMMMMMMCMXCIX");
    ASSERT_EQ(getRoman(10000),"MMMMMMMMMM");
    ASSERT_EQ(getRoman(std::numeric_limits<std::uint16_t>::max()),"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXXXV");
}

TEST(RomanNumberTest,testZero)
{
    ASSERT_THROW(getRoman(0),std::runtime_error);
}