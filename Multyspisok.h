#pragma once
#include <string>
#include <list>
#include <iostream>
#include "Header.h"

/**
MultyList

Мультиcписок, реализованный с помощью специального списка ссылок
*/
using namespace std;
class Multyspisok
{
private:
	///Число учеников
	int pupilsCount;
	///Число предметов
	int subjectsCount;
	///Количество записей
	int Xcount;
	///Массив имен учеников
	char** pupils;
	///Массив названий предметов
	char** subjects;
	///Двумерный массив связей
	int** linkTable;
	///Массив записей
	Header* nodes;
public:
	///Конструктор
	Multyspisok();
	///Деструктор
	~Multyspisok();
	///Получить число учеников
	int PupilsCount();
	///Получить число предметов
	int SubjectsCount();
	///Получить имена учеников
	char** Pupils();
	///Получить названия предметов
	char** Subjects();
	///Получить таблицу связей
	int** LinkTable();
	///Получить учеников по предмету
	list<char*> GetPupilsOnSubject(char* subjectName);
	///Получить предмет по ученику
	list<char*> GetSubjectsOnPupil(char* pupilName);
	///Установить имя предмета
	void SetSubjects(char** subjects, int count);
	///Установить имя ученика
	void SetPupils(char** pupils, int count);
	///Установить таблицу связей
	void SetLinks(int** lTable);	
};

