/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:45:00 by mawako            #+#    #+#             */
/*   Updated: 2025/08/20 16:26:41 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"

static std::string	ask(const char* prompt)
{
	std::string	s;
	
	std::cout << prompt;
	std::getline(std::cin, s);
	return (s);
}

int	main()
{
	PhoneBook	pb;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
			break ;
		if (cmd == "ADD")
		{
			Contact	c;
			bool	check;

			std::string fn = ask("First name: ");
			std::string ln = ask("Last name: ");
			std::string nn = ask("Nickname: ");
			std::string ph = ask("Phone: ");
			std::string sc = ask("Darkest secret: ");
			check = true;
			if (!c.setFirstName(fn))
			{
				std::cout << "Input first name." << std::endl;
				check = false;
			}
			if (!c.setLastName(ln))
			{
				std::cout << "Input Last name." << std::endl;
				check = false;
			}
			if (!c.setNickName(nn))
			{
				std::cout << "Input Nick name." << std::endl;
				check = false;
			}
			if (!c.setPhone(ph))
			{
				std::cout << "Input Phone number." << std::endl;
				check = false;
			}
			if (!c.setSecret(sc))
			{
				std::cout << "Input Darkest secret." << std::endl;
				check = false;
			}
			if (!check)
				continue ;
			pb.addPb(c);
			std::cout << "Saved.\n";
		}
		else if (cmd == "SEARCH")
		{
			int		idx;
			const Contact	*pc;
			std::string	s;

			if (pb.getSize() == 0)
			{
				std::cout << "Empty.\n";
				continue ;
			}
			pb.printTable();
			std::cout << "Index? ";
			std::getline(std::cin, s);
			std::stringstream ss(s);
			idx = -1;
			if (!(ss >> idx) || !ss.eof())
			{
				std::cout << "Invalid index.\n";
				continue ;
			}
			pc = pb.getData(idx);
			if (!pc)
			{
				std::cout << "Out of range.\n";
				continue ;
			}
			std::cout << "FIrst:  " << pc->getFirstName() << "\n"
				  << "Last:   " << pc->getLastName() << "\n"
				  << "Nick:   " << pc->getNickName() << "\n"
				  << "Phone:  " << pc->getPhone() << "\n"
				  << "Secret: " << pc->getSecret() << "\n";
		}
		else if (cmd == "EXIT")
			break ;
		else if (cmd.empty())
			continue ;
		else
			std::cout << "Unknown command.\n";
	}
	return (0);
}
