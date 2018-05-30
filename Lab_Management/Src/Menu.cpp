#include"../Headers/Menu.h"



/********************************************************************************************************************
****************************************** MENU CONSTRUCTOR *********************************************************
********************************************************************************************************************/


/**
 *Initialize class MENU and load data from files to different vectors
 *@param none
 */

MENU::MENU()
{
	
	this->load_file<Student>("Resources/Student_List.dat", Student_list);
	this->load_file<Lecturer>("Resources/Lecturer_List.dat", Lecturer_list);
	this->load_file<Equipment>("Resources/Equipment_List.dat", Equipment_list);
	this->load_file<Projects_Courses>("Resources/Project_Course_List.dat", Project_Course_List);

}




/********************************************************************************************************************
****************************************** MENU INTERFACE ***********************************************************
********************************************************************************************************************/


void MENU::Main_menu()
{
Main_Screen:
	//Variables declaration
	int choice;
	this->cont = true;
	
	//Clear everything left on the screen
	this->clear_screen();
	
	//Main Menu screen
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
		this->clear_screen();
		this->Student_Menu(); //Go to Sub-menu: Student Menu
	}
	case 2:
	{	
		this->clear_screen();
		this->Lecture_Menu();//Go to Sub-menu: Lecturer Menu
	}
	case 3:
	{	
		this->clear_screen();
		this->Equipment_Menu();//Go to Sub-menu: Equipment Menu
	}
	case 4:
	{
		this->clear_screen();
		this->Courses_Project_Menu();//Go to Sub-menu: Course and project menu
	}
	default:
	{	
		//Go back to the main Menu if user enters invalid input 
		std::cout << "Invalid Choice!" << std::endl; 
		goto Main_Screen; 
	}
	}
}


void MENU::Student_Menu()
{
	int sub_choice;
	do {
		//Variable declaration
		this->cont = true;

		//Save data in file
		this->save_file<Student>("Resources/Student_List.dat", Student_list);
	
		//Student Menu Interface
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
			this->add_member<Student>(Student_list);			// Add a new Student to the Student List
			break;
		}
		case 2: {
			this->change_member_info<Student>(Student_list);	// Change Student Infomation
			break; }
		case 3: {
			this->print_vector_list<Student>(Student_list);		// Print Student List
			break;
		}
		case 4: {
			this->find_member<Student>(Student_list);			// Find a Student
			break; }
		case 5: {
			this->remove_member<Student>(Student_list);			// Remove a Student
			break; }
		case 6: {												// Go Back to Main menu
			break; }
		default: {	std::cout << "Bad Input" << std::endl; }
		}
		this->clear_screen();
	} while (sub_choice != 6);	//Check if the user wants to go back the main menu 
	this->Main_menu();	//Go back to the main menu
}



void MENU::Lecture_Menu()
{
	int sub_choice;
	do {
		//Variable Declaration
		this->cont = true;
		//Save data in file
		this->save_file<Lecturer>("Resources/Lecturer_List.dat", Lecturer_list);
		std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
		std::cout << "Submenu: Lecturers" << std::endl;
		std::cout << "1: Add new Lecturer" << std::endl;
		std::cout << "2: Change Lecturer Info" << std::endl;
		std::cout << "3: Print Lecturer List" << std::endl;
		std::cout << "4: Find Lecturer" << std::endl;
		std::cout << "5: Remove Lecturer info" << std::endl;
		std::cout << "6: Back" << std::endl;
		std::cout << "Enter your choice [1-6]" << std::endl;
		std::cin >> sub_choice;
		switch (sub_choice)
		{
		case 1: {
			this->clear_screen();
			this->add_member<Lecturer>(Lecturer_list);				// Add a new Lecturer
			break;
		}
		case 2: {
			this->clear_screen();
			this->change_member_info<Lecturer>(Lecturer_list);		// Change a lecturer Information
			break; }
		case 3: {
			this->clear_screen();
			this->print_vector_list<Lecturer>(Lecturer_list);		// Print the Lecturer List 
			break;
		}
		case 4: {
			this->clear_screen();
			this->find_member<Lecturer>(Lecturer_list);				// Find a Lecturer
			break; }
		case 5: {
			this->clear_screen();
			this->remove_member<Lecturer>(Lecturer_list);			// Remove a Lecturer
			break; }
		case 6: {
			break;													// Back to Main Menu
		}
		default: {}
		}
		this->clear_screen();
	} while (sub_choice != 6);	//Check if the user wants to go back the main menu 
	this->Main_menu();	//Go back to the main menu
}


