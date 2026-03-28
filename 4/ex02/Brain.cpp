#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called!\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain Copy constructor called!\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called!\n";
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}
