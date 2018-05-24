#pragma once
#include"Lib.h"
struct borrowthings
{	
	bool vacancy = true;
	char name[50] = "None";
	int quantity = 0;
	char date[5] = "N/A";
};

class Student {
protected:
	char name[50];
	char email[50];
	char phonenumber[20];
	char ID_Number[10];

	borrowthings list[3];
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
	void set_borrow_list(char* equip_name, int vacancy, int quantity, char* date);	
	
/***********************************
***********GET DATA*****************
************************************/
	char* get_name();
	char* get_email();
	char* get_phonenumber();
	char* get_IDnumber();
	char* get_equip_name(int index);
	int get_equip_quantity(int index);

	int return_vacancy_index();
	int occupied_vacancies();
	void return_all_equipments(int vacancy);


	void borrow_things() {};
	void return_things() {};
	void print_info();
	void check_out() {};
	void return_object() {};
};
