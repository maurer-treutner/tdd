//
// Please implement class fraction here
//

#include "frac/Fraction.hxx"

#include <stdexcept>

namespace frac
{
    double Fraction::getFloating() const
    {
        if (den_ == 0)
        {
            throw std::runtime_error("Denominator == 0");
        }
        return static_cast<double>(num_) / static_cast<double> (den_);
    }

    Fraction& Fraction::operator += (const Fraction& rhs)
    {
        if (rhs.den_ == den_)
        {
            num_ += rhs.num_;
        }
        else
        {
            num_ = num_*rhs.den_ + rhs.num_*den_;
            den_ *= rhs.den_;    
        }
        return *this;        
    }

    Fraction& Fraction::operator -= (const Fraction& rhs)
    {
       if (rhs.den_ == den_)
        {
            num_ -= rhs.num_;
        }
        else
        {
            num_ = num_*rhs.den_ - rhs.num_*den_;
            den_ *= rhs.den_;    
        }
        return *this;        

    }
}