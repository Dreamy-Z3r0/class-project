#include"../Headers/Lib.h"

Students::Students(std::string Name, std::string email, std::string ID_Number, std::string phonenumber)
{
	this->name = Name;
	this->email = email;
	this->ID_Number = ID_Number;
	this->phonenumber = phonenumber;
}

 void Students::print_info() const
{
	std::cout << this->name << "\t\t\t" << this->email << "\t\t\t" << this->ID_Number << "\t\t\t" << this->phonenumber << std::endl;
}

void Students::delete_member()
{

}

void Students::borrow()
{

}

void Students::update()
{

}