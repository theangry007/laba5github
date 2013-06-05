#pragma once
#include <string>
#include <list>
#include <iostream>
#include "Header.h"

/**
MultyList

������c�����, ������������� � ������� ������������ ������ ������
*/
using namespace std;
class Multyspisok
{
private:
	///����� ��������
	int pupilsCount;
	///����� ���������
	int subjectsCount;
	///���������� �������
	int Xcount;
	///������ ���� ��������
	char** pupils;
	///������ �������� ���������
	char** subjects;
	///��������� ������ ������
	int** linkTable;
	///������ �������
	Header* nodes;
public:
	///�����������
	Multyspisok();
	///����������
	~Multyspisok();
	///�������� ����� ��������
	int PupilsCount();
	///�������� ����� ���������
	int SubjectsCount();
	///�������� ����� ��������
	char** Pupils();
	///�������� �������� ���������
	char** Subjects();
	///�������� ������� ������
	int** LinkTable();
	///�������� �������� �� ��������
	list<char*> GetPupilsOnSubject(char* subjectName);
	///�������� ������� �� �������
	list<char*> GetSubjectsOnPupil(char* pupilName);
	///���������� ��� ��������
	void SetSubjects(char** subjects, int count);
	///���������� ��� �������
	void SetPupils(char** pupils, int count);
	///���������� ������� ������
	void SetLinks(int** lTable);	
};

