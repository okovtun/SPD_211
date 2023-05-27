#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

////////////////////////////////////////////////////////////////////////////////////
///////////				ОБЪЯВЛЕНИЕ КЛАССА - CLASS DECLARATION			////////////

class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	//Строка в языке 'C' - это массив элементов типа 'char', 
	//последний элемент которого всегда содержит ASCII-символ с кодом 0 - '\0'
	//'\0' является признаком конца строки
	int size;		//размер строки в Байтах
	char* str;		//адрес строки в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Constructors:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	//				Operators:
	String& operator=(const String& other);
	String& operator+=(const String& other);

	char operator[](int i)const;
	char& operator[](int i);


	//				Methods:
	void print()const;
};


///////////			КОНЕЦ ОБЪЯВЛЕНИя КЛАССА - CLASS DECLARATION	END		////////////
////////////////////////////////////////////////////////////////////////////////////