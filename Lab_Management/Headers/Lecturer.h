#pragma once

#include "Lib.h"

class Lecturer : public Student
{
public:
	Lecturer() {};
	Lecturer(std::string Name, std::string Email, std::string ID_Number, std::string phonenumber) {};
	void create_course_project() {};
	void delete_course_project() {};
	void update_status() {};
};
