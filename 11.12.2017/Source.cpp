#include <iostream>
#include <math.h>
using namespace  std;


/*Создайте абстрактный базовый класс Employer (служащий) с чисто виртуальной ф-цией Print().
Создайте  три произвольных класса: President, Manager, Worker. Переопределите ф-цию Print()
для вывода ин-ции, соответствующей каждому типу служащего.*/

//class Employer
//{
//public:
//	Employer();
//	~Employer();
//
//	virtual void Print() = 0;
//
//};
//
//Employer::Employer()
//{
//}
//Employer::~Employer()
//{
//}
//void Employer::Print()
//{
//}
//
//
//class President:public Employer {
//public:
//	President();
//	~President();
//
//	void Print() override {
//		cout << "I`m President" << endl;
//	};
//
//};
//President::President()
//{
//}
//President::~President()
//{
//}
//
//
//class Manager :public Employer {
//public:
//	Manager();
//	~Manager();
//
//	void Print() override {
//		cout << "I`m Manager" << endl;
//	};
//
//};
//Manager::Manager()
//{
//}
//Manager::~Manager()
//{
//}
//
//
//class Worker :public Employer {
//public:
//	Worker();
//	~Worker();
//
//	void Print() final {
//		cout << "I`m Worker" << endl;
//	};
//
//};
//Worker::Worker()
//{
//}
//Worker::~Worker()
//{
//}
//
//void main() {
//	Employer *a = new President();
//	Employer *b = new Manager();
//	Employer *c = new Worker();
//
//	a->Print();
//	b->Print();
//	c->Print();
//
//	delete a;
//	delete b;
//	delete c;
//
//}



//class Figure {
//public:
//	Figure(){}
//	virtual~Figure() {}
//	virtual float getAria() = 0;
//	virtual void print() = 0;
//};
//
//
//class Rectangle :public Figure {
//	float width, height;
//public:
//	Rectangle(){}
//	~Rectangle() {}
//	Rectangle(float width, float height)  {
//		this->width = width;
//		this->height = height;
//	}
//	
//	float getAria() override { //override не даст наследникам от Rectangle наследовать ф-цию getAria
//		return width * height;	}
//
//	void print() {
//		cout << (width * height) << endl;
//	}
//
//};
//
//
//class Circle :public Figure {
//	float radius;
//public:
//	Circle() {}
//	~Circle() {}
//	Circle(float radius) {
//		this->radius = radius;
//	}
//
//	float getAria() override { //override не даст наследникам от Rectangle наследовать ф-цию getAria
//		
//		return pow(radius,2) * 3.14;
//	}
//	void print() {
//		cout << (pow(radius, 2) * 3.14) << endl;
//	}
//};
//
//
//
//void main() {
//
//	Figure **arr = new Figure*[2]; //массив ссылок на абстрактный класс
//	arr[0] = new Rectangle(3,2); 
//	arr[1] = new Circle(2);
//
//	for (size_t i = 0; i < 2; i++){
//		arr[i]->print();
//	}
//
//	for (size_t i = 0; i < 2; i++) {
//		delete arr[i];
//	}
//	delete[] arr;
//}



class MyException : public exception {
public:
	virtual const char * what() const {
		return "No division by zero is allowed";
	}

};

float divide(float a, float b) {
	if (b == 0) {
		throw MyException();
	}
	else
		return a / b;
}

int main()
{
	try { // если реализация не сработала, то catch (лови)
		divide(2, 0);

	}
	catch (MyException e) {
		cout << e.what() << endl; // вывод ошибки
	}
	return 0;
}











