#include"../Headers/Member.h"

Member::Member()
{

}

void Member::add_member(std::string name, std::string age, std::string phonenumber, std::string ID_number)
{
	this->name = name;
	this->age = age;
	this->phonenumber = phonenumber;
	this->ID_number = ID_number;
}

void Member::delete_member()
{
}

void Member::Update()
{
}

void Member::print_member_info()
{
	std::cout << this->name << "\t\t\t" << this->age << "\t" << this->phonenumber << "\t\t\t" << this->ID_number << std::endl;
}