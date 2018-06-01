#include"../Headers/Lib.h"



/************************************************************************************************************
**************************************** CONSTRUCTOR ********************************************************
************************************************************************************************************/

Lecturer::Lecturer(char* Name, char* Email, char* phonenumber, char* ID_Number)
{
	//Copy and store data to a member
	strcpy_s(this->name, 50, Name);
	strcpy_s(this->email, 50, Email);
	strcpy_s(this->phonenumber, 20, phonenumber);
	strcpy_s(this->ID_Number, 10, ID_Number);
}

int  Lecturer::return_occupied_vacancies(const char* mode)
{
	int occuppied = 0;
	//Check if the mode is "BORROW" or "HOST"
	if (strcmp(mode, "BORROW") == 0)
	{
		//Scan through the borrow list
		for (int i = 0; i < 3; i++)
		{
			if (this->borrowed_list[i].vacancy == false)	//If the position at this index is occupied
				occuppied += 1 * borrowed_list[i].quantity;	//Check for the quantity of the equipment in each index
		}
		std::cout << 3 - occuppied << " Equipment Vacancy(ies) left" << std::endl;
		std::cout << occuppied << " Equipment(s) borrowed" << std::endl;
	}
	else if (strcmp(mode, "HOST") == 0)
	{
		//Scan through the hosted project list
		for (int i = 0; i < 5; i++)	
		{
			if (this->project_list[i].vacancy == false)	//Check if the position is occupied, and add to the variable
				occuppied++;
		}
		std::cout << 5 - occuppied << " Project Hosted Vacancy(ies) left" << std::endl;
		std::cout << occuppied << " Project(s) Hosted" << std::endl;
	}
	return occuppied;	//Return the occupied vacancy
}


int Lecturer::return_vacancy_index(const char* mode)
{	
	//Check if the mode is "BORROW" or "HOST"
	if (strcmp(mode, "BORROW") == 0) {
		//Scan through the borrow list
		for (int i = 0; i < 3; i++)
		{	
			//if a vacancy is found, return its index
			if (this->borrowed_list[i].vacancy == true)
			{
				return i;
			}
		}
	}
	else if (strcmp(mode, "HOST") == 0) {
		//Scan through the hosted project list
		for (int i = 0; i < 5; i++)
		{
			//If a vacancy is found, return its index
			if (this->project_list[i].vacancy == true)
			{
				return i;
			}
		}
	}
return -1;
}


void Lecturer::project_done(int index)
{
	//Copy and store Data to a member
	strcpy_s(this->project_list[index].name, 50, "none");
	strcpy_s(this->project_list[index].ID_number, 10, "none");
	this->project_list[index].vacancy = true;
}


void Lecturer::set_project_list(char* project_name, char* ID_num, int vacancy_index)
{
	//Copy and store Data to the host project list
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
	//Print basic information
	std::cout << " " << std::endl;
	std::cout << "Full Lecturer Name: " << this->name << std::endl;
	std::cout << "Email Adress: " << this->email << std::endl;
	std::cout << "Phone Number: " << this->phonenumber << std::endl;
	std::cout << "ID Number: " << this->ID_Number << std::endl;
	std::cout << "************" << std::endl;
	//Check if there is any equipment in the borrow list
	if (this->return_occupied_vacancies("BORROW") == 0)
	//If zero occupied vacancy return 
		std::cout << "Borrowed Equipment: none" << std::endl;
	else {
		//Scan the borrow list and print the equipment info 
		for (int i = 0; i < 3; i++)
		{
			//Check for the occuped index
			if (!this->borrowed_list[i].vacancy)
				//Print the equipment info if encounter a occupied index
				std::cout << "Borrowed Equipment(s): " << this->borrowed_list[i].name << "\t" << "Quantity: " << this->borrowed_list[i].quantity
				<< "\t" << "Equipment ID Number: " << this->borrowed_list[i].ID_number << std::endl;
		}
	}
	std::cout << "************" << std::endl;
	//Check if there is any project in the project list
	if (this->return_occupied_vacancies("HOST") == 0)
		//If zero occupied vacancy return
		std::cout << "Hosted Projects: none" << std::endl;
	else {
		for (int i = 0; i < 5; i++)
		{
			//Check for the occuped index
			if (!this->project_list[i].vacancy)
				//Print the project info if encounter a occupied index
				std::cout << "Project(s) hosted: " << this->project_list[i].name << "\t" << "Project ID Number: " << this->project_list[i].ID_number << std::endl;
		}
	}
	std::cout << "************" << std::endl;
	std::cout << " " << std::endl;
}
