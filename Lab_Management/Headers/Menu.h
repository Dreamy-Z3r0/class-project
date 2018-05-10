#pragma once
#include"Lib.h"


class MENU {
private:
	bool cont = true;	

	std::vector <Lecturer> Lecturer_list;
	std::vector <Student>  Student_list;

	
public:
	MENU();
	void Main_menu();
	void Student_Menu();
	void Lecture_Menu();
	void Equipment_Menu();
	void Courses_Project_Menu();
	template <class T> 
	void add_member(std::vector<T>& Mem_list);
	template <class T>
	void print_member_list(const std::vector<T>& Mem_list);
	bool yes_no_option();
};