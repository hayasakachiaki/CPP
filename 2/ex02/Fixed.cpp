/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:33:30 by mawako            #+#    #+#             */
/*   Updated: 2025/08/16 15:59:35 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed()
	: _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
	: _raw(other._raw)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_raw = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_raw = (int)(roundf(value * (1 << _fractionalBits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_raw = other._raw;
	return (*this);
}

int	Fixed::operator>(const Fixed& other) const
{
	if (this->_raw > other._raw)
		return (1);
	return (0);
}

int	Fixed::operator<(const Fixed& other) const
{
	if (this->_raw < other._raw)
		return (1);
	return (0);
}

int	Fixed::operator>=(const Fixed& other) const
{
	if (this->_raw >= other._raw)
		return (1);
	return (0);
}

int	Fixed::operator<=(const Fixed& other) const
{
	if (this->_raw <= other._raw)
		return (1);
	return (0);
}

int	Fixed::operator==(const Fixed& other) const
{
	if (this->_raw == other._raw)
		return (1);
	return (0);
}

int	Fixed::operator!=(const Fixed& other) const
{
	if (this->_raw != other._raw)
		return (1);
	return (0);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	res;

	res._raw = this->_raw + other._raw;
	return (res);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	res;

	res._raw = this->_raw - other._raw;
	return (res);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	res;
	long	res_raw;

	res_raw = (long)this->_raw * other._raw;
	res._raw = (int)(res_raw >> _fractionalBits);
	return (res);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	res;
	long	res_raw;

	res_raw = (long)((this->_raw << _fractionalBits) / other._raw);
	res._raw = (int)(res_raw);
	return (res);
}

Fixed&	Fixed::operator++()
{
	this->_raw += 1;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->_raw -= 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->_raw += 1;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->_raw -= 1;
	return (temp);
}

float		Fixed::toFloat(void) const
{
	return ((float)_raw / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (_raw >> _fractionalBits);
}

Fixed&		Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed&		Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& raw)
{
	os << raw.toFloat();
	return (os);
}
