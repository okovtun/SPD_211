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
			cout << "������� ������: " << get_area() << endl;
			cout << "�������� ������: " << get_perimeter() << endl;
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
			cout << "����� �������: " << get_side() << endl;
			cout << "���������: " << get_diagonal() << endl;
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

			//1) �������� ���������� ���� �������:
			HWND hwnd = GetConsoleWindow();
			
			//2) �������� �������� ���������� ��� ���� �������:
			HDC hdc = GetDC(hwnd);	//�������� ���������� - ��� ��, �� ��� �� ����� ��������
			//������ ����� ������������ � ���, ��� �� ����� ��������

			//3) ������� ��������. �������� ������ ������ ������
			HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));	//PS_SOLID - �������� �����
																//5 - ������� �����

			//4) ������� �����. ����� ��������� ������� ������
			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));

			//5) ����� ���������� ����� ������� ���, � �� ��� �� ����� ��������
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//6) ����� ��� ������� ������� � �������, ����� �������� ������ ��� ������,
			//	 ��� ������ ��������������� �������:
			::Rectangle(hdc, 100, 100, 300, 200);

			//7) ����� � �������� ��� �� �������� �������, ������� �� ���� ����� �������:
			DeleteObject(hPen);
			DeleteObject(hBrush);

			//8) ����������� �������� ����������:
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "������: " << get_width() << endl;
			cout << "�����: " << get_length() << endl;
			cout << "���������: " << " ������� ����" << endl;
			Shape::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	Geometry::Square square(5);
	cout << "����� ������� ��������: " << square.get_side() << endl;
	cout << "��������� ��������: " << square.get_diagonal() << endl;
	cout << "������� ��������: " << square.get_area() << endl;
	cout << "�������� ��������:" << square.get_perimeter() << endl;
	square.draw();
	cout << delimiter << endl;
	square.info();

	Geometry::Rectangle rect(25, 15);
	rect.info();
}