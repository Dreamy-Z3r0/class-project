#include"../Headers/Lib.h"

Student::Student(char* Name, char* email, char* phonenumber, char* ID_Number)
{
	strcpy_s(this->name, 50, Name);
	strcpy_s(this->email, 50, email);
	strcpy_s(this->ID_Number, 10, ID_Number);
	strcpy_s(this->phonenumber, 10, phonenumber);
}


void Student::set_name(char* name) 
{
	strcpy_s(this->name, 50, name); 
}

void Student::set_email(char* email) 
{ 
	strcpy_s(this->email, 50, email); 
}

void Student::set_phonenumber(char* phonenumber) {
	strcpy_s(this->ID_Number, 10, ID_Number);
}

void  Student::set_IDnumber(char* ID_Number) {
	strcpy_s(this->phonenumber, 10, phonenumber);
}
void Student::set_borrow_list(char* equip_name, int vacancy, int quantity, char* date)
{
	strcpy_s(this->list[vacancy].name, 50, equip_name);
	this->list[vacancy].vacancy = false;
	this->list[vacancy].quantity = quantity;
	strcpy_s(this->list[vacancy].date, 5, date);

}
int  Student::occupied_vacancies()
{	
	int occuppied = 0;
	int un_occupied = 0;
	// Check occupied and unoccupied vacancy
	for (int i = 0; i < 3; i++)
	{
		if (this->list[i].vacancy == true)
			un_occupied++;
		else occuppied += 1 * list[i].quantity ;
		
	}
	std::cout << un_occupied << " Vacancies left" << std::endl;
	std::cout << occuppied << " borrowed" << std::endl;
	return occuppied;

}

int Student::return_vacancy_index()
{

	for (int i = 0; i < 3; i++)
	{
		if (this->list[i].vacancy == true)
		{
			std::cout << "first index: " << i << std::endl;
			return i;
		}
	}


	return -1;
}
char* Student::get_name() { return this->name; }
char* Student::get_email() { return this->email; }
char* Student::get_phonenumber() { return this->phonenumber; }
char* Student::get_IDnumber() { return this->ID_Number; }


void Student::print_info() 
{
	//std::cout << this->name << "\t\t\t" << this->email << "\t\t\t" << this->phonenumber << "\t\t\t" << this->ID_Number << std::endl;
	std::cout << this->name << "\t\t" << this->email << "\t\t" << this->phonenumber << "\t\t" << this->ID_Number << std::endl;
	
	int vacancy_index = this->return_vacancy_index();
	if (vacancy_index == -1)
	{
		std::cout << "list full" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			if (!this->list[i].vacancy)
			std::cout << "Equipment borrowed: " << this->list[i].name << "\t" << "Quantity: " << this->list[i].quantity << std::endl;
		}
	}
	else {
		for (int i = 0; i < vacancy_index; i++)
		{
			std::cout << "Equipment borrowed: " << this->list[i].name <<"\t" << "Quantity: " << this->list[i].quantity
				<< "\t" << "Date: "<< this->list[i].date  << std::endl;
		}
	}
}
