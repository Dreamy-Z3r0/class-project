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
	std::cout << "1: Add new equipment" << std::endl;
	std::cout << "2: Add new member" << std::endl;
	std::cout << "3: Print Equipment List" << std::endl;
	std::cout << "4: Print Member List" << std::endl;
	std::cout << "Enter your choice [1-7]" << std::endl;
	std::cin >> this->choice;
	std::cout << this->choice;
	
	switch (this->choice)
	{
		std::cout << "choosing" << std::endl;
	case 1:
	{
		std::cout << "debug_case" << std::endl;
		this->add_equipment();
		break;
	}
	case 2:
	{
		this->add_member();
		break;
	}
	case 3: 
	{
		this->print_equip_list();
		break;
	}
	case 4:
	{
		this->print_member_list();
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
		Equip_list[e_num].add_equipment(label, model, number, price);
		e_num++;
		std::cout << "Debug e_num after" << e_num << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		cont = this->yes_no_option();
	}
	this->Main_menu();
}

void MENU::add_member()
{
	std::string name, age, phonenumber, ID_number;
	while (cont) {
		if (m_num >= mem_arr_len)
		{
			Member *m_temp = new Member[mem_arr_len + 1];
			for (int i = 0; i < mem_arr_len; i++)
			{
				m_temp[i] = Mem_list[i];
			}
			mem_arr_len++;
			delete[] Mem_list;
			Mem_list = m_temp; // Copy the address of the temp array to Mem_list
		}
		std::cout << "Enter the name" << std::endl;
		std::cin >> name;
		std::cout << "Enter the age" << std::endl;
		std::cin >> age;
		std::cout << "Enter the phone number" << std::endl;
		std::cin >> phonenumber;
		std::cout << "Enter the ID number" << std::endl;
		std::cin >> ID_number;
		Mem_list[m_num].add_member(name, age, phonenumber, ID_number);
		m_num++;
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


void MENU::print_member_list()
{
	if (this->m_num == 0)
	{
		std::cout << "The Member list is currently empty" << std::endl;
		input_case:
		std::cout << "Do you want to add some? [Y/N]" << std::endl;
		cont = this->yes_no_option();
		if (cont) this->add_equipment();
		else this->Main_menu();
	}
	else {
		std::cout << "Member list " << std::endl;
		std::cout << "No\t" << "Name\t\t\t" << "age\t" << "phonenumber\t\t\t" << "ID number" << std::endl;
		for (int i = 0; i < m_num; i++) {
			std::cout << i + 1 << "\t";
			Mem_list[i].print_member_info();
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