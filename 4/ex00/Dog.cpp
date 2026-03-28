#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "Dog Default constructor called!\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy constructor called!\n";
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called!\n";
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Bow-Wow!\n";
}
