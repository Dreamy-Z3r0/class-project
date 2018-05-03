#include"../Headers/Lib.h"
#include"../Headers/Lecturers.h"

void Lectures::Add_a_Member(std::string Name, std::string Email, unsigned long ID_Number, unsigned long phonenumber) 
{
	this->name = Name;
	this->email = Email;
	this->ID_Number = ID_Number;
	this->phonenumber = phonenumber;
}

void Lectures::print_info()
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