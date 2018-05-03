#pragma once
#include"Lib.h"

class Students :public Member
{
public:
	Students() {};
	void Add_a_Member(std::string Name, std::string Email, unsigned long ID_Number, unsigned long phonenumber);
	void print_info();
	void borrow();
	void update();
	void delete_member();
};

