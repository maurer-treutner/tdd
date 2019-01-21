/**
 * @file roman.hxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief C++ class for operations with roman numbers. This class is for demonstration purpose 
 *   and has no practical value 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include <cstdint>
#include <string>

namespace roman
{
class RomanNumber
{
public:
    RomanNumber(std::uint16_t number);

    /**
     * @brief Is instance representing a valid roman number
     * 
     * @return true, if value_ != 0
     * @return false, if value == 0
     */
    bool isValid() const {return value_ != 0;};

    /**
     * @brief Get the integer value stored in instance
     * 
     * @return uint16_t 
     */
    uint16_t getValue() const {return value_;};

    std::string toString() const;

    /**
     * @brief Comparison: two numbers are equal, if their values are equal
     * 
     * @return RomanNumber 
     */
    bool operator == (const RomanNumber rm) const;

    /**
     * @brief -= operator acts as minus for natural numbers.
     * 
     * @param lhs 
     * @return RomanNumber& 
     * @throws std::range_error if result would become negative
     */
    RomanNumber& operator -= (RomanNumber lhs);

    /**
     * @brief - operator acts as minus for natural numbers.
     * 
     * @param lhs 
     * @return RomanNumber 
     * @throws std::range_error if result would become negative
     */
    RomanNumber operator - (RomanNumber lhs) const;


private:
    std::string calcRomanThousands(std::string digit1000 = "m") const;
    std::string calcRomanPart(std::uint16_t number, std::uint16_t base,std::string baseDigit,std::string base5Digit,std::string base10Digit) const;

    std::uint16_t value_ {0};
    mutable std::string svalue_ {""};
};
}

