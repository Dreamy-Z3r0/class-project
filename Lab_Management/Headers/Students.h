#pragma once
#include"Lib.h"

class Students :public Member
{
public:
	Students() {};
	void Add_a_Member(std::string Name, std::string Email, unsigned long ID_Number, unsigned long phonenumber) override;
	void print_info() override;
	void borrow() override;
	void update() override;
	void delete_member() override;
};