#include"../Headers/Equipment.h"

Equipment::Equipment()
{
}

void Equipment::add_equipment(std::string label, std::string model, int quantity, float price)
{
	this->label = label;
	this->model = model;
	this->quantity = quantity;
	this->price = price;
}

void Equipment::delete_equipment()
{

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
