#include"../Headers/Lib.h"





/**
 *Initialize Constructor for class Student
 *@param <char*> $Name, $email, $phonenumbe, $ID_Number 
 */
Student::Student(char* Name, char* email, char* phonenumber, char* ID_Number)
{
	strcpy_s(this->name, 50, Name);
	strcpy_s(this->email, 50, email);
	strcpy_s(this->ID_Number, 10, ID_Number);
	strcpy_s(this->phonenumber, 20, phonenumber);
}
/*******************************************************************
********************BASIC STUDENT SETTER AND GETTER*****************
********************************************************************/

/**
 *Student name, email, telephone, ID_number setter
 *@param <char*> $var
 *@return void
 */
void Student::set_name(char* name)						{ strcpy_s(this->name, 50, name); }

void Student::set_email(char* email)					{ strcpy_s(this->email, 50, email); }

void Student::set_phonenumber(char* phonenumber)	    { strcpy_s(this->ID_Number, 10, ID_Number); }

void Student::set_IDnumber(char* ID_Number)			    { strcpy_s(this->phonenumber, 20, phonenumber); }


/**
*Student name, email, phonenumber, ID_number getter
*@param none
*@return char*
*/

char* Student::get_name()								{ return this->name; }

char* Student::get_email()								{ return this->email; }

char* Student::get_phonenumber()						{ return this->phonenumber; }

char* Student::get_IDnumber()							{ return this->ID_Number; }


/*******************************************************************
***************CHECK-OUT AND RETURN EQUIPMENT***********************
********************************************************************/

/**
 *Modify a specific equipment in the borrow list
 *@param <char*> $equip_name, <int> $index, <int> $quantity, <char*> $date
 *@return void
 */

void Student::set_borrow_list(char* equip_name, char* ID_number, int index, int quantity, char* date)
{
	strcpy_s(this->borrowed_list[index].name, 50, equip_name);
	strcpy_s(this->borrowed_list[index].ID_number, 10, ID_number);
	this->borrowed_list[index].vacancy = false;
	this->borrowed_list[index].quantity = quantity;
	strcpy_s(this->borrowed_list[index].date, 5, date);
}

/**
 *For a specific equipment whose quantity is more than one, return all 
 *@param <int> $index
 *@return void
 */

void Student::return_all_equipments(int vacancy)
{
	strcpy_s(this->borrowed_list[vacancy].name, 50, "none");
	strcpy_s(this->borrowed_list[vacancy].ID_number, 10, "none");
	this->borrowed_list[vacancy].vacancy = true;
	this->borrowed_list[vacancy].quantity = 0;
	strcpy_s(this->borrowed_list[vacancy].date, 5, "N/A");
}

/**
 *Return the number of borrowed equipment(s)
 *@param none
 *@return int
 */

int  Student::return_occupied_vacancies(const char* mode)
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
		std::cout << 3 - occuppied  << " Vacancy(ies) left" << std::endl;
		std::cout << occuppied << " Equipment(s) borrowed" << std::endl;
	}
	else if (strcmp(mode, "INVOLVED") == 0)
	{
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

/**
 *Check and return vacancy in the borrow list. Return -1 if the list is full.
 *@param none
 *@return int
 */

int Student::return_vacancy_index(const char* mode)
{
	if (strcmp(mode, "BORROW") == 0) {
		for (int i = 0; i < 3; i++)
		{
			if (this->borrowed_list[i].vacancy == true)
			{
				std::cout << "first index: " << i << std::endl;
				return i;
			}
		}
	}
	if (strcmp(mode, "INVOLVED") == 0) {
		for (int i = 0; i < 2; i++)
		{
			if (this->	involved__list[i].vacancy == true)
			{
				std::cout << "first index: " << i << std::endl;
				return i;
			}
		}
	}
	return -1;
}

/**
 *Return a specific equipment name in the borrow list 
 *@param <int> index
 *@return char*
 */

char* Student::get_equip_IDnumber(int index)
{
	return this->borrowed_list[index].ID_number;
}

/**
*Return a specific equipment quantity in the borrow list
*@param <int> index
*@return char*
*/

int Student::get_equip_quantity(int index) 
{
	return this->borrowed_list[index].quantity;
}


/*******************************************************************
********************PRINT STUDENT INFORMATION***********************
********************************************************************/

/**
*Print all the student infomation 
*@param none
*@return void
*/

void Student::print_info()
{
	//std::cout << this->name << "\t\t\t" << this->email << "\t\t\t" << this->phonenumber << "\t\t\t" << this->ID_Number << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Full Student Name: " << this->name << std::endl;
	std::cout << "Email Adress: " << this->email << std::endl;
	std::cout << "Phone Number" << this->phonenumber << std::endl;
	std::cout << "ID Number " << this->ID_Number << std::endl;

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
	if (this->return_vacancy_index("INVOLVED") == 0)
		std::cout << "Involved Projects: none" << std::endl;
	else {
		for (int i = 0; i < 2; i++)
		{
			if (!this->involved__list[i].vacancy)
				std::cout << "Project involved: " << this->involved__list[i].name << "\n" << "Project ID Number: " << this->involved__list[i].ID_number << std::endl;
		}
	}	
	std::cout << " " << std::endl;
}

void Student::set_project_list(char* project_name, char* ID_num, int vacancy_index)
{
	strcpy_s(this->involved__list[vacancy_index].name, 50, project_name);
	strcpy_s(this->involved__list[vacancy_index].ID_number, 10, ID_num);
	this->involved__list[vacancy_index].vacancy = false;
}
