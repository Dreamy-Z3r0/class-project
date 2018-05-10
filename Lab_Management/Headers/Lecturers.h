#pragma once

#include "Lib.h"

class Lectures:public Member
{
public:
	Lectures() {};
	Lectures(std::string Name, std::string Email, std::string ID_Number, std::string phonenumber);
	void print_info() const override;
	void borrow() override;
	void update() override;
	void delete_member() override;
};