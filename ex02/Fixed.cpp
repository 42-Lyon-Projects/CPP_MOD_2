#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedValue(0), fractionalBits(8) {}

Fixed::Fixed(const Fixed &fixed) : fractionalBits(8)
{
	*this = fixed;
}

Fixed::Fixed(const int value) : fractionalBits(8)
{
	this->fixedValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value) : fractionalBits(8)
{
	this->fixedValue = (int)(roundf(value * (1 << this->fractionalBits)));
}

Fixed::~Fixed() {}

float Fixed::toFloat() const
{
	return ((float)this->fixedValue / (1 << this->fractionalBits));
}

int Fixed::toInt() const
{
	return (this->fixedValue >> this->fractionalBits);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a > b ? b : a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a > b ? b : a);
}


Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}


Fixed &Fixed::operator = (const Fixed &fixed)
{
	if (this == &fixed)
		return (*this);
	this->fixedValue = fixed.fixedValue;
	this->fractionalBits = fixed.fractionalBits;
	return (*this);
}

bool Fixed::operator > (const Fixed& other) const
{
	return (this->toInt() > other.toInt());
}

bool Fixed::operator < (const Fixed& other) const
{
	return (this->toInt() < other.toInt());
}

bool Fixed::operator >= (const Fixed& other) const
{
	return (this->toInt() >= other.toInt());
}

bool Fixed::operator <= (const Fixed& other) const
{
	return (this->toInt() <= other.toInt());
}

bool Fixed::operator == (const Fixed& other) const
{
	return (this->toInt() == other.toInt());
}

bool Fixed::operator != (const Fixed& other) const
{
	return (this->toInt() != other.toInt());
}

Fixed& Fixed::operator + (const Fixed& other)
{
	this->fixedValue += other.fixedValue;
	return (*this);
}

Fixed& Fixed::operator - (const Fixed& other)
{
	this->fixedValue -= other.fixedValue;
	return (*this);
}

Fixed& Fixed::operator * (const Fixed& other)
{
	this->fixedValue *= other.fixedValue;
	return (*this);
}

Fixed& Fixed::operator / (const Fixed& other)
{
	if (other.fixedValue <= 0)
		return (*this);
	this->fixedValue /= other.fixedValue;
	return *this;
}

Fixed& Fixed::operator ++ ()
{
	this->fixedValue++;
	return (*this);
}

const Fixed Fixed::operator ++ (int)
{
	const Fixed *tmp = new Fixed(*this);
	this->fixedValue++;
	return (*tmp);
}

Fixed& Fixed::operator -- ()
{
	this->fixedValue--;
	return (*this);
}

const Fixed Fixed::operator -- (int)
{
	const Fixed *tmp = new Fixed(*this);
	this->fixedValue--;
	return (*tmp);
}



std::ostream& operator << (std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}