#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);

class String
{
	//Строка в языке 'C' - это массив элементов типа 'char', 
	//последний элемент которого всегда содержит ASCII-символ с кодом 0 - '\0'
	//'\0' является признаком конца строки
	int size;		//размер строки в Байтах
	char* str;		//адрес строки в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//				Constructors:
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char str[]) :String(strlen(str)+1)
	{
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other) :String(other.str)
	{
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other):size(other.size), str(other.str)
	{
		//Shallow copy:
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
	String& operator=(const String& other)
	{
		/*int a = 2;
		int b = 3;
		a = b;*/
		if (this == &other)return *this;
		delete[] str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}


	//				Methods:
	void print()const
	{
		cout << "Size: " << size << endl;
		cout << "Str:  " << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

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