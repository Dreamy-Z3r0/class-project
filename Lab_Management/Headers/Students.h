#pragma once
#include"Lib.h"

class Students :public Member
{
public:
	Students() {};
	Students(std::string Name, std::string email, std::string ID_Number, std::string phonenumber);
	void print_info() const override;
	void borrow() override;
	void update() override;
	void delete_member() override;
};