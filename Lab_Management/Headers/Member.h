#pragma once
#include"Lib.h"
class Member {
protected:
	std::string name;
	std::string email;
	std::string phonenumber;
	std::string ID_Number;
	bool status;
public:
	Member() {};
	~Member() {};
	virtual void Add_a_Member(std::string Name, std::string Email, unsigned long ID_Number, unsigned long phonenumber) {};
	void print_info() const {};
	void borrow() {};
	void update() {};
	void delete_member() {};
};

