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
	

	std::vector<Lectures> Lec_list;
	std::vector<Students> Stu_list;

	
public:
	MENU();
	void Main_menu();
	void add_equipment();
	template <class T> 
	void add_member(std::vector<T>& Mem_list);
	void print_equip_list();
	template <class T>
	void print_member_list(const std::vector<T>& Mem_list);
	bool yes_no_option();
};