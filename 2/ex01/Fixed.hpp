/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:33:35 by mawako            #+#    #+#             */
/*   Updated: 2025/08/15 20:19:10 by mawako           ###   ########.fr       */
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
		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& raw);

#endif
