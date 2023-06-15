// Создать приложение которое по внесенным данным о размерах фигур и их координат
// посчитает их площадь и нарисует фигуры в файле
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Shape
{
protected:
	double x, y;
public:
	Shape(double x, double y) : x(x), y(y) {}
	~Shape() {}

	virtual void Save() = 0;
	virtual string Load() = 0;
	virtual void Show() = 0;

};

class Square : public Shape
{
protected:
	string type;
	int a;
public:
	Square(int a, double x, double y) : Shape(x, y)
	{
		this->type = "\n   Square";
		this->a = a;
	}
	~Square() {}

	void Save() override
	{
		ofstream inf("shape_file_info.txt", ios::app);
		if (!(inf.is_open()))                                         
		{
			cout << "\nError open file!!!";
		}
		else
		{
			inf << this->type << endl;
			inf << "x = " << x << endl;
			inf << "y = " << y << endl;
			inf << "a = " << a << endl;
			inf << "" << endl;
		}
		inf.close();

		ofstream inf2("Square_file.txt", ios::app);
		if (!(inf2.is_open()))                                          
		{
			cout << "\nError opening file!!!";
		}
		else
		{
			inf2 << this->type << endl;
			for (int i = 0; i < a + x; i++)
			{
				for (int j = 0; j < a + y; j++)
				{
					if (i < x || j < y)
						inf2 << "  ";
					else
						inf2 << "XX";
				}
				inf2 << endl;
			}
		}
		inf2.close();
	}

	string Load() override
	{
		string way;
		ifstream outf;
		outf.exceptions(ifstream::badbit | ifstream::failbit);   // эта строка не относится к try catch но относится к fstream

		try
		{
			cout << "Try to open file \n";

			outf.open("Squarefile.txt");                         //  Здесь допущена ошибка в имени файла Squarefile.txt вместо Square_file.txt

			cout << "file is opened \n";

			while (!(outf.eof()))
			{
				way = " ";
				getline(outf, way);
				cout << way << endl;
			}
			outf.close();
		}
		catch (const ifstream::failure& ex)                     // failure класс exception для ошибок ifstream     // или (const std::exception& ex) но тогда без code()
		{
			cout << "\nError opening file!!!\n";
			cout << ex.what() << endl;
			cout << "code error is : " << ex.code() << endl;    // ф-я code() - выдаст код ошибки
			
		}
			
		return way;
	}

	void Show() override
	{
		cout << this->type << " information :" << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "a = " << a << endl;
		cout << "" << endl;
	}
};

class Rectangle : public Square
{
protected:
	string type;
	int b;
public:
	Rectangle(int a, int b, double x, double y) : Square(a, x, y)
	{
		this->type = "\n   Rectangle";
		this->b = b;
	}
	~Rectangle() {}

	void Save() override
	{
		ofstream inf("shape_file_info.txt", ios::app);
		if (!(inf.is_open()))                                          // проверка открытия файлов
		{
			cout << "\nError opening file!!!";
		}
		else
		{
			inf << this->type << endl;
			inf << "x = " << x << endl;
			inf << "y = " << y << endl;
			inf << "a = " << a << endl;
			inf << "b = " << b << endl;
			inf << "" << endl;
		}
		inf.close();

		ofstream inf2("Rectangle_file.txt", ios::app);
		if (!(inf2.is_open()))                                          // проверка открытия файлов
		{
			cout << "\nError opening file!!!";
		}
		else
		{
			inf2 << this->type << endl;
			for (int i = 0; i < a + x; i++)
			{
				for (int j = 0; j < b + y; j++)
				{
					if (i < x || j < y)
						inf2 << "  ";
					else
						inf2 << "XX";
				}
				inf2 << endl;
			}
		}
		inf2.close();
	}

	string Load() override
	{
		string way;
		ifstream outf;
		outf.open("Rectangle_file.txt");
		if (!(outf.is_open()))
		{
			cout << "\nError opening file!!!";
		}
		else
		{
			while (!(outf.eof()))
			{
				way = " ";
				getline(outf, way);
				cout << way << endl;
			}
			outf.close();
		}
		return way;
	}
	void Show() override
	{
		cout << this->type << " information :" << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "" << endl;
	}
};

class Circle : public Rectangle
{
protected:
	string type;
	int r;
public:
	Circle(int a, int b, int r, double x, double y) : Rectangle(a, b, x, y)
	{
		this->type = "\n   Circle";
		this->r = r;
	}
	~Circle() {}