void MENU::Equipment_Menu()
{	
	int sub_choice;
	do {
		//Variable Declaration
		this->cont = true;
		//Save data to files
		this->save_file<Equipment>("Resources/Equipment_List.dat", Equipment_list);

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
			this->clear_screen();
			this->print_vector_list<Equipment>(Equipment_list);				//Print all the In-lab Equipment
			break; }
		case 2: {
			this->clear_screen();
			this->add_equipment();											//Add a new Equipment
			break; }
		case 3: {
			this->clear_screen();
			int check_out_choice;
			std::cout << "Identify yourself, are you a: [1] Student, [2] Lecturer ? " << std::endl;	// Check if the borrower is a Student or Lecturer
			std::cin >> check_out_choice;
			switch (check_out_choice)
			{
			case 1: {
				this->clear_screen();
				this->check_out<Student>(Student_list);						//Check out an equipment (Student)
				break;			
			}
			case 2:
			{
				this->clear_screen();
				this->check_out<Lecturer>(Lecturer_list);					//Check out an equipment (Lecturer)
				break;
			}
			default: {}
			}
			break; }
		case 4: {
			this->clear_screen();
			int check_out_choice;
			std::cout << "Identify yourself, are you a: [1] Student, [2] Lecturer ? " << std::endl; // Check if the borrower is a Student or Lecturer
			std::cin >> check_out_choice;
			switch (check_out_choice)
			{
			case 1: {
				this->clear_screen();
				this->return_equip<Student>(Student_list);					//Return an equipment (Student)
				break;
			}
			case 2:
			{
				this->clear_screen();
				this->return_equip<Lecturer>(Lecturer_list);				//Return an equipment (Lecturer)
				break;
			}
			default: {}
			}
			break; }
		case 5: {
			break;															//Go back to main menu
		}
		default: {}
		}
		this->clear_screen();
	} while (sub_choice != 5);	//Check if the user wants to go back the main menu 
	this->Main_menu();	//Go back to the main menu
}


void MENU::Courses_Project_Menu()
{	
	int sub_choice;
	do {
		//Varaible Declaration
		this->cont = true;
		//Save data to the file
		this->save_file<Projects_Courses>("Resources/Project_Course_List.dat", Project_Course_List);
		//Menu Interface
		std::cout << "LAB MANAGEMENT SYSTEM" << std::endl;
		std::cout << "Submenu: Project/Courses" << std::endl;
		std::cout << "1: Available Courses/Project" << std::endl;
		std::cout << "2: Add a New Course/Project" << std::endl;
		std::cout << "3: Course/Project Enrollment" << std::endl;
		std::cout << "4: Project Status Update" << std::endl;
		std::cout << "5: Back" << std::endl;

		std::cout << "Enter your choice [1 or 2]" << std::endl;
		std::cin >> sub_choice;
		switch (sub_choice)
		{
		case 1:
		{
			this->clear_screen();
			this->print_vector_list<Projects_Courses>(Project_Course_List);				//Print all the Projects/Courses
			break;
		}
		case 2: {
			this->clear_screen();
			this->add_project_course();													//Add a new course
			break; }
		case 3: {
			this->clear_screen();
			this->project_course_enrollment();											//Student enrollment for the Project/Course
			break;
		}
		case 4:
		{
			this->clear_screen();
			this->project_course_status_change();										//Update the Project/Course status
			break;
		}
		case 5:
		{
			break;																		//Return to the main menu
		}

		default: {}
		}
		this->clear_screen();
	} while (sub_choice != 5);	//Check if the user wants to go back the main menu 
	this->Main_menu();	//Go back to the main menu
}





/********************************************************************************************************************
****************************************** MENU BASIC OPERATIONS ****************************************************
********************************************************************************************************************/

template<class T>
void MENU::save_file(std::string file_name, std::vector<T>& Mem_list)
{
	//Store the size of a vector into a variable 
	std::size_t size = Mem_list.size(); 
	//Create an object of fstream
	std::fstream file;	
	/*Open the file with the following modes:
		+ in (input):	open the file for reading purpose
		+ out (Output):	open the file for writing purpose
		+ trunc(truncate): delete all the content of the file before writing new one
		+ binary: write data in binary mode
	*/
	file.open(file_name, std::fstream::in | std::fstream::out | std::fstream::trunc | std::fstream::binary);
	//Check if the file is opened successfully 
	if (file.is_open()) {
		//Set the pointer to the end of stream to write new data
		file.seekp(0, std::ios::end);
		for (std::size_t i = 0; i < size; i++)
		{
			//Move the pointer to the end of stream to write data
			file.seekp(0, std::ios::end);
			//Write all elements of the given vector to the file, with the size of the accroding class
			file.write((char*)&Mem_list[i], sizeof(T));
		}
		file.close();
	}
	else std::cout << "Error Opening the file" << std::endl; 
}



