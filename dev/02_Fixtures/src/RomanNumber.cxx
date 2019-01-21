/**
 * @file RomanNumber.cxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief 
 * @version 0.1
 * @date 2019-01-16
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include "roman/RomanNumber.hxx"

#include <cassert>
#include <cstdint>
#include <stdexcept>

namespace roman{

using std::uint16_t;
using std::string;

RomanNumber::RomanNumber(uint16_t value):
    value_(value)
{}

string RomanNumber::toString() const
{
    if (isValid() && svalue_.empty())
    {
        svalue_.append(calcRomanThousands());
        auto val = value_ % 1000;
        svalue_.append(calcRomanPart(val,100,"c","d","m"));
        val %= 100;
        svalue_.append(calcRomanPart(val,10,"x","l","c"));
        val %= 10;
        svalue_.append(calcRomanPart(val,1,"i","v","x"));
    }
    return svalue_;
}

bool RomanNumber::operator == (const RomanNumber rm) const
{
    return value_ == rm.value_;
}

RomanNumber& RomanNumber::operator -= (RomanNumber lhs)
{
    if (lhs.value_ <= value_)
    {
        value_ -= lhs.value_;
        svalue_ = "";
    }
    else
    {
        throw std::range_error("no negative roman numbers");
    }
    return *this;
}


RomanNumber RomanNumber::operator - (RomanNumber lhs) const
{
    RomanNumber result {*this};
    result -= lhs;
    return result;
}



string RomanNumber::calcRomanThousands(std::string digit1000) const
{
    string result {""};
    auto digits = value_ / 1000;
    for (decltype(digits) i=0;i<digits;i++)
    {
        result.append(digit1000);
    }
    return result;
}

string RomanNumber::calcRomanPart(std::uint16_t number, std::uint16_t base,std::string baseDigit,std::string base5Digit,std::string base10Digit) const
{
    string result {""};
    if (number >= base && number < 10 * base)
    {
        auto baseUnits = number / base;
        if (baseUnits<4)
        {
            for (int i=0;i<baseUnits;i++)
            {
                result.append(baseDigit);
            }
        }
        else if (baseUnits==4)
        {
            result.append(baseDigit);
            result.append(base5Digit);
        }
        else if (baseUnits >= 5 && baseUnits < 9)
        {
            result.append(base5Digit);
            baseUnits = (number % (5*base))/base;
            for (int i=0;i<baseUnits;i++)
            {
                result.append(baseDigit);
            }
        }
        else if (baseUnits==9)
        {
            result.append(baseDigit);
            result.append(base10Digit);
        }
    }
    return result;
}


} // namespace roman