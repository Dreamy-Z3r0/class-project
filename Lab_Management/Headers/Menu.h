#pragma once
#include"Lib.h"

class MENU {
private:
	bool cont = true;
	std::size_t lec_index;
	std::size_t stu_index;

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
	template <class T>
	void print_member_list(std::vector<T>& Mem_list);
	template<class T>
	void find_member(std::vector<T>& Mem_list);
	template<class T>
	void remove_member(std::vector<T>& Mem_list);
	template<class T>
	void change_member_info(std::vector<T>& Mem_list);
	template <class T>
	std::size_t return_mem_index(std::vector<T>& Mem_list, bool &found);

/************************************************************************
*******************EQUIPMENT, PROJECT AND COURSES FUNCTIONS**************
************************************************************************/


	void add_equipment();
	void add_course_project();
	void print_equipment_info();
	void print_project_course_info();
	template <class T>
	std::size_t return_obj_index(std::vector<T>& Obj_list, bool &found);
	template <class T>
	void check_out(std::vector<T>& Mem_list);
	template <class T>
	void return_equip(std::vector<T>& Mem_list);
	void project_course_status_change();



/************************************************************************
*******************BASIC MENU FUNCTIONS**********************************
************************************************************************/
	bool yes_no_option();




	template <class T>
	void save_file(std::string file_name,  std::vector<T>& Mem_list);
	template <class T>
	void load_file(std::string file_name, std::vector<T>& Mem_list);
};