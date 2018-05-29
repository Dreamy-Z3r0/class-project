#pragma once
#include"Lib.h"
#include"Check_Vacancy.h"

struct borrowthings
{	
	bool vacancy = true;
	char name[50] = "None";
	char ID_number[10] = "None";
	int quantity = 0;
	char date[5] = "N/A";
};

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
	borrowthings borrowed_list[3];
private:
	projects involved__list[2];
public:
/***********************************
***********CONSTRUCTOR**************
************************************/
	Student() {};
	Student(char* Name, char* email, char* phonenumber, char* ID_Number);
	~Student() {};


/***********************************
***********SETTER*******************
************************************/
	void set_name(char* name);
	void set_email(char*email);
	void set_phonenumber(char* phonenumber);
	void set_IDnumber(char* ID_Number);
	void set_borrow_list(char* equip_name, char* ID_number, int vacancy, int quantity, char* date);	
	virtual void set_project_list(char* project_name, char* ID_num, int vacancy_index);
	
/***********************************
***********GET DATA*****************
************************************/
	char* get_name();
	char* get_email();
	char* get_phonenumber();
	char* get_IDnumber();
	char* get_equip_IDnumber(int index);
	int get_equip_quantity(int index);

	int return_vacancy_index(const char* mode) override;
	int return_occupied_vacancies(const char* mode) override;
	void return_all_equipments(int vacancy);
	virtual void print_info();

};