template<class T>
void MENU::load_file(std::string file_name, std::vector<T>& Mem_list)
{
	//Create a temp object with class T
	T check;
	//Store the size of the vector to a variable
	std::size_t size = Mem_list.size();
	//Create an instance of fstream
	std::fstream file;
	/*Open the file with the following modes:
	+ in (input):	open the file for reading purpose
	+ out (Output):	open the file for writing purpose
	+ binary: write data in binary mode
	*/
	file.open(file_name, std::fstream::in | std::fstream::out | std::fstream::binary);
	//Check if the file is opened successfully
	if (file.is_open()) {

		file.seekg(0, std::ios::end);	//move the pointer to the end of the file to get data
		std::streamoff end_point = file.tellg();	// Return the position of pointer
														  
		std::streamoff size_of_file = end_point / sizeof(T);	//Return the number of element with size of class T in the file
		file.seekg(0, std::ios::beg);     //move back to the beginning of the file

		for (std::streamoff i = 0; i < size_of_file; i++)
		{
			file.read((char*)&check, sizeof(T)); //Store the read data to a same type object, named "check" in this case.
			Mem_list.push_back(check);			// Add the object to the vector
		}
		std::cout << "Receiving data..." << std::endl;
		//Sleep for one second 
		std::this_thread::sleep_for(std::chrono::seconds(1));
		
	}
	else std::cout << "Error Opening the file" << std::endl;
}


template <class T>
void MENU::print_vector_list(std::vector<T>& list)
{
	//Print different with different type of class
	if (std::is_same<T, Student>::value) std::cout << "The Student List: " << std::endl;
	else if (std::is_same<T, Lecturer>::value) std::cout << "The Lecturer List: " << std::endl;
	else if (std::is_same<T, Equipment>::value) std::cout << "The Equipment List: " << std::endl;
	else std::cout << "The Project/Course List: " << std::endl;
	//Get the vector size
	std::size_t size = list.size();
	std::cout << "The list " << std::endl;
	//print out all the element in the vector
	for (std::size_t i = 0; i < size; i++) {
		std::cout << "No: " << i + 1 << std::endl;
		list[i].print_info();
	}
	this->press_any_key();
}


template<class T>
std::size_t MENU::return_opponent_index(std::vector<T>& list, bool &found)
{
	//Variable Declaration
	char ID_num[20];
	std::size_t found_index = 0;
	std::size_t size = list.size();
	//Print different content based on the class type
	if (std::is_same<T, Student>::value) std::cout << "Please Enter the Student ID Number: " << std::endl;
	else if (std::is_same<T, Lecturer>::value) std::cout << "Please Enter the Lecturer ID Number: " << std::endl;
	else if (std::is_same<T, Equipment>::value) std::cout << "Please Enter the Equipment ID Number: " << std::endl;
	else std::cout << "Please Enter the Project/Course ID Number " << std::endl;
	//Use input
	std::cin >> ID_num;
	for (std::size_t i = 0; i < size; i++)	//Scan all the list
	{
		if (strcmp(ID_num, list[i].get_IDnumber()) == 0) //Compare the two ID numbers
		{
			found = true;					//Return true if the member is found
			return found_index = i;			//Return Member index in the list
		}	
	}
	return 0;
}



template<class T>
std::size_t MENU::return_opponent_index(std::vector<T>& Mem_list, char* IDnumber, bool &found)
{	

	std::size_t size = Mem_list.size();
	for (std::size_t i = 0; i < size; i++) // Scan all the list
	{
		if (strcmp(Mem_list[i].get_IDnumber(), IDnumber) == 0) //Compare the two ID numbers
		{
			found = true;	//If found, return true
			return i;		//Return member index in the list
		}
	}
	return 0;
}


bool MENU::yes_no_option()
{	
	//Create a string variable
	std::string a;
	std::cin >> a;
	if (a == "y") return true;			
	else if (a == "n") return false;	
	else {
		std::cout << "Invalid Input" << std::endl;
		this->yes_no_option();
	}
}


