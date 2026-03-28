/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:28:57 by mawako            #+#    #+#             */
/*   Updated: 2025/08/17 14:41:35 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

static std::string	trim(const std::string& s)
{
	size_t	start;
	size_t	end;

	start = s.find_first_not_of(" \t\n\r\f\v");
	end = s.find_last_not_of(" \t\n\r\f\v");
	if (start == std::string::npos)
		return ("");
	return (s.substr(start, end - start + 1));
}

bool			Contact::setFirstName(const std::string& fn)
{
	std::string	str;

	str = trim(fn);
	if (str.empty())
		return (false);
	_firstName = str;
	return (true);
}

bool			Contact::setLastName(const std::string& ln)
{
	std::string	str;

	str = trim(ln);
	if (str.empty())
		return (false);
	_lastName = str;
	return (true);
}

bool			Contact::setNickName(const std::string& nn)
{
	std::string	str;

	str = trim(nn);
	if (str.empty())
		return (false);
	_nickName = str;
	return (true);
}

bool			Contact::setPhone(const std::string& ph)
{
	std::string	str;

	str = trim(ph);
	if (str.empty())
		return (false);
	_phone = str;
	return (true);
}

bool			Contact::setSecret(const std::string& sec)
{
	std::string	str;

	str = trim(sec);
	if (str.empty())
		return (false);
	_secret = str;
	return (true);
}

const std::string&	Contact::getFirstName() const
{
	return (_firstName);
}

const std::string&	Contact::getLastName() const
{
	return (_lastName);
}

const std::string&	Contact::getNickName() const
{
	return (_nickName);
}

const std::string&	Contact::getPhone() const
{
	return (_phone);
}

const std::string&	Contact::getSecret() const
{
	return (_secret);
}
