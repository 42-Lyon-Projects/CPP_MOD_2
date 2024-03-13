#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedValue(0), fractionalBits(8)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : fractionalBits(8)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int value) : fractionalBits(8)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value) : fractionalBits(8)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedValue = (int)(roundf(value * (1 << this->fractionalBits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const
{
	return ((float)this->fixedValue / (1 << this->fractionalBits));
}

int Fixed::toInt() const
{
	return (this->fixedValue >> this->fractionalBits);
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this == &fixed)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedValue = fixed.fixedValue;
	return (*this);
}

std::ostream& operator << (std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}