bool MENU::press_any_key()
{
	std::string a;
	std::cout << "Press any key to go back" << std::endl;
	std::cin >> a;
	return true;
}

void MENU::clear_screen()
{
#ifdef _WIN32
	system("CLS");
#else
	std::cout << "\033[2J\033[1;1H";
#endif

}



/********************************************************************************************************************
****************************************** STUDENT AND LECTURER BASIC FUNCTIONS *************************************
********************************************************************************************************************/


template <class T>
void MENU::add_member(std::vector<T>& Mem_list)
{
	//Variable declaration
	char name[50], email[50];
	char phonenumber[20], ID_number[10];
	this->clear_screen();

	while (cont) {
		this->clear_screen();
		//Input all the basic info
		std::cout << "Enter the name" << std::endl;
		std::cin.get();	//Enter sucks in the input buffer until it encounters another input statement. So use cin.get() to get risk of it.
		std::cin.getline(name, 50);		
		std::cout << "Enter the email" << std::endl;
		std::cin.getline(email, 50);
		std::cout << "Enter the phone number" << std::endl;
		std::cin.getline(phonenumber, 20);
		std::cout << "Enter the ID number" << std::endl;
		std::cin.getline(ID_number, 10);
		//Create a T-typed instance (Lecture or Student)
		T newmember(name, email, phonenumber, ID_number);
		Mem_list.push_back(newmember);
		std::cout << "Do you want to continue adding another Member? [y/n]" << std::endl;
		cont = this->yes_no_option();	//Check if the useer wants to continue adding more students
	}
}


template<class T>
void MENU::find_member(std::vector<T>& Mem_list)
{	
	this->clear_screen();
	while (this->cont) {
		this->clear_screen();
		bool found = false;
		std::size_t index = this->return_opponent_index<T>(Mem_list, found);	//Return the member index in vector
		if (found) Student_list[index].print_info();	//If the member is found, return its index
		else std::cout << "No member found" << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		this->cont = this->yes_no_option();
	}
}

template<class T>
void MENU::change_member_info(std::vector<T>& Mem_list)
{
	//Variable declaration
	char c_input[50];
	char tele_input[20];
	char n_input[10];
	this->clear_screen();
	while (this->cont) {
		this->clear_screen();
		bool found = false;
		std::size_t index = this->return_opponent_index<T>(Mem_list, found); //Find the member and return the member index
		if (found)	//If the member is found, proceed to the next menu
		{
			bool sub_cont = true;
			while (sub_cont) {
				int choice;
				Mem_list[index].print_info();
				//Sub menu interface
				std::cout << "What do you want to change?" << std::endl;
				std::cout << "Enter [1] Name, [2] Email, [3] Telephone Number [4] ID Number" << std::endl;
				//Options to change member specific info
				std::cin >> choice;
				if (choice == 1) {
					std::cout << "Enter the name" << std::endl;
					std::cin.get();
					std::cin.getline(c_input,50);
					Mem_list[index].set_name(c_input);		//Update name
				}
				else if (choice == 2)
				{
					std::cout << "Enter the Email" << std::endl;
					std::cin.get();
					std::cin.getline(c_input, 50);
					Mem_list[index].set_email(c_input);		//Update email
				}
				else if (choice == 3)
				{
					std::cout << "Enter the Telephone Number" << std::endl;
					std::cin.get();
					std::cin.getline(tele_input, 20);
					Mem_list[index].set_phonenumber(tele_input);	//Update telephone number
				}
				else if (choice == 4)
				{
					std::cout << "Enter the ID Number" << std::endl;
					std::cin.get();
					std::cin.getline(tele_input, 10);
					Mem_list[index].set_IDnumber(n_input);		//Update ID number
				}
				else std::cout << "Invalid Choice!" << std::endl;
				std::cout << "Do you want to change other information? [y/n]" << std::endl; // User input to decide whether to continue or not
				sub_cont = this->yes_no_option();
			}
		}
		else std::cout << "No member found" << std::endl;
		std::cout << "Do you want to change other member infomation? [y/n]" << std::endl;
		this->cont = this->yes_no_option();
	}
}


