#pragma once
#include"Lib.h"


class MENU {
private:
	int equip_arr_len = 1, lec_arr_len = 1,
		std_arr_len = 1, s_num = 0,
		e_num = 0, l_num = 0;
	int choice;
	bool cont = true;
	Equipment* Equip_list = new Equipment[equip_arr_len];
	
	Lectures* Lec_list = new Lectures[lec_arr_len];
	Students* Std_list = new Students[]
	
public:
	MENU();
	void Main_menu();
	void add_equipment();
	void add_member();
	void add_lectures();
	void add_students();
	void print_equip_list();
	void print_member_list();
	bool yes_no_option();
};