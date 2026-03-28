#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called!\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy constructor called!\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called!\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "BYOW\n";
}