template<class T>
void MENU::remove_member(std::vector<T>& Mem_list)
{
	this->clear_screen();
	while (this->cont) {
		bool found = false;
		std::size_t index = this->return_opponent_index<T>(Mem_list, found); //Find the member and return the member index
		if (found) //If the member is found
		{
			bool choice;
			Mem_list[index].print_info();
			std::cout << "do you want to delete this member? [y/n]" << std::endl;
			choice = this->yes_no_option();
			if (choice) {
				Mem_list.erase(Mem_list.begin() + index); //Delete the index_th object in vector
				std::cout << "Member Info is deleted!" << std::endl;
			}
		}
		else std::cout << "No member found" << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		this->cont = this->yes_no_option();
	}
}


/********************************************************************************************************************
****************************************** EQUIPMENT BASIC FUNCTIONS ************************************************
********************************************************************************************************************/


void MENU::add_equipment()
{	
	//Variable declaration
	char name[50], ID_number[10];
	int quantity;
	this->clear_screen();
	while (cont) {
		//Get the user input
		std::cout << "Enter equipment name" << std::endl;
		std::cin.get();
		std::cin.getline(name, 50);
		std::cout << "Enter equipment ID_Number" << std::endl;
		std::cin >> ID_number;
		std::cout << "Enter the quantity" << std::endl;
		std::cin >> quantity;
		//Create an instance of Equipment
		Equipment new_equip(name, ID_number, quantity);
		//Add the instance to the end of the vector
		Equipment_list.push_back(new_equip);
		std::cout << "Do you want to continue adding a new equipment? [y/n]" << std::endl;
		cont = this->yes_no_option();
	}
}


