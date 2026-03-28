#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	const Animal* animals[4];

	std::cout << "\n---- CREATE ----\n\n";

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Cat();
	animals[3] = new Dog();

	std::cout << "\n---- SOUNDS ----\n\n";

	for (int i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
	}

	std::cout << "\n---- DELETE ----\n\n";

	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "\n---- BRAINS ----\n\n";

	Dog	dog;
	Dog swampMan = dog;
	Animal* a = new Dog();

	std::cout << "ORIGIN: " << dog.getBrain() << std::endl;
	std::cout << "COPIED: " << swampMan.getBrain() << std::endl;
	std::cout << "Abstraction Test!: " << a->getType() << std::endl;

	std::cout << "\n---- DELETE ----\n\n";
	delete a;
}
