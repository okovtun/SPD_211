﻿#define _USE_MATH_DEFINES
#include<Windows.h>
#include<iostream>
using namespace std;

#define delimiter "\n-----------------------------------------\n"

namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,
		grey = 0x00AAAAAA,
		white = 0x00FFFFFF,
	};
	enum Limits
	{
		MIN_START_X = 100,
		MAX_START_X = 1000,
		MIN_START_Y = 100,
		MAX_START_Y = 800,
		MIN_LINE_WIDTH = 1,
		MAX_LINE_WIDTH = 30,
		//---------------------------
		MIN_LENGTH = 20,
		MAX_LENGTH = 800
	};
#define SHAPE_TAKE_PARAMETERS	Color color, int start_x, int start_y, int line_width = 5
#define SHAPE_GIVE_PARAMETERS	color, start_x, start_y, line_width
	class Shape
	{
	protected:
		Color color;
		int start_x;
		int start_y;
		int line_width;

	public:
		Shape(SHAPE_TAKE_PARAMETERS)
		{
			set_color(color);
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		Color get_color()const
		{
			return color;
		}
		int get_start_x()const
		{
			return start_x;
		}
		int get_start_y()const
		{
			return start_y;
		}
		int get_line_width()const
		{
			return line_width;
		}
		void set_color(Color color)
		{
			this->color = color;
		}
		void set_start_x(int start_x)
		{
			if (start_x < Limits::MIN_START_X)start_x = Limits::MIN_START_X;
			if (start_x > Limits::MAX_START_X)start_x = Limits::MAX_START_X;
			this->start_x = start_x;
		}
		void set_start_y(int start_y)
		{
			if (start_y < Limits::MIN_START_Y)start_y = Limits::MIN_START_Y;
			if (start_y > Limits::MAX_START_Y)start_y = Limits::MAX_START_Y;
			this->start_y = start_y;
		}
		void set_line_width(int line_width)
		{
			if (line_width < Limits::MIN_LINE_WIDTH)line_width = Limits::MIN_LINE_WIDTH;
			if (line_width > Limits::MAX_LINE_WIDTH)line_width = Limits::MAX_LINE_WIDTH;
			this->line_width = line_width;
		}

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

	/*class Square :public Shape
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
	};*/

	class Rectangle :public Shape
	{
		double width;
		double length;
	public:
		Rectangle(double width, double length, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_length(length);
		}
		~Rectangle() {}
		void set_width(double width)
		{
			if (width < MIN_LENGTH)width = MIN_LENGTH;
			if (width > MAX_LENGTH)width = MAX_LENGTH;
			this->width = width;
		}
		void set_length(double lendth)
		{
			if (lendth < MIN_LENGTH)lendth = MIN_LENGTH;
			if (lendth > MAX_LENGTH)lendth = MAX_LENGTH;
			this->length = lendth;
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
			HPEN hPen = CreatePen(PS_SOLID, 5, color);	//PS_SOLID - сплошная линия
																//5 - толщина линии

			//4) Создаем кисть. Кисть выполняет заливку фигуры
			HBRUSH hBrush = CreateSolidBrush(color);

			//5) Перед рисованием нужно выбрать чем, и на чем мы будем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//6) Когда все объекты созданы и выбраны, можно рисовать нужную нам фигуру,
			//	 при помощи соответствующей функции:
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + length);

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
	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
	};
	class Circle :public Shape
	{
		double radius;
	public:
		Circle(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_radius(radius);
		}
		void set_radius(double radius)
		{
			if (radius < Limits::MIN_LENGTH)radius = Limits::MIN_LENGTH;
			if (radius > Limits::MAX_LENGTH)radius = Limits::MAX_LENGTH;
			this->radius = radius;
		}
		double get_radius()const
		{
			return radius;
		}
		double get_diameter()const
		{
			return 2 * radius;
		}
		double get_area()const
		{
			return M_PI * radius*radius;
		}
		double get_perimeter()const
		{
			return 2 * M_PI*radius;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус круга: " << get_radius() << endl;
			Shape::info();
		}
	};
	class Triangle :public Shape
	{
	public:
		Triangle(SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) {};
		~Triangle() {}
		virtual double get_height()const = 0;
		void info()const
		{
			cout << "Высота треугольника: " << get_height() << endl;
			Shape::info();
		}
	};
	class EquillateralTriangle :public Triangle
	{
		double side;
	public:
		EquillateralTriangle(double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
		}
		void set_side(double side)
		{
			if (side < Limits::MIN_LENGTH)side = Limits::MIN_LENGTH;
			if (side > Limits::MAX_LENGTH)side = Limits::MAX_LENGTH;
			this->side = side;
		}
		double get_side()const
		{
			return side;
		}
		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(side / 2, 2));
		}
		double get_area()const
		{
			return (side / 2 * get_height());
		}
		double get_perimeter()const
		{
			return 3 * side;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertex[] =
			{
				{ start_x, start_y + side },
				{ start_x + side, start_y + side },
				{ start_x + side / 2, start_y + side - get_height()}
			};

			::Polygon(hdc, vertex, 3);

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_side() << endl;
			Triangle::info();
		}
	};
	class IsoscalesTriangle :public Triangle
	{
		double base;	//основание треуголника
		double side;	//сторона треуголника
	public:
		IsoscalesTriangle(double base, double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_base(base);
			set_side(side);
		}
		~IsoscalesTriangle() {}
		void set_base(double base)
		{
			if (base < Limits::MIN_LENGTH)base = Limits::MIN_LENGTH;
			if (base > Limits::MAX_LENGTH)base = Limits::MAX_LENGTH;
			this->base = base;
		}
		void set_side(double side)
		{
			if (side < Limits::MIN_LENGTH)side = Limits::MIN_LENGTH;
			if (side > Limits::MAX_LENGTH)side = Limits::MAX_LENGTH;
			this->side = side;
		}
		double get_base()const
		{
			return base;
		}
		double get_side()const
		{
			return side;
		}
		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(base / 2, 2));
		}
		double get_area()const
		{
			return base * get_height() / 2;
		}
		double get_perimeter()const
		{
			return base + 2 * side;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertex[] =
			{
				{ start_x, start_y + side },
				{ start_x + base, start_y + side },
				{ start_x + base / 2, start_y + side - get_height()}
			};

			::Polygon(hdc, vertex, 3);

			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Основание: " << get_base() << endl;
			cout << "Сторона: " << get_side() << endl;
			Triangle::info();
		}
	};
}

void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//Получаем окно консоли:
	//COORD coord = {};	//Объявляем экземпляр структуры COORD. Мы никак не используем этот экземпляр, но без него невозможно вызвать функцию
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, NULL);	//Функция SetConsoleDisplayMode() задает режим отображения консоли

	setlocale(LC_ALL, "");
	Geometry::Square square(50, Geometry::Color::red, 300, 100, 5);
	/*cout << "Длина стороны квадрата: " << square.get_side() << endl;
	cout << "Диагональ квадрата: " << square.get_diagonal() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата:" << square.get_perimeter() << endl;
	square.draw();*/
	//cout << delimiter << endl;
	square.info();

	Geometry::Rectangle rect(250, 150, Geometry::Color::grey, 500, 100);
	rect.info();

	Geometry::Circle sun(150, Geometry::Color::yellow, 800, 100);
	sun.info();

	Geometry::EquillateralTriangle eq_tri(80, Geometry::Color::green, 500, 270, 8);
	eq_tri.info();

	Geometry::IsoscalesTriangle iso_tri(250, 127, Geometry::Color::blue, 700, 270, 1);
	iso_tri.info();
}