#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "Dog Default constructor called!\n";
	_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy constructor called!\n";
	_brain = new Brain(*other._brain);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called!\n";
	delete _brain;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

const Brain*	Dog::getBrain() const
{
	return (_brain);
}

void		Dog::makeSound() const
{
	std::cout << "Bow-Wow!\n";
}
