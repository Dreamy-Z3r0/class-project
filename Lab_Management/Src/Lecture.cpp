#include"../Headers/Lib.h"


Lecturer::Lecturer(char* Name, char* Email, char* phonenumber, char* ID_Number)
{
	strcpy_s(this->name, 50, Name);
	strcpy_s(this->email, 50, Email);
	strcpy_s(this->phonenumber, 20, phonenumber);
	strcpy_s(this->ID_Number, 10, ID_Number);
}

int  Lecturer::return_occupied_vacancies(const char* mode)
{
	int occuppied = 0;
	// Check occupied and unoccupied vacancy
	if (strcmp(mode, "BORROW") == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			if (this->borrowed_list[i].vacancy == false)
				occuppied += 1 * borrowed_list[i].quantity;
		}
		std::cout << 3 - occuppied << " Vacancy(ies) left" << std::endl;
		std::cout << occuppied << " Equipment(s) borrowed" << std::endl;
	}
	else if (strcmp(mode, "HOST") == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (this->project_list[i].vacancy == false)
				occuppied++;
		}
		std::cout << 2 - occuppied << " Project Hostes Vacancy(ies) left" << std::endl;
		std::cout << occuppied << "Project(s) Hosted" << std::endl;
	}
	return occuppied;
}

/**
*Check and return vacancy in the borrow list. Return -1 if the list is full.
*@param none
*@return int
*/

int Lecturer::return_vacancy_index(const char* mode)
{
	if (strcmp(mode, "BORROW") == 0) {

		for (int i = 0; i < 3; i++)
		{	
			if (this->borrowed_list[i].vacancy == true)
			{
				std::cout << "first index Equipment " << i << std::endl;
				return i;
			}
		}
	}
	else if (strcmp(mode, "HOST") == 0) {
		for (int i = 0; i < 5; i++)
		{
			if (this->project_list[i].vacancy == true)
			{
				std::cout << "first index create a new project " << i << std::endl;
				return i;
			}
		}
	}
return -1;
}


void Lecturer::project_done(int index)
{
	strcpy_s(this->project_list[index].name, 50, "none");
	strcpy_s(this->project_list[index].ID_number, 10, "none");
	this->project_list[index].vacancy = true;
}


void Lecturer::set_project_list(char* project_name, char* ID_num, int vacancy_index)
{
	strcpy_s(this->project_list[vacancy_index].name, 50, project_name);
	strcpy_s(this->project_list[vacancy_index].ID_number, 10, ID_num);
	this->project_list[vacancy_index].vacancy = false;
}

char* Lecturer::get_project_IDnumber(int index)
{
	return this->project_list[index].ID_number;
}


void Lecturer::print_info()
{
	std::cout << " " << std::endl;
	std::cout << "Full Lecturer Name: " << this->name << std::endl;
	std::cout << "Email Adress: " << this->email << std::endl;
	std::cout << "Phone Number" << this->phonenumber << std::endl;
	std::cout << "ID Number " << this->ID_Number << std::endl;
	this->return_vacancy_index("BORROW");
	std::cout << "bug";
	if (this->return_vacancy_index("BORROW") == 0)
		std::cout << "Borrowed Equipment: none" << std::endl;
	else {
		for (int i = 0; i < 3; i++)
		{
			if (!this->borrowed_list[i].vacancy)
				std::cout << "Borrowed Equipment(s): " << this->borrowed_list[i].name << "\t" << "Quantity: " << this->borrowed_list[i].quantity
				<< "\t" << "Equipment ID Number: " << this->borrowed_list[i].ID_number << std::endl;
		}
	}
	if (this->return_vacancy_index("HOST") == 0)
		std::cout << "Hosted Projects: none" << std::endl;
	else {
		for (int i = 0; i < 10; i++)
		{
			if (!this->project_list[i].vacancy)
				std::cout << "Project(s) hosted: " << this->project_list[i].name << "\t" << "Project ID Number: " << this->project_list[i].ID_number << std::endl;
		}
	}
	std::cout << " " << std::endl;
}
