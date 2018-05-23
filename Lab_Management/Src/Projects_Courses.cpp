#include"../Headers/Projects_Courses.h"

Projects_Courses::Projects_Courses(char* name, char* start_date, char* duration, const char* status, const char* description)
{
	strcpy_s(this->name,50, name);
	strcpy_s(this->start_date,10, start_date);
	strcpy_s(this->duration,10, duration);
	strcpy_s(this->status, 10, status);
	strcpy_s(this->description,100, description);
}

Projects_Courses::~Projects_Courses() {}
char* Projects_Courses::get_name()
{
	return this->name;
}

void Projects_Courses::change_status(char* status)
{
	strcpy_s(this->status, 10, status);
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
