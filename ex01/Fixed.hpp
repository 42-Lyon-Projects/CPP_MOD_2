#ifndef FIXED_HPP
	#define FIXED_HPP

	#include <iostream>
	class Fixed
	{
		private:
			int fixedValue;
			const int fractionalBits;
		public:
			Fixed();
			Fixed(const Fixed &fixed);
			Fixed(const int value);
			Fixed(const float value);
			~Fixed();

			float toFloat() const;
			int toInt() const;

			int getRawBits() const;
			void setRawBits(int const raw);

			Fixed &operator=(const Fixed &fixed);
	};
std::ostream& operator << (std::ostream& os, const Fixed& other);
#endif
