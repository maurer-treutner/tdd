/**
 * @file romannumber.cxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Implementation of functions for handling of roman numbers
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier:	BSL-1.0
 */

#include "SimpleDemo/romannumber.hxx"

#include <iostream>

#include <cassert>
#include <stdexcept>


namespace SimpleDemo
{
using std::string;

/**
 * @brief local helper function for calculation of a roman number
 * 
 * @param number 
 * @param base 
 * @param rmOne 
 * @param rmFive 
 * @param rmTen 
 * @return string 
 */
static string makeRoman(uint16_t number,uint16_t base,string rmOne,string rmFive,string rmTen);

string getRoman(uint16_t number)
{
    if (number == 0)
    {
        throw std::runtime_error("Romans did not yet invent 0");
    }
    string result{""};
    auto thousands = number / 1000;
    number %= 1000;
    for (int i=0;i<thousands;i++)
    {
        result.append("M");
    }
    result.append(makeRoman(number,100,"C","D","M"));
    number %= 100;
    result.append(makeRoman(number,10,"X","L","C"));
    number %= 10;
    result.append(makeRoman(number,1,"I","V","X"));
    return result;
}

static string makeRoman(uint16_t number,uint16_t base,string rmOne,string rmFive,string rmTen)
{
    if (number > 10 * base)
    {
        throw std::runtime_error("makeRoman: number to big for base");
    }
    string result {""};
    auto baseUnits = number / base;
    if (baseUnits<4)
    {
        for (int i=0;i<baseUnits;i++)
        {
            result.append(rmOne);
        }
    }
    else if (baseUnits==4)
    {
        result.append(rmOne);
        result.append(rmFive);
    }
    else if (baseUnits >= 5 && baseUnits < 9)
    {
        result.append(rmFive);
        baseUnits = (number % (5*base))/base;
        for (int i=0;i<baseUnits;i++)
        {
            result.append(rmOne);
        }
    }
    else if (baseUnits==9)
    {
        result.append(rmOne);
        result.append(rmTen);
    }
    return result;

}

}
