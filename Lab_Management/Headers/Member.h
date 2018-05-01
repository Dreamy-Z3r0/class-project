#pragma once
#include"Lib.h"
class Member {
private:
	std::string name;
	std::string age;
	std::string phonenumber;
	std::string ID_number;
public:
	Member();
	void add_member(std::string name, std::string age, std::string phonenumber, std::string ID_number);
	void delete_member();
	void Update();
	void print_member_info();
};