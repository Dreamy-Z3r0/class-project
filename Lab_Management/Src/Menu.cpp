#include"../Headers/Menu.h"

MENU::MENU()
{

}

void MENU::Main_menu()
{
Main_Screen:
	int choice;
	this->cont = true;
	std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
	std::cout << "\tMenu" << std::endl;
	std::cout << "1: Students" << std::endl;
	std::cout << "2: Lectures" << std::endl;
	std::cout << "3: Lab Equipment" << std::endl;
	std::cout << "4: Courses/Project" << std::endl;
	std::cout << "Enter your choice [1-4]" << std::endl;

	std::cin >> choice;

	switch (choice)
	{

	case 1: {
		this->Student_Menu();
		break;
	}
	case 2:
	{
		this->Lecture_Menu();
		break;
	}
	case 3:
	{
		this->Equipment_Menu();
		break;
	}
	case 4:
	{
		this->Courses_Project_Menu();
		break;
	}
	default:
	{
		std::cout << "Invalid Choice!" << std::endl;
		goto Main_Screen;
	}
	}
}

void MENU::Student_Menu()
{
	this->cont = true;
	int sub_choice;
	std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
	std::cout << "Submenu: Students" << std::endl;
	std::cout << "1: Add Students" << std::endl;
	std::cout << "2: Change Student Info" << std::endl;
	std::cout << "3: Print Student List" << std::endl;
	std::cout << "4: Find Student" << std::endl;
	std::cout << "5: Remove Student info" << std::endl;
	std::cout << "6: Back" << std::endl;
	std::cout << "Enter your choice [1-6]" << std::endl;
	std::cin >> sub_choice;
	switch (sub_choice)
	{
	case 1: {
		this->add_member<Student>(Student_list);
		this->Student_Menu();
		break;
	}
	case 2: {
		this->change_member_info<Student>(Student_list);
		this->Student_Menu();
		break; }
	case 3: {
		this->print_member_list<Student>(Student_list);
		this->Student_Menu();
		break;
	}
	case 4: {
		this->find_member<Student>(Student_list);
		this->Student_Menu();
		break; }
	case 5: {
		this->remove_member<Student>(Student_list);
		this->Student_Menu();
		break; }
	case 6: {
		this->Main_menu();
		break; }
	default: {}
	}
}

void MENU::Lecture_Menu()
{
	this->cont = true;
	int sub_choice;
	std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
	std::cout << "Submenu: Lecturers" << std::endl;
	std::cout << "1: Add new Lecturer" << std::endl;
	std::cout << "2: Change Lecturer Info" << std::endl;
	std::cout << "3: Print Lecturer List" << std::endl;
	std::cout << "4: Find Lecturer" << std::endl;
	std::cout << "5: Remove Lecturer info" << std::endl;
	std::cout << "6: Print Lecturer List" << std::endl;
	std::cout << "7: Find Lecturer" << std::endl;
	std::cout << "8: Remove Lecturer info" << std::endl;
	std::cout << "9: Back" << std::endl;
	std::cout << "Enter your choice [1-6]" << std::endl;
	std::cin >> sub_choice;
	switch (sub_choice)
	{
	case 1: {
		this->add_member<Lecturer>(Lecturer_list);
		break;
	}
	case 2: {
		this->change_member_info<Lecturer>(Lecturer_list);
		this->Student_Menu();
		break; }
	case 3: {
		this->print_member_list<Lecturer>(Lecturer_list);
		break;
	}
	case 4: {
		this->find_member<Lecturer>(Lecturer_list);
		this->Student_Menu();
		break; }
	case 5: {
		this->remove_member<Lecturer>(Lecturer_list);
		this->Student_Menu();
		break; }
	case 6: {break; }
	default: {}
	}
}

void MENU::Equipment_Menu()
{
	this->cont = true;
	int sub_choice;
	std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
	std::cout << "Submenu: Lab Equipment" << std::endl;
	std::cout << "1: In-lab Equipment" << std::endl;
	std::cout << "2: Add Equipment" << std::endl;
	std::cout << "3: Check-out" << std::endl;
	std::cout << "4: Return" << std::endl;
	std::cout << "5: Back" << std::endl;
	std::cout << "Enter your choice [1-5]" << std::endl;
	std::cin >> sub_choice;
	switch (sub_choice)
	{
	case 1: {break; }
	case 2: {break; }
	case 3: {break; }
	case 4: {break; }
	case 5: {break; }
	default: {}
	}
}

void MENU::Courses_Project_Menu()
{
	this->cont = true;
	int sub_choice;
	std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
	std::cout << "Submenu: Project/Courses" << std::endl;
	std::cout << "1: Available Courses/Project" << std::endl;
	std::cout << "2: New Course/Project" << std::endl;
	std::cout << "Enter your choice [1 or 2]" << std::endl;
	std::cin >> sub_choice;
	switch (sub_choice)
	{
	case 1:
	{
		int sub_sub_choice;
		std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
		std::cout << "Submenu: Project/Courses" << std::endl;
		std::cout << "1: Enrollment" << std::endl;
		std::cout << "2: Change Status" << std::endl;
		std::cout << "3: Delete" << std::endl;
		std::cout << "Enter your choice [1-3]" << std::endl;
		std::cin >> sub_sub_choice;
		switch (sub_sub_choice)
		{
		case 1: {break; }
		case 2: {break; }
		case 3: {break; }
		default: {}
				 break;
		}
	case 2: {break; }
	default: {}
	}
	}
}


