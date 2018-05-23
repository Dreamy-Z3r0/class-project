#pragma once
#include"Lib.h"

class Equipment {
private:
	char name[50];
	int quantity;
	int availability;

public: 
	Equipment() {};
	Equipment(char* name, int quantity = 1);
	~Equipment();
	char* get_name();
	int get_availability();
	void set_name(char* name);
	void quantity_change(int num);
	void availability_change(int num);
	void print_info() const;
};
