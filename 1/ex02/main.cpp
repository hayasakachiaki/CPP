/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:26:38 by mawako            #+#    #+#             */
/*   Updated: 2025/10/02 10:52:35 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << std::setw(30) << "This is str address: " << &str << std::endl;
	std::cout << std::setw(30) << "This is stringPTR address: " << stringPTR << std::endl;
	std::cout << std::setw(30) << "This is stringREF address: " << &stringREF << std::endl;

	std::cout << std::setw(30) << "This is str value: " << str << std::endl;
	std::cout << std::setw(30) << "This is stringPTR value: " << *stringPTR << std::endl;
	std::cout << std::setw(30) << "This is stringREF value: " << stringREF << std::endl;
}
