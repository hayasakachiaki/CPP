#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "Cat Default constructor called!\n";
	_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy constructor called!\n";
	_brain = new Brain(*other._brain);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called!\n";
	delete _brain;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

const Brain*	Cat::getBrain() const
{
	return (_brain);
}

void		Cat::makeSound() const
{
	std::cout << "Mew~o\n";
}
