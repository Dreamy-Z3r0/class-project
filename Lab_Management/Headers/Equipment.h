#pragma once
#include"Lib.h"

class Equipment {
private:
	std::string label;
	std::string model;
	int number;
	float price;

public: 
	Equipment();
	void add_equipment(std::string label, std::string model, int number, float price);
	void delete_equipment();
	void update();
	void search();
	void print_equip_info();
};