#pragma once
#include"Lib.h"
class Student {
protected:
	std::string name;
	std::string email;
	std::string phonenumber;
	std::string ID_Number;
public:
	Student() {};
	Student(std::string Name, std::string email, std::string ID_Number, std::string phonenumber);
	~Student() {};
	void set_name(std::string name);
	void set_email(std::string email);
	void set_phonenumber(std::string phonenumber);
	void set_IDnumber(std::string ID_Number);
	void print_info() const;
	void check_out() {};
	void return_object() {};
};
