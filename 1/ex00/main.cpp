/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:33:50 by mawako            #+#    #+#             */
/*   Updated: 2025/11/19 03:47:20 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	Zombie*	z1;

	z1 = newZombie("HEAP ZOMBIE");
	z1->announce();
	delete z1;

	randomChump("STACK ZOMBIE");
}
