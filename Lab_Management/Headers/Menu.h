#pragma once
#include"Lib.h"

class MENU {
private:
	bool cont = true;
	std::size_t lec_index;
	std::size_t stu_index;

	std::vector <Lecturer> Lecturer_list;
	std::vector <Student>  Student_list;
	
	ifstream student_file;
	
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
	template<class T>
	void find_member(std::vector<T>& Mem_list);
	template<class T>
	void remove_member(std::vector<T>& Mem_list);
	template<class T>
	void change_member_info(std::vector<T>& Mem_list);
	template <class T>
	std::size_t return_index(std::vector<T>& Mem_list, bool &found);
	bool yes_no_option();
};