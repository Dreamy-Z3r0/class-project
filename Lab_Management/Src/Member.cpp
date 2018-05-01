#include"../Headers/Member.h"

Member::Member()
{

}

void Member::add_member(std::string name, std::string ID_number, std::string Class, std::string email, std::string phonenumber)
{
	this->name = name;
	this->ID_number = ID_number;
	this->Class = Class;
	this->email = email;
	this->phonenumber = phonenumber;
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
