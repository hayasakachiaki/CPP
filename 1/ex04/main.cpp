/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:41:47 by mawako            #+#    #+#             */
/*   Updated: 2025/08/14 15:38:22 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	std::string	outFileName;
	std::string	s1;
	std::string	s2;
	std::string	line;
	size_t		pos;

	if (ac != 4)
	{
		std::cerr << "Usage: " << "./replace" << " <filename> <s1> <s2>\n";
		return (1);
	}
	std::ifstream inFile(av[1]);
	if (!inFile)
	{
		std::cerr << "Error: cannot open file " << av[1] << "\n";
		return (1);
	}
	outFileName = std::string(av[1]) + ".replace";
	std::ofstream outFile(outFileName.c_str());
	if (!outFile)
	{
		std::cerr << "Error: cannot create file " << outFileName << "\n";
		return (1);
	}
	s1 = av[2];
	s2 = av[3];
	while (std::getline(inFile, line))
	{
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.size());
			line.insert(pos, s2);
			pos += s2.size();
		}
		outFile << line;
		if (!inFile.eof())
			outFile << "\n";
	}
	return (0);
}
