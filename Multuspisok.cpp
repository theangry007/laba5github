#include "Multyspisok.h"
// Конструктор 
Multyspisok::Multyspisok()
	:Xcount(0)
{
	
}
// Деструктор 
Multyspisok::~Multyspisok()
{
}
// название предмета
void Multyspisok::SetSubjects(char** arr, int count)
{
	subjects = arr;
	subjectsCount = count;
}
// имя ученика
void Multyspisok::SetPupils(char** arr, int count)
{
	pupils = arr;
	pupilsCount = count;
}
//таблица связей
void Multyspisok::SetLinks(int **lTable)
{
	linkTable = lTable;		
	nodes = new Header[Xcount];	
	int k = 0;
	for (int i = 0; i < subjectsCount; ++i)
	{
		for (int j = 0; j < pupilsCount; ++j)
		{
			if (linkTable[i][j])
			{
				nodes[k].pupil = j;
				nodes[k].subject = i;
				++k;
				++Xcount;			
			}
		}		
	}
	for(int k = 0; k < Xcount; ++k)
	{
		nodes[k].pPupil = -1;
		nodes[k].pSubject = -1;		
	}
	for(int k = 0; k < Xcount; ++k)
	{
		for (int i = k + 1; i < Xcount; ++i) 
		{
			if (nodes[i].subject == nodes[k].subject) 
			{
				nodes[k].pPupil = i;
				break;
			}
		}
		for (int i = k + 1; i < Xcount; ++i)
		{
			if (nodes[i].pupil == nodes[k].pupil)
			{
				nodes[k].pSubject = i;
				break;
			}
		}
	}		
}
//учеников по предмету
list<char*> Multyspisok::GetPupilsOnSubject(char* subject)
{
	list<char*> result;
	int i;
	int k;
	for (i = 0; i < subjectsCount; ++i)	if (subjects[i] == subject)	break;
	for (k = 0; k < Xcount; ++k) if (nodes[k].subject == i) break;
	Header curNode = nodes[k];
	result.push_back(pupils[curNode.pupil]);
	while (curNode.pPupil !=-1)
	{
		curNode = nodes[curNode.pPupil];
		result.push_back(pupils[curNode.pupil]);
	}
	return result; 
}
//предметы по ученику
list<char*> Multyspisok::GetSubjectsOnPupil(char* pupil)
{
	list<char*> result;
	int i;
	int k;
	for (i = 0; i < pupilsCount; ++i)	if (pupils[i] == pupil)	break;
	for (k = 0; k < Xcount; ++k) if (nodes[k].pupil == i) break;
	Header curNode = nodes[k];
	result.push_back(subjects[curNode.subject]);
	while (curNode.pSubject !=-1)
	{
		curNode = nodes[curNode.pSubject];
		result.push_back(subjects[curNode.subject]);
	}
	return result; 
}
// число учеников
int Multyspisok::PupilsCount()
{
	return pupilsCount;
}
// число предметов
int Multyspisok::SubjectsCount()
{
	return subjectsCount;
}
// массив учеников
char** Multyspisok::Pupils()
{
	return pupils;
}
//массив предметов
char** Multyspisok::Subjects()
{
	return subjects;
}
// таблиа связей
int** Multyspisok::LinkTable()
{
	return linkTable;
}
