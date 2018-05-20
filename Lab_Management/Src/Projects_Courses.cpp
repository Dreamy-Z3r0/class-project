#include"../Headers/Projects_Courses.h"

Projects_Courses::Projects_Courses(std::string name, std::string start_date, std::string duration, std::string status, std::string description)
{
	this->name = name;
	this->start_date = start_date;
	this->duration = duration;
	this->status = status;
	this->description = description;
}

Projects_Courses::~Projects_Courses() {}

void Projects_Courses::change_status(std::string status)
{
	this->status = status;
}

void Projects_Courses::print_info()
{
	std::cout << name << ": (" << status << ")\n";
	std::cout << "Start: " << start_date;
	std::cout << "\nDuration: " << duration;
	std::cout << "\nDescription: " << description;
	std::cout << "\nAttending list: ";
	
	if (attending_list.size() == 0)
	{
		std::cout << "N/A";
	}
	else 
		for (int i = 0; i < attending_list.size(); i++)
		{
			std::cout << "\n\t" << attending_list[i].get_name() << " (" << attending_list[i].get_IDnumber() << ")";
				std::cout << " ";
		}
		
}
