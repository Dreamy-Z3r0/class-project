#pragma once
#include"Lib.h"
class Member {
protected:
	std::string name;
	std::string email;
	unsigned long phonenumber;
	unsigned long ID_Number;
	bool status;
public:
	Member() {};
	virtual ~Member() {};
	virtual void Add_a_Member() {};
	virtual void print_info() {};
	virtual void borrow() {};
	virtual void update() {};
	virtual void delete_member() {};
};

