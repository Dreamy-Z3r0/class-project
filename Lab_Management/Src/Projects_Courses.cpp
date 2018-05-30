#include"../Headers/Projects_Courses.h"



/************************************************************************************************************
**************************************** CONSTRUCTOR ********************************************************
************************************************************************************************************/

Projects_Courses::Projects_Courses(char* name, char* ID_number, char* tutor_name, char* tutor_ID_number, 
	char* start_date, char* duration, char* description, const char* status )
{	
	//Copy and store the data to a member
	strcpy_s(this->name,50, name);
	strcpy_s(this->ID_number, 10, ID_number);
	strcpy_s(this->project_tutor.name, 50, tutor_name);
	strcpy_s(this->project_tutor.ID_Number, 10, tutor_ID_number);
	strcpy_s(this->start_date,10, start_date);
	strcpy_s(this->duration,10, duration);
	strcpy_s(this->status, 50, status);
	strcpy_s(this->description,100, description);
}

Projects_Courses::~Projects_Courses() {}



/************************************************************************************************************
************************************ BASIC PROJECT GETTER AND SETTER ****************************************
************************************************************************************************************/
char* Projects_Courses::get_name()
{
	return this->name;	//Return the name of the project
}

char* Projects_Courses::get_IDnumber()
{
	return this->ID_number;	//Return the ID number of the project
}

char* Projects_Courses::get_status()
{
	return this->status;
}
char* Projects_Courses::get_tutor_IDnumber()
{
	return this->project_tutor.ID_Number;	//Return ID number of the tutor
}

char* Projects_Courses::get_member_IDnumber(int index)
{
	return this->Member_List[index].ID_Number;	//Return ID number of the member
}

void Projects_Courses::set_tutor_name(char* name, char* id_number)	//Set tutor name again
{
	strcpy_s(this->project_tutor.name, 50, name);
	strcpy_s(this->project_tutor.ID_Number, 10, id_number);
}




/************************************************************************************************************
****************************** PROJECT OPPERATION FUNCTIONS *************************************************
************************************************************************************************************/


void Projects_Courses::change_status(char* status)
{
	strcpy_s(this->status, 50, status);	//Rewrite the project status
}


int Projects_Courses::return_occupied_vacancies(const char* mode)
{
	int occuppied = 0;

	//Check if the mode is "MEMBER" or "TUTOR"
	if (strcmp(mode, "MEMBER") == 0)
	{
		//Scan through the member list
		for (int i = 0; i < 5; i++)
		{	
			//Check if the position is occupied, and add to the variable
			if (this->Member_List[i].vacancy == false)
				occuppied++;
		}
		std::cout << 5 - occuppied << " Vacancies in this project left" << std::endl;
		std::cout << occuppied << " Students in this project" << std::endl;
	}
	else if (strcmp(mode, "TUTOR") == 0)
	{
		//Scan through the hosted project list
		if (project_tutor.vacancy == false)
		{
			//Check if the position is occupied yet
			occuppied++;
			std::cout << "There is a tutor already!" << std::endl;
		}
	}
	return occuppied;	//Return the occupied vacancy
}

int Projects_Courses::return_vacancy_index(const char* mode)
{
	//Check if the mode is "MEMBER" or "TUTOR"
	if (strcmp(mode, "MEMBER") == 0) {
		//Scan through the borrow list
		for (int i = 0; i < 5; i++)
		{
			//if a vacancy is found, return its index
			if (this->Member_List[i].vacancy == true)
			{
				return i;
			}
		}
	}
	else if (strcmp(mode, "TUTOR") == 0)
	{
		//If there is no tutor, return 0
		if (this->project_tutor.vacancy == true) return 0;
	}
	return -1;
}


void Projects_Courses::add_member(char* name, char* ID_number, int index)
{
	//copy and store data to a variable
	strcpy_s(this->Member_List[index].name, 50, name);
	strcpy_s(this->Member_List[index].ID_Number, 10, ID_number);
	this->Member_List[index].vacancy = false;

}

void Projects_Courses::release_all_members()
{
	for (int i = 0; i < 5; i++)
	{
		Member_List[i].vacancy = true;
		strcpy_s(this->Member_List[i].name, 50, "none");
		strcpy_s(this->Member_List[i].ID_Number, 10, "none");
	}
}

bool Projects_Courses::project_check_finish()
{
	if (strcmp(this->status, "Finished") == 0 || strcmp(this->status, "Abandoned") == 0)
		return true;
	return false;
}

bool Projects_Courses::duplicate_member_check(char* ID_number)
{
	//Scan through the list
	for (int i = 0; i < 5; i++)
	{
		//Compare the input ID and the student ID in the list
		if (strcmp(Member_List[i].ID_Number,ID_number) == 0) return true;	//If found, return true
	}
	//If there is no duplicate member, return false
	return false;
}




void Projects_Courses::print_info()
{
	//Print basic information
	std::cout << " " << std::endl;
	std::cout << "Project name: " << name << ": (" << status << ")\n";
	std::cout << "ID Number: " << ID_number;
	std::cout << "\nStart: " << start_date;
	std::cout << "\nDuration: " << duration;
	std::cout << "\nDescription: " << description << std::endl;
	//Print the tutor info
	std::cout << " " << std::endl;
	std::cout << "Tutor: " << project_tutor.name << "\t" << "Tutor ID Number: " << project_tutor.ID_Number << std::endl;

	std::cout << " " << std::endl;
	//Check if there is any member in the project's member list
	if (this->return_occupied_vacancies("MEMBER") == 0)
		//If zero occupied vacancy return 
		std::cout << "Member List: none" << std::endl;
	else {
		//Scan the member list and print the member info 
		for (int i = 0; i < 5; i++)
		{
			//Check for the occuped index
			if (!Member_List[i].vacancy)
			{
				//Print the member info if encounter a occupied index
				std::cout << "**** Member: " << i + 1 << "\n" << Member_List[i].name << std::endl;
				std::cout << "ID number: " << Member_List[i].ID_Number << std::endl;
				std::cout << " " << std::endl;
			}
		}
	}
}