template <class T>
void MENU::add_member(std::vector<T>& Mem_list)
{
	char name[50], email[50];
	char phonenumber[10], ID_number[10];
	while (cont) {
		std::cout << "Enter the name" << std::endl;
		std::cin >> name;
		std::cout << "Enter the email" << std::endl;
		std::cin >> email;
		std::cout << "Enter the phone number" << std::endl;
		std::cin >> phonenumber;
		std::cout << "Enter the ID number" << std::endl;
		std::cin >> ID_number;
		T newmember(name, email, phonenumber, ID_number);
		Mem_list.push_back(newmember);
		std::cout << "Debug " << Mem_list.size() << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		cont = this->yes_no_option();
	}
	/*
	if (std::is_same<T, Student>::value) this->Student_Menu();
	else this->Lecture_Menu();
	*/
}






template <class T>
void MENU::print_member_list(const std::vector<T>& Mem_list)
{
	std::size_t size = Mem_list.size();
	std::cout << "The list " << std::endl;
	std::cout << "No\t" << "Name\t\t\t" << "age\t\t\t" << "phonenumber\t\t\t" << "ID number" << std::endl;
	for (unsigned int i = 0; i < size; i++) {
		std::cout << i + 1 << "\t";
		Mem_list[i].print_info();
	}
	std::cout << "press 'y' to go back" << std::endl;
	this->cont = this->yes_no_option();
	if (this->cont)
	{
		if (std::is_same<T, Student>::value) this->Student_Menu();
		else this->Lecture_Menu();
	}
}

template<class T>
std::size_t MENU::return_index(std::vector<T>& Mem_list, bool &found)
{
	std::string ID_num;
	std::size_t found_index = 0;
	std::size_t size = Mem_list.size();
	std::cout << "Enter the ID number" << std::endl;
	std::cin >> ID_num;
	for (std::size_t i = 0; i < size; i++)
	{
		std::cout << "Mem_list value" << Mem_list[i].get_IDnumber() << std::endl;
		std::cout << "Input ID" << ID_num << std::endl;
		if (ID_num == Mem_list[i].get_IDnumber())
		{
			found_index = i;

			found = true;
		}
	}
	std::cout << "Index value " << found_index << std::endl;
	return found_index;
}


bool MENU::yes_no_option()
{
	char a = ' ';
	std::cin >> a;
	if (a == 'y') return true;
	else if (a == 'n') return false;
	else {
		std::cout << "Invalid Input" << std::endl;
		this->yes_no_option();
	}
}


template<class T>
void MENU::change_member_info(std::vector<T>& Mem_list)
{

	char c_input[50];
	char n_input[10];
	while (this->cont) {
		bool found = false;
		std::size_t index = this->return_index<T>(Mem_list, found);
		if (found)
		{
			bool sub_cont = true;
			while (sub_cont) {
				int choice;
				Student_list[index].print_info();
				std::cout << "What do you want to change?" << std::endl;
				std::cout << "Enter [1] Name, [2] Email, [3] Telephone Number [4] ID Number" << std::endl;
				std::cin >> choice;
				if (choice == 1) {
					std::cout << "Enter the name" << std::endl;
					std::cin >> c_input;
					Student_list[index].set_name(c_input);
				}
				else if (choice == 2)
				{
					std::cout << "Enter the Email" << std::endl;
					std::cin >> c_input;
					Student_list[index].set_email(c_input);
				}
				else if (choice == 3)
				{
					std::cout << "Enter the Telephone Number" << std::endl;
					std::cin >> n_input;
					Student_list[index].set_phonenumber(n_input);
				}
				else if (choice == 4)
				{
					std::cout << "Enter the ID Number" << std::endl;
					std::cin >> n_input;
					Student_list[index].set_IDnumber(n_input);
				}
				else std::cout << "Invalid Choice!" << std::endl;
				std::cout << "Do you want to change other information? [y/n]" << std::endl;
				sub_cont = this->yes_no_option();
			}
		}
		else std::cout << "No member found" << std::endl;
		std::cout << "Do you want to change other member infomation? [y/n]" << std::endl;
		this->cont = this->yes_no_option();
	}

}

template<class T>
void MENU::find_member(std::vector<T>& Mem_list)
{
	while (this->cont) {
		bool found = false;
		std::size_t index = this->return_index<T>(Mem_list, found);
		if (found) Student_list[index].print_info();
		else std::cout << "No member found" << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		this->cont = this->yes_no_option();
	}
}

template<class T>
void MENU::remove_member(std::vector<T>& Mem_list)
{
	while (this->cont) {
		bool found = false;
		std::size_t index = this->return_index<T>(Mem_list, found);
		if (found)
		{
			bool choice;
			Student_list[index].print_info();
			std::cout << "do you want to delete this student? [y/n]" << std::endl;
			choice = this->yes_no_option();
			if (choice) {
				Student_list.erase(Student_list.begin() + index);
				std::cout << "Student Info is deleted!" << std::endl;
			}
		}
		else std::cout << "No member found" << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		this->cont = this->yes_no_option();
	}
}