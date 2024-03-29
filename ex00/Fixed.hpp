#ifndef FIXED_HPP
	#define FIXED_HPP

	class Fixed
	{
		private:
			int fixedValue;
			static const int fractionalBits = 8;
		public:
			Fixed();
			Fixed(const Fixed &fixed);
			~Fixed();
			Fixed &operator=(const Fixed &fixed);
			int getRawBits() const;
	};

#endif
