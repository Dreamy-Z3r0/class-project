#include"../Headers/Menu.h"

MENU::MENU()
{

}

void MENU::Main_menu()
{
Main_Screen:
	cont = true;
	std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
	std::cout << "\tMenu" << std::endl;
	std::cout << "1: Students" << std::endl;
	std::cout << "2: Lectures" << std::endl;
	std::cout << "2: Lab Equipment" << std::endl;
	std::cout << "3: Courses/Project" << std::endl;
	std::cout << "4: Print Info" << std::endl;
	std::cout << "Enter your choice [1-4]" << std::endl;
	std::cin >> this->choice;
	
	switch (this->choice)
	{
		
	case 1:
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
		break;
	}
	case 2:
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
		break;
	}
	case 3: 
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
		switch (sub_choice)
		{
		case 1: {break; }
		case 2: {break; }
		case 3: {break; }
		case 4: {break; }
		case 5: {break; }
		default: {}
		}
		break;
	}
	case 4:
	{
		int sub_choice;
		std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
		std::cout << "Submenu: Project/Courses" << std::endl;
		std::cout << "1: Available Courses/Project" << std::endl;
		std::cout << "2: New Course/Project" << std::endl;
		std::cout << "Enter your choice [1 or 2]" << std::endl;
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
			switch (sub_choice)
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
		break;
	}
	case 5:
	{
		std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
		std::cout << "A student project for the final exam" << std::endl;
		goto Main_Screen;
		break;
	}
	default:
		std::cout << "Invalid Choice!" << std::endl;
		goto Main_Screen;
	}
	
}


void MENU::add_equipment()
{
	std::string label, model;
	int number;
	float price;
	//while (end != 'y')
	while (cont)
	{
		if (e_num >= equip_arr_len)
		{
			Equipment *e_temp = new Equipment[equip_arr_len + 1];
			for (int i = 0; i < equip_arr_len; i++)
			{
				e_temp[i] = Equip_list[i];
			}
			equip_arr_len++;
			delete[] Equip_list;
			Equip_list = e_temp; // Copy the address of the temp array to Equip_list
		}
		std::cout << "Enter the equipment name" << std::endl;
		std::cin >> label;
		std::cout << "Enter the equipment model" << std::endl;
		std::cin >> model;
		std::cout << "Enter the number of the book" << std::endl;
		std::cin >> number;
		std::cout << "Enter the price of the book" << std::endl;
		std::cin >> price;
		std::cout << "Debug e_num before" << e_num << " " << equip_arr_len << std::endl;
		//Equip_list[e_num].add_equipment(label, model, number, price);
		e_num++;
		std::cout << "Debug e_num after" << e_num << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		cont = this->yes_no_option();
	}
	this->Main_menu();
}



template <class T>
void MENU::add_member(std::vector<T>& Mem_list)
{
	std::string name, email;
	std::string phonenumber, ID_number;
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
	this->Main_menu();
}

void MENU::print_equip_list()
{
	if (this->e_num == 0)
	{
		std::cout << "The Equipment list is currently empty" << std::endl;
		input_case:
		std::cout << "Do you want to add some? [Y/N]" << std::endl;
		cont = this->yes_no_option();
		if (cont) this->add_equipment();
		else this->Main_menu();
	}
	else {
		std::cout << "Equipment list " << std::endl;
		std::cout << "No\t\t" << "Label\t\t" << "Model\t\t" << "Number\t\t" << "Price Per Unit" << std::endl;
		for (int i = 0; i < e_num; i++) {
			std::cout << i+1 << "\t\t";
			Equip_list[i].print_equip_info();
		}
		std::cout << "press 'y' to go back to the main menu" << std::endl;
		cont = this->yes_no_option();
		if (cont) this->Main_menu();

	}
}

template <class T>
void MENU::print_member_list(const std::vector<T>& Mem_list)
{	
	unsigned int size = Mem_list.size();
	std::cout << "Debug " << size << std::endl;
	if (size == 0)
	{
		std::cout << "The Member list is currently empty" << std::endl;
		std::cout << "Do you want to add some? [y/n]" << std::endl;
		cont = this->yes_no_option();
		if (cont) this->add_member<Lectures>(Lec_list);
		else this->Main_menu();
	}
	else {
		std::cout << "Member list " << std::endl;
		std::cout << "No\t" << "Name\t\t\t" << "age\t\t\t" << "phonenumber\t\t\t" << "ID number" << std::endl;
		for (unsigned int i = 0; i < size; i++) {
			std::cout << i + 1 << "\t";
			Mem_list[i].print_info();
		}
		std::cout << "press 'y' to go back to the main menu" << std::endl;
		cont = this->yes_no_option();
		if (cont) this->Main_menu();
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