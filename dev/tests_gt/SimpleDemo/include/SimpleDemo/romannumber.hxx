/**
 * @file romannumber.hxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Definition of functions for handling of roman numbers
 * @version 0.1
 * @date 2019-01-10
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier:	BSL-1.0
 */

#ifndef __SIMPLEDEMO_ROMANNUMBERS_HXX__
#define __SIMPLEDEMO_ROMANNUMBERS_HXX__

#include <string>

namespace SimpleDemo
{
    
using std::uint16_t;
using std::string;

string getRoman(uint16_t number);
}

#endif