#include<iostream>
using namespace std;

class Book
{
	char* name;
	int pages;
public:
	Book(const char* n);
	Book(const char* n, int p);
	void Print();
	~Book();
};

class Student
{
	char* name;
	const double step;
	Book book;
public:
	Student();
	Student(const char* n, const double st, const char* bookName, int bookPages);
	~Student();
	void Print();

};

Book::Book(const char* n)
{
	if (name != nullptr)
	{
		delete[]name;
	}
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

Book::Book(const char* n, int p) :Book(n)
{
	pages = p;
}

void Book::Print()
{
	cout << "Kniga: " << name << "\tPages: " << pages;
}

Book::~Book()
{
	delete[]name;
}

Student::Student() :step(0), book(nullptr, 0)
{
	name = nullptr;
}

Student::Student(const char* n, const double st, const char* bookName, int bookPages) :step(st), book(bookName, bookPages)
{
	if (name != nullptr)
	{
		delete[]name;
	}
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

Student::~Student()
{
	delete[]name;
}

void Student::Print()
{
	cout << "Student: " << name << "\tStep: " << step << '\t';
	book.Print();
}

int main()
{
	Book obj1("Orudie Vermahta", 420);
	obj1.Print();
	cout << endl;
	Student obj2("Hans", 3500, "Orudie Vermahta", 420);
	obj2.Print();
}