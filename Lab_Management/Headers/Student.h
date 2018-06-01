#pragma once
#include"Lib.h"
#include"Check_Vacancy.h"

//Set up a struct to store equipment data
struct borrowthings
{	
	bool vacancy = true;
	char name[50] = "None";
	char ID_number[10] = "None";
	int quantity = 0;
	char date[10] = "N/A";
};

//Set up a struct to store project data
struct projects
{
	bool vacancy = true;
	char name[50] = "none";
	char ID_number[10] = "none";
};

class Student : public Check_Vacancy {
protected:
	char name[50];
	char email[50];
	char phonenumber[20];
	char ID_Number[10];
	borrowthings borrowed_list[3];	//List of borrowed equipments
private:
	projects involved__list[2];	//List of projects involved
public:

/************************************************************************************************************
**************************************** CONSTRUCTOR ********************************************************
************************************************************************************************************/

	//Initialize Constructor for class Student
	Student() {};
	Student(char* Name, char* email, char* phonenumber, char* ID_Number);
	~Student() {};

/************************************************************************************************************
****************************** BASIC STUDENT SETTER AND GETTER***********************************************
************************************************************************************************************/
	
	//Basic Student name, email, telephone, ID_number setter
	void set_name(char* name);
	void set_email(char*email);
	void set_phonenumber(char* phonenumber);
	void set_IDnumber(char* ID_Number);
	

	//Student name, email, phonenumber, ID_number getter
	char* get_name();
	char* get_email();
	char* get_phonenumber();
	char* get_IDnumber();


/*************************************************************************************************************
****************************** CHECK-OUT AND RETURN EQUIPMENT ************************************************
*************************************************************************************************************/
	
	//Return an equipment ID number in the borrow list
	char* get_equip_IDnumber(int index);
	//Return an equipment quantity in the borrow list
	int get_equip_quantity(int index);

	//Modify a specific equipment in the borrow list
	void set_borrow_list(char* equip_name, char* ID_number, int vacancy, int quantity, char* date);
	//For a specific equipment whose quantity is only one, return all 
	void return_all_equipments(int vacancy);



/*************************************************************************************************************
**************************************** PROJECTS INVOLVED LIST **********************************************
*************************************************************************************************************/
	
	//Add a new project to the student's project list
	virtual void set_project_list(char* project_name, char* ID_num, int vacancy_index);
	//Return the Project ID number
	virtual char* get_project_IDnumber(int index);
	//Remove the project from the list
	virtual void project_done(int index);

	/*
	*Return the number of occupied vacancy(s). This function takes in 2 modes:
	*BORROW: return occupied vacancies in borrow list
	*HOST: return occupied vacancies in project involved list
	*/
	int return_occupied_vacancies(const char* mode) override;

	/*Return vacancy index. Return - 1 if the list is full.Also opperate in two modes :
	*"BORROW" : return the vacancy index in the borrow list
	*"HOST" : return the vacancy index in the project list
	*/
	int return_vacancy_index(const char* mode) override;

	//Print the Student Info
	virtual void print_info();

};
