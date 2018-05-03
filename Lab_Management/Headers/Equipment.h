#pragma once
#include"Lib.h"

class Equipment {
private:
	std::string label;
	int quantity;
	float price;

public: 
	Equipment();
	Equipment(std::string label, int quantity, float price);
	~Equipment();
	void modifier(std::string label, int quantity_change);
	void update();
	void search();
	void print_equip_info();
};
