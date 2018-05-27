#pragma once

#include "Lib.h"
#include "Check_Vacancy.h"


class Lecturer : public Student
{
private:
	projects project_list[10];
public:
	Lecturer() {};
	Lecturer(std::string Name, std::string Email, std::string ID_Number, std::string phonenumber) {};
};
