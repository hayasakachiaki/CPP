#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "Cat Default constructor called!\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy constructor called!\n";
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called!\n";
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Mew~o\n";
}
