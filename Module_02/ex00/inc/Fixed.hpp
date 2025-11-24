#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	public:
		Fixed();				// 1. Default Constructor
		Fixed(const Fixed &other);		// 2. Copy Constructor
		Fixed& operator=(const Fixed &other);	// 3. Assignment Operator
		~Fixed();				// 4. Destructor
	
		int	getRawBits() const;
		void	setRawBits(int const raw);
	private:
		int			_value;
		static const int	_fractionalBits = 8;
};

#endif
