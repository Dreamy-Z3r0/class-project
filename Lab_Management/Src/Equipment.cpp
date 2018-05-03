#include"../Headers/Equipment.h"

Equipment::Equipment()
{
	label = "N/A";
	quantity = 1;
	price = 1000;
}

Equipment::Equipment(std::string label, int quantity, float price)
{
	this->label = label;
	this->quantity = quantity;
	this->price = price;
}

Equipment::~Equipment()

void Equipment::modifier(std::string label, int quantity_change = 0)
{
	this->label = label;
	quantity += quantity_change;
}

void Equipment::update()
{
}

void Equipment::search()
{
}

void Equipment::print_equip_info()
{
	std::cout << this->label << "\t\t" << this->model << "\t\t" << this->number << "\t\t" << this->price << std::endl;
}