template<class T>
void MENU::check_out(std::vector<T>& Mem_list)
{
	this->clear_screen();
	while (this->cont) {
		bool found = false;
		//Finding the equipment and return its index
		std::size_t equip_index = this->return_opponent_index<Equipment>(Equipment_list, found); //Finding the equipment
		if (found) //If the equipment is found, then proceed to the check-out process
		{
			bool choice;
			//Print the equip info and ask the user to confirm
			Equipment_list[equip_index].print_info();
			//Check if the equipment is still available
			int availability = Equipment_list[equip_index].get_availability();
			if (availability == 0)	//There is no equipment left to borrow
			{
				std::cout << "Ther is no equipment left" << std::endl;
				if (this->press_any_key()) break;
			}
			std::cout << "do you want to check this Equipment out? [y/n]" << std::endl;
			choice = this->yes_no_option();
			if (choice) {
				//If the user chooses "y", proceed to enter user info
				bool sub_cont = true;
				while (sub_cont)
				{	
					
					//Finding the Student Info
					bool sub_found = false;
					std::size_t mem_index = this->return_opponent_index<T>(Mem_list, sub_found);
					if (sub_found) {
						//Check the equipment availibility in database 

						//If user info exists in database
						char date[5];
						int borrowed = Mem_list[mem_index].return_occupied_vacancies("BORROW"); // Return the number of equipment that the user has borrowed
						int vacancy = Mem_list[mem_index].return_vacancy_index("BORROW");	//Return the vacancy index in user borrow list
						Mem_list[mem_index].print_info();
						if (borrowed >= 3) //Check if the user has borrowed more than 3 equipments or not
						{
							std::cout << "This Member has borrowed more than 3 equipment" << std::endl;
							std::cout << "Return one to borrow another" << std::endl;
							break;
						}
						else {	
							//Asking for the desired quantity, and check if serveral conditions are met
							int quantity = 0;	//Input user quantity

						availability_check:
											
							std::cout << "How many do you want to borrow? " << std::endl;
							std::cin >> quantity;
							//Check if the desired quantity is greater than the available quantity of the equipment
							if(quantity  > availability)
							{
								std::cout << "Out of stock!" << std::endl;
								std::cout << "Only " << availability << " remained!" << std::endl;
								std::cout << "Do you want to re-enter the quantity?" << std::endl;
								bool re_enter = this->yes_no_option();
								if (re_enter) goto availability_check;
								else break;
							}
							else if (quantity + borrowed > 3)	//Check if the sum of borrowed and will-be-borrowed equipment quantity is greater than 3 or not  
							{
								std::cout << "Borrow: " << borrowed << std::endl;
								std::cout << "Borrow and quantity: " << borrowed + quantity << std::endl;
								std::cout << "Your quantity exceeds the limit! (Only 3 Equipment for each Person!) " << std::endl;
								std::cout << "Do you want to re-enter the quantity? [y/n]" << std::endl;
								bool re_enter = this->yes_no_option();
								if (re_enter) goto availability_check;	
								else break;
							}
							else {
								//All the requiremnts are met!
								std::cout << "Avaibility: " << Equipment_list[equip_index].get_availability() << std::endl;
								std::cout << "Avaibility: " << Equipment_list[equip_index].get_availability() << std::endl;
								std::cout << "Enter date" << std::endl;
								std::cin >> date;
								Mem_list[mem_index].set_borrow_list(Equipment_list[equip_index].get_name(),
									Equipment_list[equip_index].get_IDnumber() , vacancy, quantity, date);	//Set borrow list for the member
								Equipment_list[equip_index].availability_change(-quantity);	//Change in the available quantity of the equipment
								std::cout << "Borrow successfully!" << std::endl;
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
	this->clear_screen();
	while (this->cont) {
		bool found = false;
		std::size_t index = this->return_opponent_index(Mem_list, found); //Finding the Member info based on user-input ID
		if (found)	//If the member is found
		{	
			bool sub_cont = true;
			while (sub_cont)
			{
				bool sub_found = false;
				int quantity;
				std::size_t equip_index;
				Mem_list[index].print_info();
				equip_index = this->return_opponent_index<Equipment>(Equipment_list, sub_found); //Finding the equipment 
				if (sub_found) {
					char input_ID[10];
					char date[5];
					strcpy_s(input_ID, 10, Equipment_list[equip_index].get_IDnumber());		//Store Equipment ID to the variable
					for (int i = 0; i < 3; i++)		//Check for all index in the borrow list
					{	
						//If the equipment name is found on the student borrow list
						if (strcmp(input_ID, Mem_list[index].get_equip_IDnumber(i)) == 0)
						{
							//Check for the quantity. If quantity = 1, automatically return all equipment
							int check_quantity = Mem_list[index].get_equip_quantity(i);
							if (check_quantity == 1)
							{
								std::cout << "Do you want to return it?[y/n]" << std::endl;
								bool _return = this->yes_no_option();
								if (_return)
								{
									std::cout << "Return successfully !" << std::endl;
									Mem_list[index].return_all_equipments(i);	//All equipment is returned
									Equipment_list[equip_index].availability_change(1);
									break;
								}
								else break;
							}
							else
							{
							//In case the member borrow more than one equipments, but wish to return only a few
							enter_quantity:
								std::cout << "How many equipment do you want to return ?" << std::endl;
								std::cin >> quantity;
								if (quantity > check_quantity)
								{
									std::cout << "The input number exceeds your current number!" << std::endl;
									goto enter_quantity;
								}
								else
								{
									//Check for the remain quantity when return equipment
									int remain = check_quantity - quantity;
									std::cout << "Remain " << remain << std::endl;
									if (remain == 0) Mem_list[index].return_all_equipments(i);
									else {
										std::cout << "Enter the date" << std::endl;
										std::cin >> date;
										Mem_list[index].set_borrow_list(Equipment_list[equip_index].get_name(), 
											Equipment_list[equip_index].get_IDnumber(), i, remain, date);	//Update the borrow list with different quantity
									}
									Equipment_list[equip_index].availability_change(quantity);
									std::cout << "Return successfully !" << std::endl;
									break;
								}
							}
							break;
						}
					}
				}
				else std::cout << "Sorry, the equipment info couldn't be found!" << std::endl;
				std::cout << "Do you want to continue returning your equipment? [y/n]" << std::endl;
				sub_cont = this->yes_no_option();
			}

		}
		else std::cout << "No Member found" << std::endl;
		std::cout << "Do you want to continue with other members? [y/n]" << std::endl;
		this->cont = this->yes_no_option();
	}
}


/********************************************************************************************************************
****************************************** PROJECT BASIC FUNCTIONS ************************************************
********************************************************************************************************************/


void MENU::add_project_course()
{
	this->clear_screen();
	std::cout << "Since a tutor is a requirement to create a new project, " << std::endl;
	std::cout << "the tutor info is required" << std::endl;
	while (cont) {
		//Variable declaration
		char name[50], ID_number[10] , start_date[10], duration[10], description[100];
		bool found = false;
		std::size_t tutor_index = this->return_opponent_index<Lecturer>(Lecturer_list,found); //Find and return the Lecturer index
		if (found)
		{
			int tutor_project_index = Lecturer_list[tutor_index].return_vacancy_index("HOST"); //Check if the lecturer has hosted more than 5 projects
			std::cout << "Lecturer Information: " << std::endl;
			Lecturer_list[tutor_index].print_info();
			if (tutor_project_index == -1) {
				//The tutor has more than 5 projects
				std::cout << "This Lecturer has hosted more than 5 projects" << std::endl;
				std::cout << "Finish other projects first before adding one" << std::endl;
				this->press_any_key();
				break;
			}
			else {
				std::cout << "Lecturer Information: " << std::endl;
				//Enter the user-input
				std::cout << " " << std::endl;
				std::cout << "Enter the Project/Course name" << std::endl;
				std::cin.get();
				std::cin.getline(name, 50);
				std::cout << "Enter the Project/Course ID number" << std::endl;
				std::cin.getline(ID_number, 10);
				std::cout << "Enter the Project/Course Start Date" << std::endl;
				std::cin.getline(start_date, 10);
				std::cout << "Enter the Project/Course duration" << std::endl;
				std::cin.getline(duration, 10);
				std::cout << "Enter the Project/Course Description" << std::endl;
				std::cin.getline(description, 100);
			}

			//Create an instance 
			Projects_Courses new_project(name, ID_number, Lecturer_list[tutor_index].get_name(), Lecturer_list[tutor_index].get_IDnumber(),
				start_date, duration, description);
			//Add the instance to the vector list
			Project_Course_List.push_back(new_project);
			//Add project name and ID number to the Lecturer's list
			Lecturer_list[tutor_index].set_project_list(name, ID_number, tutor_project_index);
			std::cout << "Project added successfully!" << std::endl;
			std::cout << "Do you want to create another new project? [y/n]" << std::endl;
			bool sub_cont = this->yes_no_option();
			if (!sub_cont) break;
		}
		else
		{
			std::cout << "Invalid ID number" << std::endl;
			std::cout << "Do you want to re-enter the ID number ? [y/n]" << std::endl;
			this->cont = this->yes_no_option();
		}
		this->clear_screen();
	}
}



void MENU::project_course_status_change()
{
	char changed_status[50];
	this->clear_screen();
	while (this->cont) {
		this->clear_screen();
		bool found = false;
		//Find the project and return its index
		std::size_t index = this->return_opponent_index<Projects_Courses>(Project_Course_List, found);	
		//If the Project/Course is found
		if (found)
		{
			char project_id[10];
			strcpy_s(project_id, 10, Project_Course_List[index].get_IDnumber());	//Store Project ID number to a variable
			Project_Course_List[index].print_info();
			//Check if the project is disabled or not
			if (Project_Course_List[index].project_check_finish())
			{
				std::cout << "This project is currently de-activated" << std::endl;
				std::cout << "Do you want to re-activate it? [y/n]" << std::endl;	//Re-activate projects
				if (this->yes_no_option()) {
					this->re_activate_project(index);
					std::cout << "Project has been re-activated" << std::endl;
					Project_Course_List[index].print_info();
				}
				else break;
			}
			//Change the project status
			std::cout << "Enter the current status of the Project/Course" << std::endl;
			std::cout << "Follow the format [On Going] [%TIME left] [Finished] [Abandoned] [Pending]" << std::endl;
			std::cin.get();
			std::cin.getline(changed_status, 20);	//Enter the changed status
			if (strcmp(changed_status, "Finished") == 0 || strcmp(changed_status, "Abandoned")==0) //Check if the status is marked as Finished or abandoned 
			{	
				this->project_finish(index);
			}
			Project_Course_List[index].change_status(changed_status);
		}
		else std::cout << "No Project/Course found" << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		this->cont = this->yes_no_option();
	}
}


void MENU::project_finish(std::size_t project_index)
{
	bool tutor_found = false;	//Check variable for Lecturer
	char project_id[10];
	strcpy_s(project_id, 10, Project_Course_List[project_index].get_IDnumber());	//Store project ID number
	std::size_t tutor_index = this->return_opponent_index<Lecturer>(Lecturer_list,	//Find and return Lecturer index in Vector
		Project_Course_List[project_index].get_tutor_IDnumber(), tutor_found);
	if (tutor_found)
	{	
		for (int i = 0; i < 5; i++)	//Scan through the project list of the Tutor. 
		{
			if (strcmp(project_id, Lecturer_list[tutor_index].get_project_IDnumber(i)) == 0)	//Check if the Project ID is the same as the one in the project list
			{
				Lecturer_list[tutor_index].project_done(i);	//Set the project to be finished in project list
				std::cout << "Project is deleted from the Lecturer" << std::endl;
			}
		}
	}
	else std::cout << "No Tutor found" << std::endl;
	char student_id[10];
	for (int i = 0; i < 5; i++)
	{
		bool mem_found = false;
		//Scan the Member List of the project and return the index of the Students involved in
		strcpy_s(student_id, 10, Project_Course_List[project_index].get_member_IDnumber(i));	
		std::size_t student_index = this->return_opponent_index<Student>(Student_list, student_id, mem_found);
		if (mem_found)
		{	
			//Search the project in every member's list
			for (int a = 0; a < 2; a++) 
			{
				//If the project is found
				if (strcmp(project_id, Student_list[student_index].get_project_IDnumber(a))==0) 
				{
					Student_list[student_index].project_done(a);
					std::cout << "Project is deleted from student" << std::endl;
				}
			}
		}

	}
}


void MENU::re_activate_project(std::size_t index)
{
	bool found = false;
	bool sub_cont = true;
	while (sub_cont) {
		std::size_t tutor_index = this->return_opponent_index<Lecturer>(Lecturer_list, found); //Find and return the Lecturer index
		if (found) {
			//If lecturer Index is found. Rewrite the lecturer's name and Id number to the project 
			Project_Course_List[index].set_tutor_name(Lecturer_list[tutor_index].get_name(), Lecturer_list[tutor_index].get_IDnumber());
			//Release all the ex-member data
			Project_Course_List[index].release_all_members();
			break;
		}
		else std::cout << "No member found!" << std::endl;
		std::cout << "Do you want to continue finding the Lecturer ID? [y/n]" << std::endl;
		sub_cont = this->yes_no_option();	//User choice
	}
}


void MENU::project_course_enrollment()
{
	int count = 0;
	this->clear_screen();
	while (this->cont) {
		//Clear the screen before start
		this->clear_screen();
		bool found = false;
		std::size_t index = this->return_opponent_index<Projects_Courses>(Project_Course_List, found);	//Search the Project/Course and return its index in vector
		if (found)
		{
			Project_Course_List[index].print_info();
			//Check if the project is marked as finished or abandoned
			if (Project_Course_List[index].project_check_finish())
			{
				std::cout << "This project has ended. Please create a new one or update the project status again" << std::endl;
				this->press_any_key();
				break;
			}
			bool sub_found = false;
			//Print project info
			//Check if the proejct has 5 member or not
			int check_full = Project_Course_List[index].return_occupied_vacancies("MEMBER");	
			if (check_full >= 5)
			{
				std::cout << "This Project is currently full" << std::endl;
				std::cout << "In order to keep productivity, each project/course only has 5 members" << std::endl;
			}
			else {
				std::cout << "Enter the ID number of Students involved in this project/course" << std::endl;
				std::size_t student_index = this->return_opponent_index(Student_list, sub_found);	//Search Student who wants to involve in this project
				if (sub_found)
				{
					count++;
					bool cont_check;
					int student_check;
					int vacancy_index = Project_Course_List[index].return_vacancy_index("MEMBER"); //Return the project vacancy index
					std::cout << "Student: " << count << std::endl;
					Student_list[student_index].print_info();
					if (!Project_Course_List[index].duplicate_member_check(Student_list[student_index].get_IDnumber())) {
						//Check if the student has already involved in 2 projects yet
						student_check = Student_list[student_index].return_vacancy_index("INVOLVED");
						if (student_check == -1) {
							std::cout << "This Student has involved in more than 2 projects" << std::endl;
							this->press_any_key();
							break;
						}
						else {
							//Ask for the user's confirmation
							std::cout << "Do you want to add this Student in the current project? [y/n]" << std::endl;
							cont_check = this->yes_no_option();
							if (cont_check)
							{	
								//Add member to the project
								Project_Course_List[index].add_member(Student_list[student_index].get_name(),
									Student_list[student_index].get_IDnumber(), vacancy_index);
								//Add project name and ID nubmer to the Student's project list
								Student_list[student_index].set_project_list(Project_Course_List[index].get_name(),
									Project_Course_List[index].get_IDnumber(),student_check);
								std::cout << "Add sucessfully!" << std::endl;
							}
						}
					}
					else std::cout << "This student is already in this project!" << std::endl;
				}
				else std::cout << "No student found" << std::endl;
			}

		}
		else std::cout << "Nothing found" << std::endl;
		std::cout << "Do you want to continue? [y/n]" << std::endl;
		this->cont = this->yes_no_option();
	}
}



