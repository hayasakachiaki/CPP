/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:32:04 by mawako            #+#    #+#             */
/*   Updated: 2025/08/20 16:25:21 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : _size(0), _next(0)
{
}

void		PhoneBook::addPb(const Contact& c)
{
	_data[_next] = c;
	_next = (_next + 1) % 8;
	if (_size < 8)
		_size++;
}

int		PhoneBook::getSize() const
{
	return (_size);
}

const Contact*	PhoneBook::getData(int idx) const
{
	if (idx < 0 || idx >= _size)
		return (0);
	return
		(&_data[idx]);
}

std::string	PhoneBook::adjust(const std::string& s)
{
	if (s.size() <= 10)
	{
		std::ostringstream oss;
		oss << std::setw(10) << s;
		return (oss.str());
	}
	std::string t;

	t = s.substr(0, 9);
	t += ".";
	return (t);
}

void		PhoneBook::printTable() const
{
	std::cout << std::setw(10) << "INDEX" << "|"
		<< std::setw(10) << "FIRST" << "|"
		<< std::setw(10) << "LAST" << "|"
		<< std::setw(10) << "NICK" << std::endl;
	for (int i = 0; i < _size; ++i)
	{
		const Contact& c = _data[i];

		std::cout << std::setw(10) << i << "|"
			<< adjust(c.getFirstName()) << "|"
			<< adjust(c.getLastName()) << "|"
			<< adjust(c.getNickName()) << std::endl;
	}
}
