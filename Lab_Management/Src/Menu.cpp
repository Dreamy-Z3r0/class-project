#include"../Headers/Menu.h"

MENU::MENU()
{
	this->load_file<Student>("Resources/Student_List.dat", Student_list);
	this->load_file<Lecturer>("Resources/Lecturer_List.dat", Lecturer_list);
	this->load_file<Equipment>("Resources/Equipment_List.dat", Equipment_list);
	this->load_file<Projects_Courses>("Resources/Project_Course_List.dat", Project_Course_List);


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
	this->save_file<Student>("Resources/Student_List.dat", Student_list);
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
	this->save_file<Lecturer>("Resources/Lecturer_List.dat", Lecturer_list);
	this->cont = true;
	int sub_choice;
	std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
	std::cout << "Submenu: Lecturers" << std::endl;
	std::cout << "1: Add new Lecturer" << std::endl;
	std::cout << "2: Change Lecturer Info" << std::endl;
	std::cout << "3: Print Lecturer List" << std::endl;
	std::cout << "4: Find Lecturer" << std::endl;
	std::cout << "5: Remove Lecturer info" << std::endl;
	std::cout << "6: Print Lecturer List {temp back}" << std::endl;
	std::cout << "7: Find Lecturer" << std::endl;
	std::cout << "8: Remove Lecturer info" << std::endl;
	std::cout << "9: Back" << std::endl;
	std::cout << "Enter your choice [1-6]" << std::endl;
	std::cin >> sub_choice;
	switch (sub_choice)
	{
	case 1: {
		this->add_member<Lecturer>(Lecturer_list);
		this->Lecture_Menu();
		break;
	}
	case 2: {
		this->change_member_info<Lecturer>(Lecturer_list);
		this->Lecture_Menu();
		break; }
	case 3: {
		this->print_member_list<Lecturer>(Lecturer_list);
		this->Lecture_Menu();

		break;
	}
	case 4: {
		this->find_member<Lecturer>(Lecturer_list);
		this->Lecture_Menu();
		break; }
	case 5: {
		this->remove_member<Lecturer>(Lecturer_list);
		this->Lecture_Menu();
		break; }
	case 6: {
		this->Main_menu();
		break; }
	default: {}
	}
}

void MENU::Equipment_Menu()
{	
	this->save_file<Equipment>("Resources/Equipment_List.dat", Equipment_list);
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
	case 1: {
		this->print_equipment_info();
		this->Equipment_Menu();
		break; }
	case 2: {
		this->add_equipment();
		this->Equipment_Menu();
		break; }
	case 3: {
		this->check_out<Student>(Student_list);
		this->Equipment_Menu();
		break; }
	case 4: {break; }
	case 5: {
		this->Main_menu();
		break; }
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
void MENU::print_member_list(std::vector<T>& Mem_list)
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
std::size_t MENU::return_mem_index(std::vector<T>& Mem_list, bool &found)
{
	std::string ID_num;
	std::size_t found_index = 0;\

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
		std::size_t index = this->return_mem_index<T>(Mem_list, found);
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
		std::size_t index = this->return_mem_index<T>(Mem_list, found);
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
		std::size_t index = this->return_mem_index<T>(Mem_list, found);
		if (found)
		{
			bool choice;
			Student_list[index].print_info();
			std::cout << "do you want to delete this member? [y/n]" << std::endl;
			choice = this->yes_no_option();
			if (choice) {
				Student_list.erase(Student_list.begin() + index);
				std::cout << "Member Info is deleted!" << std::endl;
			}
		}
		else std::cout << "No member found" << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		this->cont = this->yes_no_option();
	}
}


void MENU::add_equipment()
{
	char name[50];
	int quantity;
	while (cont) {
		std::cout << "Enter equipment name" << std::endl;
		std::cin >> name;
		std::cout << "Enter the quantity" << std::endl;
		std::cin >> quantity;
		Equipment new_equip(name, quantity);
		Equipment_list.push_back(new_equip);
		std::cout << "Debug " << Equipment_list.size() << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		cont = this->yes_no_option();
	}
	/*
	if (std::is_same<T, Student>::value) this->Student_Menu();
	else this->Lecture_Menu();
	*/
}


void MENU::print_equipment_info()
{
	std::size_t size = Equipment_list.size();
	std::cout << "The list " << std::endl;
	std::cout << "No: ";
	for (unsigned int i = 0; i < size; i++) {
		std::cout << i + 1 << "\n";
		Equipment_list[i].print_info();
	}
	std::cout << "press 'y' to go back" << std::endl;
	this->cont = this->yes_no_option();
}


template <class T>
std::size_t MENU::return_obj_index(std::vector<T>& Obj_list, bool &found)
{
	char name[50];
	std::size_t found_index = 0;
	std::size_t size = Obj_list.size();
	std::cout << "Enter the name" << std::endl;
	std::cin >> name;
	for (std::size_t i = 0; i < size; i++)
	{
		std::cout << "Obj_list value" << Obj_list[i].get_name() << std::endl;
		std::cout << "Input Name" << name << std::endl;
		if (strcmp(name, Obj_list[i].get_name()) == 0)
		{
			found_index = i;
			std::cout << "found!" << std::endl;
			found = true;
		}
	}
	std::cout << "Index value " << found_index << std::endl;
	return found_index;
}

