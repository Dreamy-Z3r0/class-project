#include"../Headers/Lib.h"

Student::Student(char* Name, char* email, char* phonenumber, char* ID_Number)
{
	strcpy_s(this->name, 50, Name);
	strcpy_s(this->email, 50, email);
	strcpy_s(this->ID_Number, 10, ID_Number);
	strcpy_s(this->phonenumber, 10, phonenumber);

}


void Student::set_name(char* name) { strcpy_s(this->name, 50, name); }

void Student::set_email(char* email) { strcpy_s(this->email, 50, email); }

void Student::set_phonenumber(char* phonenumber) {
	strcpy_s(this->ID_Number, 10, ID_Number);
}

void  Student::set_IDnumber(char* ID_Number) {
	strcpy_s(this->phonenumber, 10, phonenumber);
}
char* Student::get_name() { return this->name; }
char* Student::get_email() { return this->email; }
char* Student::get_phonenumber() { return this->phonenumber; }
char* Student::get_IDnumber() { return this->ID_Number; }


void Student::print_info() const
{
	std::cout << this->name << "\t\t\t" << this->email << "\t\t\t" << this->phonenumber << "\t\t\t" << this->ID_Number << std::endl;
}
