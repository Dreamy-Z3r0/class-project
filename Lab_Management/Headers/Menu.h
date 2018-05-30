#pragma once
#include"Lib.h"

class MENU {
private:
	bool cont = true;

	//Set up vector list to store data for each class
	std::vector <Lecturer> Lecturer_list;
	std::vector <Student>  Student_list;
	std::vector <Equipment> Equipment_list;
	std::vector <Projects_Courses> Project_Course_List;

public:
	//Menu constructor
	MENU();


/********************************************************************************************************************
****************************************** MENU INTERFACE ***********************************************************
********************************************************************************************************************/
	/**
	 *Main Menu interface
	 *@param none
	 *@return void
	 */
	void Main_menu();
	void Student_Menu();
	void Lecture_Menu();
	void Equipment_Menu();
	void Courses_Project_Menu();

/********************************************************************************************************************
****************************************** MENU BASIC OPERATIONS ****************************************************
********************************************************************************************************************/

	
	//Save objects(all kinds) from a vector to a file
	template <class T>
	void save_file(std::string file_name, std::vector<T>& Mem_list);
	//Load objects(all kinds) from a file to a vector
	template <class T>
	void load_file(std::string file_name, std::vector<T>& Mem_list);
	//Print the list of all members(Student and Lecturers)
	template <class T>
	void print_vector_list(std::vector<T>& list);
	//Return a object index in a vector (regardless of class). Required user input
	template <class T>
	std::size_t return_opponent_index(std::vector<T>& list, bool &found);
	//Return a object index in a vector (regardless of class). Does not require user-input
	template<class T>
	std::size_t return_opponent_index(std::vector<T>& Mem_list, char* IDnumber, bool &found);
	//Used for yes no option.Return true when input is 'y' and false when 'n'
	bool yes_no_option();
	//Wait for user-confirmation to proceed, take every kinds of string input and return true
	bool press_any_key();
	//Clear screen
	void clear_screen();


/********************************************************************************************************************
********************************** STUDENT AND LECTURER BASIC FUNCTIONS *********************************************
********************************************************************************************************************/
	
//Add a new member (Student or Lecturer) to vectors
	template <class T>
	void add_member(std::vector<T>& Mem_list);
	//Print a specific member info(Student or Lecturer) based on found index
	template<class T>
	void find_member(std::vector<T>& Mem_list);
	//Update a specific member info (Student or Lecturer) based on found index
	template<class T>
	void change_member_info(std::vector<T>& Mem_list);
	//Remove a specific member info (Student or Lecturer) based on found index
	template<class T>
	void remove_member(std::vector<T>& Mem_list);

/******************************************************************************************************************
********************************* EQUIPMENT, PROJECT AND COURSES FUNCTIONS ****************************************
*******************************************************************************************************************/

	//Add a new equipment
	void add_equipment();
	//Borrow equipment(s).Enter the equipment name and a member(Student or Lecturer) ID number, then check for equipment availability as well as
	//vacancies in member's borrow list. A member can ONLY borrow three equipments. Can choose between Lecturer or Student.
	template <class T>
	void check_out(std::vector<T>& Mem_list);
	//Return equipment(s).Enter the member(Student or Lecturer) ID number and the desired equipment to be returned,
	//*then several conditions are checked before operating.
	template <class T>
	void return_equip(std::vector<T>& Mem_list);
	//Re-activate project if there it has been finished or abandoned
	void re_activate_project(std::size_t index);

	/*Add a new project/course.
	*In order to create one, user has to input a valid Lecturer ID number, of whom will be the project's tutor
	*Each project will have only one tutor, and less than 5 members*/
	void add_project_course();
	//Change the Project Status
	//If the project status is changed to "Finished" or "Abandoned", the project position in both Lecturer and Student list will automatically be removed
	void project_course_status_change();
	//Remove the project from both Student and Lecturer's project list
	void project_finish(std::size_t project_index);
	//Enroll students in the project
	void project_course_enrollment();

};