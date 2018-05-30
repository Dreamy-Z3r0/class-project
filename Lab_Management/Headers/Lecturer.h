#pragma once

#include "Lib.h"
#include "Check_Vacancy.h"


class Lecturer : public Student
{
private:
	projects project_list[5];
public:

/************************************************************************************************************
**************************************** CONSTRUCTOR ********************************************************
************************************************************************************************************/	
	
//Initialize the instance
	Lecturer() {};
	Lecturer(char* Name, char* Email, char* phonenumber, char* ID_Number);
	

/*************************************************************************************************************
************************************ PROJECTS HOSTED LIST ****************************************************
*************************************************************************************************************/
	
	/*
	*Return the number of occupied vacancy(s). This function takes in 2 modes:
	*BORROW: return occupied vacancies in equipment borrowed list
	*HOST: return occupied vacancies in project tutor list
	*/
	int return_occupied_vacancies(const char* mode) override;

	/*Return vacancy index. Return - 1 if the list is full.Also opperate in two modes :
	*"BORROW" : return the vacancy index in the borrow list
	*"HOST" : return the vacancy index in the project list
	*/
	int return_vacancy_index(const char* mode) override;
	
	//Add a new project to the tutor's project hosted list
	void set_project_list(char* project_name, char* ID_num, int vacancy_index) override;
	//Return the Project ID number
	char* get_project_IDnumber(int index) override;
	//Remove the project from the list
	void project_done(int index) override;
	//Print the Lecturer Info
	void print_info() override;
};