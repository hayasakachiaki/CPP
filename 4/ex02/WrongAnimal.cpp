#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal Default constructor called!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << "WrongAnimal Copy constructor called!\n";
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
	std::cout << this->_type << " is here!\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called!\n";
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

const std::string&	WrongAnimal::getType() const
{
	return (this->_type);
}

void		WrongAnimal::makeSound() const
{
	std::cout << "*WRONG SOUND*\n";
}
