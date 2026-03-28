#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class	Cat : public Animal
{
	private:
		Brain*	_brain;
	public:
		Cat();
		Cat(const Cat& other);
		~Cat();
		Cat&	operator=(const Cat& other);

		const Brain*	getBrain() const;
		void		makeSound() const;
};

#endif
