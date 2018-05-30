#pragma once
#include"Lib.h"

class Equipment {
private:
	char name[50];
	char ID_number[10];
	int quantity;
	int availability;

public: 

/************************************************************************************************************
**************************************** CONSTRUCTOR ********************************************************
************************************************************************************************************/

	Equipment() {};
	Equipment(char* name, char* ID_number, int quantity = 1);
	~Equipment();



/************************************************************************************************************
****************************** BASIC EQUIPMENT SETTER AND GETTER ********************************************
************************************************************************************************************/
	//Return the equipment name
	char* get_name();
	//Return the equipment ID number
	char* get_IDnumber();
	//Return the available quantity of the equipment
	int get_availability();
	//Set the equipment name
	void set_name(char* name);


/************************************************************************************************************
************************************* BASIC EQUIPMENT OPPERATION ********************************************
************************************************************************************************************/

	//Change the equipment quantity
	void quantity_change(int num);
	//Change the equipment availability
	void availability_change(int num);
	//Print the equipment Information
	void print_info() const;
};
