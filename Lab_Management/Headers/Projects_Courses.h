#pragma once
#include"Lib.h"
#include"Check_Vacancy.h"

//Set up a struct to store tutor data
struct Tutor
{
	char name[50] = "none";
	char ID_Number[10] = "none";
	bool vacancy = true;
};
//Set up a struct to store member data
struct Member
{
	char name[50] = "none";
	char ID_Number[10] = "none";
	bool vacancy = true;
};




class Projects_Courses : public Check_Vacancy {
private:
	//Variable declaration
	char name[50];
	char ID_number[20];
	char start_date[10];
	char duration[10];
	char status[50];
	char description[100];

	Member Member_List[5];
	Tutor project_tutor;

public:

/************************************************************************************************************
**************************************** CONSTRUCTOR ********************************************************
************************************************************************************************************/
	Projects_Courses() {};
	Projects_Courses(char* name, char* ID_number, char* tutor_name, char* tutor_ID_number,
	char* start_date, char* duration, char* description, const char* status = "On-Going");
	~Projects_Courses();


/************************************************************************************************************
************************************ BASIC PROJECT GETTER AND SETTER ****************************************
************************************************************************************************************/

	char* get_name();
	char* get_IDnumber();
	char* get_status();
	char* get_tutor_IDnumber();
	char* get_member_IDnumber(int index);

	void set_tutor_name(char* name, char* id_number);


/************************************************************************************************************
****************************** PROJECT OPPERATION FUNCTIONS *************************************************
************************************************************************************************************/

	//Add a new member to the project's member list
	void add_member(char* name, char* ID_number, int index);
	//Update the status of the project
	void change_status(char* status);
	//Check if the project is finished or abandoned
	bool project_check_finish();
	//Release all its ex-member data
	void release_all_members();
	/*
	*Return vacancy index. Return - 1 if the list is full. Also opperate in two modes :
	*MEMBER: return vacancy indexs in member list
	*TUTOR: return 0 if there is no tutor
	*/
	int return_vacancy_index(const char* mode) override;
	/*
	*Return the number of occupied vacancy(s). This function takes in 2 modes:
	*MEMBER: return occupied vacancies in member list
	*TUTOR: return if the tutor vacancy is occupied
	*/
	int return_occupied_vacancies(const char* mode) override;
	//Check if there is a duplicate member in the member list
	bool duplicate_member_check(char* ID_number);
	//Print the project info
	void print_info();

	
};
