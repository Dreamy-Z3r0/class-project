#pragma once
#include"Lib.h"

class Equipment {
private:
	std::string label;
	std::string model;
	int quantity;
	float price;

public: 
	Equipment();
	void add_equipment(std::string label, int quantity, float price);
	void delete_equipment();
	void update();
	void search();
	void print_equip_info();
};
