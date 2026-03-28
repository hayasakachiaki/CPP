/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:29:31 by mawako            #+#    #+#             */
/*   Updated: 2025/08/17 14:43:19 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phone;
		std::string	_secret;
	public:
		Contact();
		bool			setFirstName(const std::string& fn);
		bool			setLastName(const std::string& ln);
		bool			setNickName(const std::string& nn);
		bool			setPhone(const std::string& ph);
		bool			setSecret(const std::string& sec);
		const std::string&	getFirstName() const;
		const std::string&	getLastName() const;
		const std::string&	getNickName() const;
		const std::string&	getPhone() const;
		const std::string&	getSecret() const;
};

#endif
