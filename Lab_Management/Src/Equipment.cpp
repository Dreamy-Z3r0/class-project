#include"../Headers/Equipment.h"

Equipment::Equipment(char* name, char* ID_number, int quantity)
{
	strcpy_s(this->name, 50, name);
	strcpy_s(this->ID_number, 10, ID_number);
	this->quantity = quantity;
	availability = quantity;
}

Equipment::~Equipment() {}

char* Equipment::get_name()
{
	return this->name;
}

char* Equipment::get_IDnumber()
{
	return this->ID_number;
}

void Equipment::set_name(char* name)
{
	strcpy_s(this->name, 40, name);
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

int Equipment::get_availability() { return this->quantity; }

void Equipment::print_info() const
{
	std::cout << "Equipment name: " << name;
	std::cout << "\nEquipment ID number" << ID_number;
	std::cout << "\nIn-lab quantity: " << quantity;
	std::cout << "\nAvailable to borrow: " << availability << std::endl;
	std::cout << " " << std::endl;

}
