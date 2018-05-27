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
	strcpy_s(this->list[index].name, 50, equip_name);
	strcpy_s(this->list[index].ID_number, 10, ID_number);
	this->list[index].vacancy = false;
	this->list[index].quantity = quantity;
	strcpy_s(this->list[index].date, 5, date);
}

/**
 *For a specific equipment whose quantity is more than one, return all 
 *@param <int> $index
 *@return void
 */

void Student::return_all_equipments(int vacancy)
{
	strcpy_s(this->list[vacancy].name, 50, "none");
	strcpy_s(this->list[vacancy].ID_number, 10, "none");
	this->list[vacancy].vacancy = true;
	this->list[vacancy].quantity = 0;
	strcpy_s(this->list[vacancy].date, 5, "N/A");
}

/**
 *Return the number of borrowed equipment(s)
 *@param none
 *@return int
 */

int  Student::return_occupied_vacancies() 
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

/**
 *Check and return vacancy in the borrow list. Return -1 if the list is full.
 *@param none
 *@return int
 */

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

/**
 *Return a specific equipment name in the borrow list 
 *@param <int> index
 *@return char*
 */

char* Student::get_equip_IDnumber(int index)
{
	return this->list[index].ID_number;
}

/**
*Return a specific equipment quantity in the borrow list
*@param <int> index
*@return char*
*/

int Student::get_equip_quantity(int index) 
{
	return this->list[index].quantity;
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
	std::cout << "Full Name: " << this->name << std::endl;
	std::cout << "Email Adress: "<< this->email << std::endl;
	std::cout << "Phone Number" << this->phonenumber << std::endl; 
	std::cout << "ID Number " << this->ID_Number << std::endl;
	int vacancy_index = this->return_vacancy_index();
	for (int i = 0; i < 3; i++)
	{
		if (!this->list[i].vacancy)
			std::cout << "Equipment borrowed: " << this->list[i].name << "\t" << "Quantity: " << this->list[i].quantity 
			<< "\t" << "ID Number: " << this->list[i].ID_number<<std::endl;
	}
	for (int i = 0; i < 2; i++)
	{	
		if (!this->involved_project[i].vacancy)
			std::cout << "Project involved: " << this->involved_project[i].name << "\n" << "ID Number: " << this->list[i].ID_number << std::endl;
	}
	std::cout << " " << std::endl;
}



int Student::return_project_vacancy_index()
{
	for (int i = 0; i < 2; i++)
	{
		if (involved_project[i].vacancy == true) return i;
	}
	return -1;
}

void Student::set_project_list(char* project_name, int vacancy_index)
{
	strcpy_s(this->involved_project[vacancy_index].name, 50, project_name);
	this->involved_project[vacancy_index].vacancy = false;
}