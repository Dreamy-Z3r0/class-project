#pragma once
#include"Lib.h"

class Projects_Courses {
private:
	char name[50];
	char start_date[10];
	char duration[10];
	char status[20];
	char description[100];
	std::vector<Student> attending_list;
	
public:
	Projects_Courses() {};
	Projects_Courses(char* name, char* start_date, char* duration, const char* status = "Ongoing", const char* description = "N/A");
	~Projects_Courses();
	char* get_name();
	void change_status(char* status);
	void print_info();
	void add_member();
};
