#pragma once
#include"Lib.h"

class Equipment {
private:
	std::string name;
	int quantity;
	int availability;

public: 
	Equipment(std::string name, int quantity = 1);
	~Equipment();
	void set_name(std::string name);
	void quantity_change(int num);
	void availability_change(int num);
	void print_info();
};
