#pragma once
#include"Lib.h"

class Projects_Courses {
private:
	std::string name;
	std::string start_date;
	std::string duration;
	std::string status;
	std::string description;
	std::vector<Student> attending_list;
	
public:
	Projects_Courses(std::string name, std::string start_date, std::string duration, std::string status = "Ongoing", std::string description = "N/A");
	~Projects_Courses();
	void change_status(std::string status);
	void print_info();
	void add_member();
};
