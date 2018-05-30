#include"../Headers/Lib.h"



/************************************************************************************************************
**************************************** CONSTRUCTOR ********************************************************
************************************************************************************************************/

Student::Student(char* Name, char* email, char* phonenumber, char* ID_Number)
{
	strcpy_s(this->name, 50, Name);
	strcpy_s(this->email, 50, email);
	strcpy_s(this->ID_Number, 10, ID_Number);
	strcpy_s(this->phonenumber, 20, phonenumber);
}

/************************************************************************************************************
****************************** BASIC STUDENT SETTER AND GETTER***********************************************
************************************************************************************************************/


void Student::set_name(char* name)						{ strcpy_s(this->name, 50, name); }

void Student::set_email(char* email)					{ strcpy_s(this->email, 50, email); }

void Student::set_phonenumber(char* phonenumber)	    { strcpy_s(this->ID_Number, 10, ID_Number); }

void Student::set_IDnumber(char* ID_Number)			    { strcpy_s(this->phonenumber, 20, phonenumber); }



char* Student::get_name()								{ return this->name; }

char* Student::get_email()								{ return this->email; }

char* Student::get_phonenumber()						{ return this->phonenumber; }

char* Student::get_IDnumber()							{ return this->ID_Number; }



/*************************************************************************************************************
****************************** CHECK-OUT AND RETURN EQUIPMENT ************************************************
*************************************************************************************************************/


char* Student::get_equip_IDnumber(int index)
{
	//Return the equipment ID number in the borrow list
	return this->borrowed_list[index].ID_number;
}

int Student::get_equip_quantity(int index)
{
	//Return the equipment quantity in the borrow list
	return this->borrowed_list[index].quantity;
}



void Student::set_borrow_list(char* equip_name, char* ID_number, int index, int quantity, char* date)
{
	//Copy and store borrowed equipment data in the list
	strcpy_s(this->borrowed_list[index].name, 50, equip_name);
	strcpy_s(this->borrowed_list[index].ID_number, 10, ID_number);
	this->borrowed_list[index].vacancy = false;
	this->borrowed_list[index].quantity = quantity;
	strcpy_s(this->borrowed_list[index].date, 5, date);
}


void Student::return_all_equipments(int vacancy)
{
	//Change the element in borrow list back to default 
	strcpy_s(this->borrowed_list[vacancy].name, 50, "none");
	strcpy_s(this->borrowed_list[vacancy].ID_number, 10, "none");
	this->borrowed_list[vacancy].vacancy = true;
	this->borrowed_list[vacancy].quantity = 0;
	strcpy_s(this->borrowed_list[vacancy].date, 5, "N/A");
}


/*************************************************************************************************************
**************************************** PROJECTS INVOLVED LIST **********************************************
*************************************************************************************************************/



void Student::set_project_list(char* project_name, char* ID_num, int vacancy_index)
{
	strcpy_s(this->involved__list[vacancy_index].name, 50, project_name);
	strcpy_s(this->involved__list[vacancy_index].ID_number, 10, ID_num);
	this->involved__list[vacancy_index].vacancy = false;
}


char* Student::get_project_IDnumber(int index)
{
	return involved__list[index].ID_number;
}


void Student::project_done(int index)
{
	strcpy_s(this->involved__list[index].name, 50, "none");
	strcpy_s(this->involved__list[index].ID_number, 10, "none");
	this->involved__list[index].vacancy = true;
}


int  Student::return_occupied_vacancies(const char* mode)
{	
	int occuppied = 0;
	//Check the mode "BORROW" or "HOST"
	if (strcmp(mode, "BORROW") == 0)
	{	
		//Scan through the borrow list
		for (int i = 0; i < 3; i++)		
		{	
			if (this->borrowed_list[i].vacancy == false)	//If the vacancy is false, this place is already occupied
				occuppied += 1 * borrowed_list[i].quantity; //Check for the quantity of the equipment in each index
		}
		std::cout << 3 - occuppied  << "Equipment Vacancy(ies) left" << std::endl;
		std::cout << occuppied << " Equipment(s) borrowed" << std::endl;
	}
	else if (strcmp(mode, "INVOLVED") == 0)
	{
		//Scan through the student project list
		for (int i = 0; i < 2; i++)
		{
			if (this->involved__list[i].vacancy == false)
				occuppied++;
		}
		std::cout << 2 - occuppied << " Project Vacancy(ies) left" << std::endl;
		std::cout << occuppied << "Project(s) involved" << std::endl;
	}
	return occuppied;
}



int Student::return_vacancy_index(const char* mode)
{	
	//Check the mode
	if (strcmp(mode, "BORROW") == 0) {
		//Scan through the borrow list
		for (int i = 0; i < 3; i++)
		{
			if (this->borrowed_list[i].vacancy == true)	//If the position at this index is not occupied
			{
				return i;
			}
		}
	}
	if (strcmp(mode, "INVOLVED") == 0) {
		//Scan through the project list
		for (int i = 0; i < 2; i++)
		{
			if (this->	involved__list[i].vacancy == true)
			{
				return i;
			}
		}
	}
	return -1;
}



/*************************************************************************************************************
************************************* PRINT STUDENT INFORMATION **********************************************
*************************************************************************************************************/


void Student::print_info()
{
	//Print all the basic info
	std::cout << " " << std::endl;
	std::cout << "Full Student Name: " << this->name << std::endl;
	std::cout << "Email Adress: " << this->email << std::endl;
	std::cout << "Phone Number" << this->phonenumber << std::endl;
	std::cout << "ID Number " << this->ID_Number << std::endl;
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
	if (this->return_occupied_vacancies("INVOLVED") == 0)
		//If zero occupied vacancy return
		std::cout << "Involved Projects: none" << std::endl;
	else {
		for (int i = 0; i < 2; i++)	//Scan the project list and print the project info (if any)
		{
			//Check for the occuped index
			std::cout << "Index: " << i << std::endl;
			if (!this->involved__list[i].vacancy)
				//Print the project info if encounter a occupied index
				std::cout <<"Index in condition: " << involved__list[i].vacancy <<  "Project involved: " << this->involved__list[i].name << "\n" << "Project ID Number: " << this->involved__list[i].ID_number << std::endl;
		}
	}	
	std::cout << "************" << std::endl;
	std::cout << " " << std::endl;
}
