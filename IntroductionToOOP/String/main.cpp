#include"String.h"

#define HOME_WORK
//#define CONSTRUCTORS_CALLING

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello String" << endl;
	//String str1;
	//str1.print();

	//String str = "Hello";
	//str.print();
	//cout << str << endl;

#ifdef HOME_WORK
	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	String str3 = str1 + str2;	//Copy constructor
	//String str3;
	//str3 = str1 + str2;
	cout << str3 << endl;

	//str1 += str2;
	//cout << str1 << endl;

	String str4 = str3;
	cout << str4 << endl;
#endif // HOME_WORK

	//Move-методы:
	//Выполняют Shallow copy (поверхностное копирование)
	//Move-constructor;
	//Move-assingment;
	//r-value reference:	Class&& other

#ifdef CONSTRUCTORS_CALLING
	String str1;		//Default constructor
	str1.print();

	String str2(22);	//Single-Argument constructor 'int'
	str2.print();

	String str3 = "Hello";//Single-Argument constructor 'const char*'
	str3.print();

	String str4();	//DefaultConstructor НЕВОЗМОЖЕНО вызвать таким образом.
	//В этой строке объявляется функция 'str4', которая ничего не принимает, 
	//и возвращает объект класса 'String'
	//str4.print();
	//Если нужно явно вызвать конструктор по умолчаниию, то это можно сделать так:
	String str5{};	//Default constructor
	str5.print();

	String str6{ "World" };
	str6.print();

	String str7 = str3;	//CopyConstructor
	str7.print();

	String str8;
	str8 = str6;	//CopyAssignment
	str8.print();
#endif // CONSTRUCTORS_CALLING

}