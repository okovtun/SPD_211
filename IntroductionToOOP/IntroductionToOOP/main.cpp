//IntroductionToOOP
#include<iostream>
using namespace std;

/*
---------------
Создавая структуру или класс, мы создаем новый тип данных,
пользовательский тип данных.

				  класс - это тип данных
				структуры - это тип данных
---------------
*/

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//				Constructors:
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Methods:
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	//type name;
	int a;		//Объявление переменной 'a' типа 'int'
	Point A;	//Объявление переменной 'A' типа 'Point'
				//Объявление объекта 'A' структуры 'Point'
				//Создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(A) << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;	//Default constructor
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();
}

/*
------------------------------------
.  - Оператор прямого доступа (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
------------------------------------
*/

/*
------------------------------------
1. Encapsulation - это сокрытие определенной части класса от внешнего мира;
	Модификаторы доступа:
		private:	закрытые поля, доступны только внутри класса
		public:		открытые поля, доступны из любого места программы
		protected:	защищенные поля, доступны внутри нашего класса, и его дочерних классов

	get/set-методы
	get (взять, получить) позволяют получить значение закрытой переменной, т.е.,
		открывают доступ к закрытым переменным на чтение.
	set (задать, установить) позволяют задавать значения закрытой переменной в классе, т.е.,
		открывают доступ к закрытым переменным на запись.
2. Inheritance;
3. Polymorphism;
------------------------------------
*/

/*
------------------------------------
1. Constructor - это метод, который создает объект, а именно, выделяет память под объект,
   и инициализирует его поля при создании;
2. ~Destructor - это метод, который уничтожает объект по завршении его времени жизни.
   Время жизни объекта завршается при выходе за пределы области видимости, в которой он объявлен;
3. Assignment operator;

				Типы конструкторов:
	-с параметрами;
	-без параметров;
	-по умолчанию - это конструктор, который может быть вызван без параметров;
	-конструктор копирования;
	-конструктор переноса;
------------------------------------
*/