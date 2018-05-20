#include"../Headers/Lib.h"

Student::Student(std::string Name, std::string email, std::string phonenumber, std::string ID_Number)
{
	this->name = name;
	this->email = email;
	this->ID_Number = ID_Number;
	this->phonenumber = phonenumber;
}


void Student::set_name(std::string name)					{ this->name = name; }

void Student::set_email(std::string email)					{ this->email = email; }

void Student::set_phonenumber(std::string phonenumber)		{ this->phonenumber = phonenumber; }

void  Student::set_IDnumber(std::string ID_Number)			{ this->ID_Number = ID_Number; }

std::string Student::get_name()								{ return this->name; }

std::string Student::get_email()							{ return this->email; }
std::string Student::get_phonenumber()				    	{ return this->phonenumber; }
std::string Student::get_IDnumber()							{ return this->ID_Number; }

 void Student::print_info() const
{
	std::cout << this->name << "\t\t\t" << this->email << "\t\t\t" << this->phonenumber << "\t\t\t" << this->ID_Number << std::endl;
}
