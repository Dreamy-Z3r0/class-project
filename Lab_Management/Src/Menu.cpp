#include"../Headers/Menu.h"

MENU::MENU()
{

}

void MENU::Main_menu()
{
Main_Screen:
	int choice;
	cont = true;
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
		break;
	}
	case 2: {break; }
	case 3: {
		this->print_member_list<Student>(Student_list);
		break;
	}
	case 4: {break; }
	case 5: {break; }
	case 6: {
		this->Main_menu();
		break; }
	default: {}
	}
}

void MENU::Lecture_Menu()
{
	int sub_choice;
	std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
	std::cout << "Submenu: Lectures" << std::endl;
	std::cout << "1: Add Lectures" << std::endl;
	std::cout << "2: Change Lecture Info" << std::endl;
	std::cout << "3: Print Lecture List" << std::endl;
	std::cout << "4: Find Lecture" << std::endl;
	std::cout << "5: Remove Lecture info" << std::endl;
	std::cout << "6: Back" << std::endl;
	std::cout << "Enter your choice [1-6]" << std::endl;
	std::cin >> sub_choice;
	switch (sub_choice)
	{
	case 1: {break; }
	case 2: {break; }
	case 3: {break; }
	case 4: {break; }
	case 5: {break; }
	case 6: {break; }
	default: {}
	}
}

void MENU::Equipment_Menu()
{
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
	std::string name, email, phonenumber, ID_number;
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
	if (std::is_same<T, Student>::value) this->Student_Menu();
	else this->Lecture_Menu();
}






template <class T>
void MENU::print_member_list(const std::vector<T>& Mem_list)
{	
	unsigned int size = Mem_list.size();
	std::cout << "The list " << std::endl;
	std::cout << "No\t" << "Name\t\t\t" << "age\t\t\t" << "phonenumber\t\t\t" << "ID number" << std::endl;
	for (unsigned int i = 0; i < size; i++) {
		std::cout << i + 1 << "\t";
		Mem_list[i].print_info();
	}
	std::cout << "press 'y' to go back" << std::endl;
	cont = this->yes_no_option();
	if (cont)
	{
		if (std::is_same<T, Student>::value) this->Student_Menu();
		else this->Lecture_Menu();
	}
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