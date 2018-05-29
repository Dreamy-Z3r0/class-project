#pragma once


class Check_Vacancy
{
public:
	virtual int return_vacancy_index(const char* mode) = 0;
	virtual int return_occupied_vacancies(const char* mode) = 0;
};

