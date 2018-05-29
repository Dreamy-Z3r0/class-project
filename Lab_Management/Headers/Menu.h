#pragma once
#include"Lib.h"

class MENU {
private:
	bool cont = true;

	std::vector <Lecturer> Lecturer_list;
	std::vector <Student>  Student_list;
	std::vector <Equipment> Equipment_list;
	std::vector <Projects_Courses> Project_Course_List;

public:
	MENU();
	void Main_menu();
	void Student_Menu();
	void Lecture_Menu();
	void Equipment_Menu();
	void Courses_Project_Menu();
/************************************************************************
*******************STUDENT AND LECTURER FUNCTIONS************************
************************************************************************/
	
	template <class T>
	void add_member(std::vector<T>& Mem_list);

	template<class T>
	void find_member(std::vector<T>& Mem_list);
	template<class T>
	void remove_member(std::vector<T>& Mem_list);
	template<class T>
	void change_member_info(std::vector<T>& Mem_list);
	template <class T>
	std::size_t return_opponent_index(std::vector<T>& list, bool &found);

/************************************************************************
*******************EQUIPMENT, PROJECT AND COURSES FUNCTIONS**************
************************************************************************/


	void add_equipment();
	template <class T>
	void check_out(std::vector<T>& Mem_list);
	template <class T>
	void return_equip(std::vector<T>& Mem_list);

	void add_project_course();
	void project_course_status_change();
	void project_course_enrollment();



/************************************************************************
*******************BASIC MENU FUNCTIONS**********************************
************************************************************************/
	bool yes_no_option();
	void clear_screen();


	template <class T>
	void print_vector_list(std::vector<T>& list);
	template <class T>
	void save_file(std::string file_name,  std::vector<T>& Mem_list);
	template <class T>
	void load_file(std::string file_name, std::vector<T>& Mem_list);
};