template<class T>
void MENU::check_out(std::vector<T>& Mem_list)
{
	while (this->cont) {
		bool found = false;
		std::size_t index = this->return_obj_index(Equipment_list, found);
		if (found)
		{
			bool choice;
			Equipment_list[index].print_info();
			std::cout << "do you want to check this Equipment out? [y/n]" << std::endl;
			choice = this->yes_no_option();
			if (choice) {
				bool sub_cont = true;
				while (sub_cont)
				{
					bool sub_found = false;
					std::size_t mem_index = this->return_mem_index<T>(Mem_list, sub_found);
					Equipment_list[index].print_info();
					if (sub_found) {
						char date[5];
						int borrowed = Mem_list[mem_index].occupied_vacancies();
						int vacancy = Mem_list[mem_index].return_vacancy_index();
						std::cout << "The Member Info is: " << std::endl;
						Mem_list[mem_index].print_info();
						if (borrowed >= 3) {
							std::cout << "This student has borrowed more than 3 equipment" << std::endl;
							std::cout << "Return one to borrow another" << std::endl;
							break;
						}
						else {
							int quantity = 0;
							int availability = Equipment_list[index].get_availability();
						availability_check:
											
							std::cout << "How many do you want to borrow? " << std::endl;
							std::cin >> quantity;

							if(quantity  > availability)
							{
								std::cout << "Out of stock!" << std::endl;
								std::cout << "Only " << availability << " remained!" << std::endl;
								std::cout << "Do you want to re-enter the quantity?" << std::endl;
								bool re_enter = this->yes_no_option();
								if (re_enter) goto availability_check;
								else break;
							}
							else if (quantity + borrowed > 3)
							{
								std::cout << "Borrow: " << borrowed << std::endl;
								std::cout << "Borrow and quantity: " << borrowed + quantity << std::endl;
								std::cout << "Your quantity exceeds the limit! (Only 3 Equipment for each Person!) " << std::endl;
								std::cout << "Do you want to re-enter the quantity?" << std::endl;
								bool re_enter = this->yes_no_option();
								if (re_enter) goto availability_check;
								else break;
							}
							else {
								std::cout << "Enter date" << std::endl;
								std::cin >> date;
								std::cout << "Borrow successfully!" << std::endl;
								Mem_list[mem_index].set_borrow_list(Equipment_list[index].get_name(), vacancy, quantity, date);
								Equipment_list[index].availability_change(-quantity);
								break;
							}
						}
					}
					else std::cout << "No Member found! Please enter again!" << std::endl;
				}
			}
			else break;
		}
		else std::cout << "No Equipment found" << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		this->cont = this->yes_no_option();
	}
}



template<class T>
void MENU::return_equip(std::vector<T>& Mem_list)
{
	while (this->cont) {
		bool found = false;
		std::size_t index = this->return_mem_index(Mem_list, found);
		if (found)
		{
			bool choice;
			Mem_list[index].print_info();
			bool sub_cont = true;
			while (sub_cont)
			{
				bool sub_found = false;
				std::size_t equip_index = this->return_obj_index<T>(Equipment_list, sub_found);
				Equipment_list[index].print_info();
				if (sub_found) {

					int vacancy = Mem_list[mem_index].check_vacancy();
					std::cout << "The Member Info is: " << std::endl;
					Mem_list[mem_index].print_info();
					if (vacancy == -1) {
						std::cout << "This student has borrowed more than 3 equipments" << std::endl;
						std::cout << "Return one to borrow another" << std::endl;
						break;
					}
					else {
						std::cout << "Borrow successfully!" << std::endl;
						Mem_list[mem_index].set_borrow_list(Equipment_list[index].get_name(), vacancy);
						break;
					}
				}
				else std::cout << "No member found! Please Enter Again"
			}
			
		}
		else std::cout << "No Equipment found" << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		this->cont = this->yes_no_option();
	}
}





template<class T>
void MENU::save_file(std::string file_name, std::vector<T>& Mem_list)
{
	std::size_t size = Mem_list.size();
	std::fstream file;
	file.open(file_name, std::fstream::in | std::fstream::out |std::fstream::trunc| std::fstream::binary);
	
	if (file.is_open()) {
		file.seekp(0, std::ios::end);
		for (std::size_t i = 0; i < size; i++)
		{
			std::cout << "Check_Save_loop" << std::endl;
			file.seekp(0, std::ios::end);
			file.write((char*)&Mem_list[i], sizeof(T));
		}
		file.close();
	}
	else std::cout << "Error Opening the file" << std::endl;
}

template<class T>
void MENU::load_file(std::string file_name, std::vector<T>& Mem_list)
{	
	T check;
	std::cout << "size of a class" << sizeof(T) << std::endl;
	std::size_t size = Mem_list.size();
	std::fstream file;
	file.open(file_name, std::fstream::in | std::fstream::out | std::fstream::binary);
	
	if (file.is_open()) {
		
		file.seekg(0, std::ios::end);     //move to the end of the file
		std::streamoff end_point = file.tellg();		  // The position of pointer
		std::cout << "The pointer at the end " << end_point << std::endl;
		std::streamoff size_of_file = end_point / sizeof(T);
		file.seekg(0, std::ios::beg);     //move to the beg of the file
		std::cout << "There are " << size_of_file << " (s) in this database ";
		
		std::streamoff fl_sz = file.tellg();
		std::cout << "The pointer is firstly " << fl_sz << std::endl;
		//while(!file.eof())
		//while(file.getline(check,10))
		//while (file.read((char*)&Mem_list, sizeof(T)));
		for(std::streamoff i = 0; i < size_of_file; i++)
		{
			std::streamoff fl_sz = file.tellg();
			std::cout << "The pointer is" << fl_sz << std::endl;
			file.read((char*)&check, sizeof(T));
			Mem_list.push_back(check);
			Mem_list[i].print_info();
		}
	}
	else std::cout << "Error Opening the file" << std::endl;
}