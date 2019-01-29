// Please implement unit test for fraction
//
#include "frac/Fraction.hxx"

#include <gtest/gtest.h>

#include <vector>
#include <tuple>

using namespace frac;


class test_Fraction : public testing::Test
{
public:
    void SetUp() override
    {
        for (auto val : valid_vals_)
        {
            valid_fracs_.emplace_back(Fraction(std::get<0>(val),std::get<1>(val)));
        }
    };

    void TearDown() override{};

protected:
    const std::vector<std::tuple<Fraction::ValueType,Fraction::ValueType,double>> valid_vals_
    {
        {1,2,0.5},
        {2,3,{2.0/3.0}},
        {0,1,0.0},
        {3,3,1.0}
    };

    std::vector<Fraction> valid_fracs_;

};

TEST_F(test_Fraction,Construction)
{
    Fraction f1;
    ASSERT_DOUBLE_EQ(f1.getFloating(),0);
    for (auto val : valid_vals_)
    {
        Fraction f(std::get<0>(val),std::get<1>(val));
        ASSERT_DOUBLE_EQ(f.getFloating(),std::get<2>(val));
    }
    Fraction invalidF(1,0); // Constructor allows denominator to be 0
    ASSERT_THROW(invalidF.getFloating(),std::runtime_error); // but throws a runtime error when calcualted
}

TEST_F(test_Fraction,Arithmetics)
{
    const Fraction StartVal(1,7);
    const auto testVal = StartVal.getFloating();

    for(const auto& frac : valid_fracs_)
    {
        Fraction testFrac1=StartVal;
        testFrac1 += frac;
        ASSERT_DOUBLE_EQ(testFrac1.getFloating(),testVal+frac.getFloating());

        Fraction testFrac2=StartVal;
        testFrac2 -= frac;
        ASSERT_DOUBLE_EQ(testFrac2.getFloating(),testVal-frac.getFloating());
    }
}