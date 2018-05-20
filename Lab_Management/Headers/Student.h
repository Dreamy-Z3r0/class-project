#pragma once
#include"Lib.h"
class Student {
protected:
	char name[50];
	char email[50];
	char phonenumber[10];
	char ID_Number[10];
public:
	Student() {};
	Student(char* Name, char* email, char* phonenumber, char* ID_Number );
	~Student() {};
	void set_name(char* name);
	void set_email(char*email);
	void set_phonenumber(char* phonenumber);
	void set_IDnumber(char* ID_Number);
	char* get_name();
	char* get_email();
	char* get_phonenumber();
	char* get_IDnumber();
	void print_info() const;
	void check_out() {};
	void return_object() {};
};
