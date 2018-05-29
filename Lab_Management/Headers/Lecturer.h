#pragma once

#include "Lib.h"
#include "Check_Vacancy.h"


class Lecturer : public Student
{
private:
	projects project_list[5];
public:
	Lecturer() {};
	Lecturer(char* Name, char* Email, char* phonenumber, char* ID_Number);
	int return_occupied_vacancies(const char* mode) override;
	int return_vacancy_index(const char* mode) override;
	void set_project_list(char* project_name, char* ID_num, int vacancy_index) override;
	void print_info() override;
};