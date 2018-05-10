#include"../Headers/Lib.h"
#include"../Headers/Lecturers.h"

Lectures::Lectures(std::string Name, std::string Email, std::string ID_Number, std::string phonenumber)
{
	this->name = Name;
	this->email = Email;
	this->ID_Number = ID_Number;
	this->phonenumber = phonenumber;
}

void Lectures::print_info() const
{
	std::cout << this->name << "\t\t" << this->email << "\t\t" << this->ID_Number << "\t\t" << this->phonenumber << std::endl;
}

void Lectures::delete_member()
{

}

void Lectures::borrow()
{
	
}

void Lectures::update()
{

}