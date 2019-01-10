#include "SimpleDemo/romannumber.hxx"
#include "gtest/gtest.h"

using namespace SimpleDemo;

TEST(RomanNumberTest,testSimpleNumbers)
{
    ASSERT_EQ(getRoman(1),"I");
}