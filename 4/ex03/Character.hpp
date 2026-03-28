#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class	Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];

	public:
		Character();
		Character(const std::string& name);
		Character(const Character& other);
		virtual ~Character();

		Character&			operator=(const Character& other);
		virtual const std::string&	getName() const;
		virtual void			equip(AMateria* m);
		virtual void			unequip(int idx);
		virtual void			use(int idx, ICharacter& target);
};

#endif
