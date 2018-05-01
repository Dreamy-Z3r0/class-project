#pragma once
#include"Lib.h"
class Member {
private:
	std::string name;
	std::string ID_number;
	std::string Class;
	std::string email;
	std::string phonenumber;
public:
	Member();
	void add_member(std::string name, std::string ID_number, std::string Class, std::string email, std::string phonenumber);
	void delete_member();
	void Update();
	void print_member_info();
};
