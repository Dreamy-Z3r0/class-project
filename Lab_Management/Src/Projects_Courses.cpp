#include"../Headers/Projects_Courses.h"

Projects_Courses::Projects_Courses(char* name, char* ID_number, char* start_date, char* duration, char* description, const char* status )
{
	strcpy_s(this->name,50, name);
	strcpy_s(this->ID_number, 10, ID_number);
	strcpy_s(this->start_date,10, start_date);
	strcpy_s(this->duration,10, duration);
	strcpy_s(this->status, 10, status);
	strcpy_s(this->description,100, description);
}

Projects_Courses::~Projects_Courses() {}
char* Projects_Courses::get_name()
{
	return this->name;
}

char* Projects_Courses::get_IDnumber()
{
	return this->ID_number;
}

void Projects_Courses::change_status(char* status)
{
	strcpy_s(this->status, 10, status);
}

void Projects_Courses::print_info()
{
	std::cout << " " << std::endl;
	std::cout << "Project name: " << name << ": (" << status << ")\n";
	std::cout << "Start: " << start_date;
	std::cout << "\nDuration: " << duration;
	std::cout << "\nDescription: " << description << std::endl;

	std::cout << " " << std::endl;
	std::cout << "Tutor(s): " << std::endl;
	for (int i = 0; i < 2; i++)
	{
		if (!Tutor_list[i].vacancy)
		{
			std::cout << "Name: " << i + 1 << Member_List[i].name << std::endl;
			std::cout << "ID number: " << Member_List[i].ID_Number << std::endl;
		}
	}


	std::cout << " " << std::endl;
	std::cout << "Member List: " << std::endl;
	for (int i = 0; i < 5; i++)
	{	
	
		if (!Member_List[i].vacancy)
		{
			std::cout << "Member: " << i + 1 <<  Member_List[i].name << std::endl;
			std::cout << "ID number: " << Member_List[i].ID_Number << std::endl;
		}
	}

}
int Projects_Courses::return_occupied_vacancies()
{
	int occuppied = 0;
	int un_occupied = 0;
	// Check occupied and unoccupied vacancy
	for (int i = 0; i < 7; i++)
	{
		if (this->Member_List[i].vacancy == true)
			un_occupied++;
		else occuppied ++;
	}
	std::cout << un_occupied << " Vacancies in this project left" << std::endl;
	std::cout << occuppied << " Students in this project" << std::endl;
	return occuppied;
}

int Projects_Courses::return_vacancy_index()
{
	for (int i = 0; i < 3; i++)
	{
		if (this->Member_List[i].vacancy == true)
		{
			std::cout << "first index: " << i << std::endl;
			return i;
		}
	}
	return -1;
}


void Projects_Courses::add_member(char* name, char* ID_number, int index)
{
	strcpy_s(this->Member_List[index].name, 50, name);
	strcpy_s(this->Member_List[index].ID_Number, 10, ID_number);
	this->Member_List[index].vacancy = false;

}

bool Projects_Courses::duplicate_member_check(char* ID_number)
{
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(Member_List[i].ID_Number,ID_number) == 0) return true;
	}
	return false;
}