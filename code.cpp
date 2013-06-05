#include "Multyspisok.h"
#include <conio.h>
#include <iostream>

void main()
{	
	///Объявление экземпляра класса Multyspisok
	Multyspisok ml;
	///Заполним массив учеников и предметов
	const int subjectsCount = 3;
	const int pupilsCount = 6;
	char* subjectsArr[subjectsCount] = {"Physics", "PE", "Chemistry"};
	char* pupilsArr[pupilsCount] = {"Ivan", "Igor", "Lena", "Vika", "Alex", "John"};	
	///Таблица связей
	bool _lTable[subjectsCount][pupilsCount] =
    {
        {1,0,1,1,0,0},
        {1,0,0,1,0,1},
        {1,1,0,0,1,0}
    };
	int** lTable = new int*[subjectsCount];
	for (int i = 0; i < subjectsCount; ++i)
	{
		lTable[i] = new int[pupilsCount];
		for (int j = 0; j < pupilsCount; ++j)
		{
			lTable[i][j] = _lTable[i][j];
		}
	}

	///Установка учеников, предметов и 
	ml.SetSubjects(subjectsArr, subjectsCount);
	ml.SetPupils(pupilsArr, pupilsCount);
	ml.SetLinks(lTable);
	cout<<"Subjects: "<<endl;
	for (int i = 0; i < subjectsCount; ++i) cout<<i<<". "<<subjectsArr[i]<<endl;
	cout<<endl<<"Students: "<<endl;
	for (int i = 0; i < pupilsCount; ++i) cout<<i<<". "<<pupilsArr[i]<<endl;
	cout<<endl<<"Link Table: "<<endl;
	for (int i = 0; i < subjectsCount; ++i)
	{
		for (int j = 0; j < pupilsCount; ++j)
		{
			cout<<ml.LinkTable()[i][j]<<"\t";
		}
		cout<<endl<<endl;
	}

	///Main workability: pupils in subject and subject on pupil
	list<char*> res = ml.GetPupilsOnSubject("Physics");
	cout<<endl<<"Students on Physics: "<<"\t";
	for (auto it = res.begin(); it != res.end(); it++)
	{
		cout<<*it<<", ";
	}
	cout<<endl<<endl<<"Subject on Ivan: "<<"\t";
	res = ml.GetSubjectsOnPupil("Ivan");
	for (auto it = res.begin(); it != res.end(); it++)
	{
		cout<<*it<<", ";
	}

	cout<<endl<<endl;
	system("PAUSE");
}