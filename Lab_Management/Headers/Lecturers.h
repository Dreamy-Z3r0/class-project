#pragma once

#include "Lib.h"

class Lectures:public Member
{
public:
	Lectures() {};
	void Add_a_Member(std::string Name, std::string Email, unsigned long ID_Number, unsigned long phonenumber) override;
	void print_info() override ;
	void borrow();
	void update();
	void delete_member();
};