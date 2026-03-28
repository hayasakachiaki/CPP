/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:33:35 by mawako            #+#    #+#             */
/*   Updated: 2025/08/16 15:22:44 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int			_raw;
		static const int	_fractionalBits;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		Fixed&	operator=(const Fixed& other);
		int	operator>(const Fixed& other) const;
		int	operator<(const Fixed& other) const;
		int	operator>=(const Fixed& other) const;
		int	operator<=(const Fixed& other) const;
		int	operator==(const Fixed& other) const;
		int	operator!=(const Fixed& other) const;
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		float			toFloat(void) const;
		int			toInt(void) const;
		static Fixed&		max(Fixed& a, Fixed& b);
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& raw);

#endif
