#ifndef FIXED_HPP
	#define FIXED_HPP

	#include <iostream>
	class Fixed
	{
		private:
			int fixedValue;
			int fractionalBits;
		public:
			Fixed();
			Fixed(const Fixed &fixed);
			Fixed(const int value);
			Fixed(const float value);
			~Fixed();

			float toFloat() const;
			int toInt() const;

			static Fixed &min(Fixed &a, Fixed &b);
			static const Fixed &min(const Fixed &a, const Fixed &b);

			static Fixed &max(Fixed &a, Fixed &b);
			static const Fixed &max(const Fixed &a, const Fixed &b);


			Fixed &operator=(const Fixed &fixed);
			bool operator >  (const Fixed& other) const;
			bool operator <  (const Fixed& other) const;
			bool operator >= (const Fixed& other) const;
			bool operator <= (const Fixed& other) const;
			bool operator == (const Fixed& other) const;
			bool operator != (const Fixed& other) const;

			Fixed& operator + (const Fixed& other);
			Fixed& operator - (const Fixed& other);
			Fixed& operator * (const Fixed& other);
			Fixed& operator / (const Fixed& other);

			Fixed& operator ++ ();
			const Fixed operator ++ (int);
			Fixed& operator -- ();
			const Fixed  operator -- (int);
	};
	std::ostream	&operator <<(std::ostream &os, const Fixed &other);

#endif
