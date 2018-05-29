#pragma once
#include"Lib.h"
#include"Check_Vacancy.h"

struct Tutor
{
	char name[50] = "none";
	char ID_Number[10] = "none";
	bool vacancy = true;
};
struct Member
{
	char name[50] = "none";
	char ID_Number[10] = "none";
	bool vacancy = true;
};




class Projects_Courses : public Check_Vacancy {
private:
	char name[50];
	char ID_number[20];
	char start_date[10];
	char duration[10];
	char status[20];
	char description[100];

	Member Member_List[5];
	Tutor project_tutor;

public:
	Projects_Courses() {};
	Projects_Courses(char* name, char* ID_number, char* tutor_name, char* tutor_ID_number,
	char* start_date, char* duration, char* description, const char* status = "On-Going");
	~Projects_Courses();
	char* get_name();
	char* get_IDnumber();
	char* get_tutor_IDnumber();
	char* get_member_IDnumber(int index);
	void change_status(char* status);
	void print_info();
	void add_member(char* name, char* ID_number, int index);
	int return_vacancy_index(const char* mode) override;
	int return_occupied_vacancies(const char* mode) override;
	bool duplicate_member_check(char* ID_number);
	
};
