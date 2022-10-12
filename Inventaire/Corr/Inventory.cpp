#include "Inventory.h"
#include "Item.h"
#include <iostream>

#pragma region constructor
Inventory::Inventory(const std::string& _name)
{
	name = _name; 
}

Inventory::Inventory(const Inventory& _copy)
{
	name = _copy.name;
	items = _copy.items;

}
Inventory::~Inventory()
{
	items.clear(); 
}
size_t Inventory::FindItem(const Item* _item)
{
	const size_t _size = items.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (_item->Equals(items[i]))
			return i; 
	}
	return -1;
}
void Inventory::AddItem(Item* _item)
{
	const size_t _index = FindItem(_item); 
	if (_index == -1)
		items.push_back(_item);
	else
		items[_index]->AddStack(1); 
}
void Inventory::RemoveItem(Item* _item)
{
	const size_t _index = FindItem(_item);
	if (_index == -1)return; 
	items.erase(items.begin() + _index); 
}
void Inventory::Clear()
{
	items.clear(); 
}
int Inventory::Count() const
{
	return (int)items.size(); 
}
void Inventory::DisplayInventory()
{
	std::cout << "_____________________" << name << "_____________________" << std::endl; 
	const size_t _size = items.size(); 
	for (size_t i = 0; i < _size; i++)
	{
		std::cout << i + 1 << ": " << items[i]->ToString() << std::endl; 
	}
	std::cout << "_____________________" << std::string(name.size(), '_') << "_____________________" << std::endl;
}
std::vector<Item*> Inventory::Items() const
{
	return std::vector<Item*>();
}
#pragma endregion constructor