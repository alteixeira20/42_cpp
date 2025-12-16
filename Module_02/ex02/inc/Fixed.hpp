#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

/*
 * Fixed-point number class.
 *
 * Represents a real number using an integer value and a fixed number
 * of fractional bits. Arithmetic and comparisons are performed using
 * this fixed-point representation.
 *
 * This class follows the Orthodox Canonical Form (OCF).
 */
class	Fixed
{
	public:
		/* Orthodox Canonical Form */
		Fixed();
		Fixed(const Fixed &other);
		Fixed&	operator=(const Fixed &other);
		~Fixed();

		/* Constructors */
		Fixed(const int n);
		Fixed(const float n);

		/* Comparison operators */
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		/*
		 * Arithmetic operators.
		 * Operations are performed using the fixed-point representation.
		 */
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		/* Increment / Decrement */
		Fixed&	operator++();		// pre-increment
		Fixed	operator++(int);	// post-increment
		Fixed&	operator--();		// pre-decrement
		Fixed	operator--(int);	// post-decrement

		/* Min / Max */
		static Fixed&		min(Fixed &a, Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static const Fixed&	max(const Fixed &a, const Fixed &b);

		/* Conversions */
		float	toFloat() const;
		int	toInt() const;

		/* Raw access */
		int	getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int			_value;
		static const int	_fractionalBits = 8;
};

/*
 * Stream insertion operator.
 * Outputs the fixed-point value as a floating-point number.
 */
std::ostream&	operator<<(std::ostream &out, const Fixed &obj);

#endif
