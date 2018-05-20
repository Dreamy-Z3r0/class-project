#include"../Headers/Equipment.h"

Equipment::Equipment(std::string name, int quantity)
{
	this->name = name;
	this->quantity = quantity;
	availability = quantity;
}

Equipment::~Equipment() {}

void Equipment::set_name(std::string name)
{
	this->name = name;
}

void Equipment::quantity_change(int num)
{
	if (-num > quantity)
	{
		std::cout << "Current quantity exceeded: " << quantity << std::endl;
	}
	else 
	{
		quantity += num;
		availability += num;
	}
}

void Equipment::availability_change(int num)
{
	if (-num > availability)
	{
		std::cout << "Available to borrow: " << availability << " items.\n";
	}
	else 
	{
		availability += num;
	}
}


void Equipment::print_info()
{
	std::cout << "Equipment name: " << name;
	std::cout << "\nIn-lab quantity: " << quantity;
	std::cout << "\nAvailable to borrow: " << availability << std::endl;
}
