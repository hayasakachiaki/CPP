#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor called!\n";
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Animal Copy constructor called!\n";
}

Animal::Animal(const std::string& type) : _type(type)
{
	std::cout << _type << " Here!\n";
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called!\n";
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

const std::string&	Animal::getType() const
{
	return (this->_type);
}

void			Animal::makeSound() const
{
	std::cout << "*Censored*\n";
}
