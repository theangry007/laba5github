#pragma once
/**
Header

Класс, который представляет собой запись, содержащую имя ученика, предмета и их индексы
*/
class Header
{
public:
	Header()
		:pupil(-1)
		,subject(-1)
		,pPupil(-1)
		,pSubject(-1)
	{
	}
	///Pupil of Header
	int pupil;
	///Subject of Header
	int subject;
	///Pointer to the Header
	int pPupil;
	///Pointer to the Header
	int pSubject;
};