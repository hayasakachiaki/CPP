#include "Character.hpp"

Character::FloorNode*	Character::_floor = 0;
int			Character::_characterCount = 0;

Character::Character() : _name("")
{
	_characterCount++;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const std::string& name) : _name(name)
{
	_characterCount++;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const Character& other) : _name(other._name)
{
	_characterCount++;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	_characterCount--;
	if (_characterCount == 0)
		clearFloor();
}

Character&		Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = 0;
		}
	}
	return (*this);
}

const std::string&	Character::getName() const
{
	return (_name);
}

void			Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			removeFromFloor(m);
			_inventory[i] = m;
			return;
		}
	}
	if (!isOnFloor(m))
		delete m;
}

void			Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;
	dropMateria(_inventory[idx]);
	_inventory[idx] = 0;
}

void			Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
}

void			Character::dropMateria(AMateria* materia)
{
	FloorNode*	curr;
	FloorNode*	newNode;

	if (!materia)
		return;
	curr = _floor;
	while (curr)
	{
		if (curr->materia == materia)
			return;
		curr = curr->next;
	}
	newNode = new FloorNode;
	newNode->materia = materia;
	newNode->next = _floor;
	_floor = newNode;
}

bool			Character::isOnFloor(AMateria* materia)
{
	FloorNode*	curr;

	curr = _floor;
	while (curr)
	{
		if (curr->materia == materia)
			return (true);
		curr = curr->next;
	}
	return (false);
}

void			Character::removeFromFloor(AMateria* materia)
{
	FloorNode*	curr;
	FloorNode*	prev;

	curr = _floor;
	prev = 0;
	while (curr)
	{
		if (curr->materia == materia)
		{
			if (prev)
				prev->next = curr->next;
			else
				_floor = curr->next;
			delete curr;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

void			Character::clearFloor()
{
	FloorNode*	next;

	while (_floor)
	{
		next = _floor->next;
		delete _floor->materia;
		delete _floor;
		_floor = next;
	}
}
