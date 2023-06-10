#include<Windows.h>
#include<iostream>
using namespace std;

#define delimiter "\n-----------------------------------------\n"

namespace Geometry
{
	class Shape
	{
	public:
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};

	class Square :public Shape
	{
		double side;
	public:
		Square(double side)
		{
			this->side = side;
		}
		~Square() {}
		double get_side()const
		{
			return side;
		}
		double get_diagonal()const
		{
			return side * sqrt(2);
			//return sqrt(side*side * 2);
		}
		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void draw()const
		{
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_side() << endl;
			cout << "Диагональ: " << get_diagonal() << endl;
			Shape::info();
		}
	};

	class Rectangle :public Shape
	{
		double width;
		double length;
	public:
		Rectangle(double width, double length)
		{
			this->width = width;
			this->length = length;
		}
		~Rectangle()
		{

		}
		double get_width()const
		{
			return width;
		}
		double get_length()const
		{
			return length;
		}
		double get_area()const
		{
			return width * length;
		}
		double get_perimeter()const
		{
			return (width + length) * 2;
		}
		void draw()const
		{
			//WinGDI - Windows Grapics Device Interface

			//1) Получаем обработчик окна консоли:
			HWND hwnd = GetConsoleWindow();
			
			//2) Получаем контекст устройства для окна консоли:
			HDC hdc = GetDC(hwnd);	//Контекст устройства - это то, на чем мы будем рисовать
			//Теперь нужно определиться с тем, чем мы будем рисовать

			//3) Создаем карандаш. Карандаш рисует контур фигуры
			HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));	//PS_SOLID - сплошная линия
																//5 - толщина линии

			//4) Создаем кисть. Кисть выполняет заливку фигуры
			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));

			//5) Перед рисованием нужно выбрать чем, и на чем мы будем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//6) Когда все объекты созданы и выбраны, можно рисовать нужную нам фигуру,
			//	 при помощи соответствующей функции:
			::Rectangle(hdc, 100, 100, 300, 200);

			//7) Кисть и карандаш так же занимают ресурсы, поэтому их тоже нужно удалить:
			DeleteObject(hPen);
			DeleteObject(hBrush);

			//8) Освобождаем контекст устройства:
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина: " << get_width() << endl;
			cout << "Длина: " << get_length() << endl;
			cout << "Диагональ: " << " сделать дома" << endl;
			Shape::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	Geometry::Square square(5);
	cout << "Длина стороны квадрата: " << square.get_side() << endl;
	cout << "Диагональ квадрата: " << square.get_diagonal() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата:" << square.get_perimeter() << endl;
	square.draw();
	cout << delimiter << endl;
	square.info();

	Geometry::Rectangle rect(25, 15);
	rect.info();
}