	void Save() override
	{
		ofstream inf("shape_file_info.txt", ios::app);
		if (!(inf.is_open()))                                          // проверка открытия файлов
		{
			cout << "\nError opening file!!!";
		}
		else
		{
			inf << this->type << endl;
			inf << "x = " << x << endl;
			inf << "y = " << y << endl;
			inf << "a = " << a << endl;
			inf << "b = " << b << endl;
			inf << "r = " << r << endl;
			inf << "" << endl;
		}
		inf.close();

		ofstream inf2("Circle_file.txt", ios::app);
		if (!(inf2.is_open()))                                          // проверка открытия файлов
		{
			cout << "\nError open file!!!";
		}
		else
		{
			inf2 << this->type << endl;
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 20; j++)
					if ((i - a) * (i - a) + (j - b) * (j - b) <= r * r) inf2 << "XX";
					else inf2 << "  ";
				inf2 << endl;
			}
			inf2 << endl;
		}
		inf2.close();
	}
	string Load() override
	{
		string way;
		ifstream outf;
		outf.open("Circle_file.txt");
		if (!(outf.is_open()))
		{
			cout << "\nError opening file!!!";
		}
		else
		{
			while (!(outf.eof()))
			{
				way = " ";
				getline(outf, way);
				cout << way << endl;
			}
			outf.close();
		}
		return way;
	}
	void Show() override
	{
		cout << this->type << " information :" << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "r = " << r << endl;
		cout << "" << endl;
	}
};

class Ellipse : public Circle
{
protected:
	string type;
public:
	Ellipse(int a, int b, int r, double x, double y) : Circle(a, b, r, x, y)
	{
		this->type = "\n   Ellipse";
	}
	~Ellipse() {}

	void Save() override
	{
		ofstream inf("shape_file_info.txt", ios::app);
		if (!(inf.is_open()))                                          // проверка открытия файлов
		{
			cout << "\nError opening file!!!";
		}
		else
		{
			inf << this->type << endl;
			inf << "x = " << x << endl;
			inf << "y = " << y << endl;
			inf << "a = " << a << endl;
			inf << "b = " << b << endl;
			inf << "r = " << r << endl;
			inf << "" << endl;
		}
		inf.close();

		ofstream inf2("Ellipse_file.txt", ios::app);
		if (!(inf2.is_open()))                                          // проверка открытия файлов
		{
			cout << "\nError opening file!!!";
		}
		else
		{
			inf2 << this->type << endl;
			for (int i = -a; i <= a; i += 2)
			{
				for (int j = -b; j <= b; j += 2)
				{
					if ((i * i) / (a * a) + (j * j) / (b * b) <= 1)  inf2 << "XX";
					else inf2 << "  ";
				}
				inf2 << endl;
			}
		}
		inf2.close();
	}
	string Load() override
	{
		string way;
		ifstream outf;
		outf.open("Ellipse_file.txt");
		if (!(outf.is_open()))
		{
			cout << "\nError opening file!!!";
		}
		else
		{
			while (!(outf.eof()))
			{
				way = " ";
				getline(outf, way);
				cout << way << endl;
			}
			outf.close();
		}
		return way;
	}
	void Show() override
	{
		cout << this->type << " information :" << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "r = " << r << endl;
		cout << "" << endl;
	}
};


int main()
{
	int r;
	int a, b;
	double x, y;
	cout << "Enter sizes -> a, b, r : (5, 10, 5 recommended)\n";
	cin >> a >> b >> r;
	cout << "Enter coordinates -> x, y : (1, 2  recommended)\n";
	cin >> x >> y;


	Shape* figures[4]
	{
		new Square(a, x, y),
		new Rectangle(a, b, x, y),
		new Circle(a, b, r, x, y),
		new Ellipse(a, b, r, x, y)
	};

	for (int i = 0; i < 4; ++i)
		figures[i]->Save();
	cout << endl;
	cout << "Figures are saved \n\n";

	cout << "Show information about figures \n";
	system("pause");
	for (int i = 0; i < 4; ++i)
		figures[i]->Show();
	cout << endl;

	cout << "Show figures \n";
	system("pause");
	for (int i = 0; i < 4; ++i)
		figures[i]->Load();
	cout << endl;
	cout << "////////////////////////////////// \n";
	cout << "Отрисованные фигуры внесены в файл \n";
	cout << "////////////////////////////////// \n";
	return 0;
}
