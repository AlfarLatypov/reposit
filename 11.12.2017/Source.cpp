#include <iostream>
using namespace  std;


/*—оздайте абстрактный базовый класс Employer (служащий) с чисто виртуальной ф-цией Print().
—оздайте  три произвольных класса: President, Manager, Worker. ѕереопределите ф-цию Print()
дл€ вывода ин-ции, соответствующей каждому типу служащего.*/

class Employer
{
public:
	Employer();
	~Employer();

	virtual void Print() = 0;

};

Employer::Employer()
{
}

Employer::~Employer()
{
}

void Employer::Print()
{
}


class President:public Employer {
public:
	President();
	~President();

	void Print() override {
		cout << "I`m President" << endl;
	};

};

President::President()
{
}

President::~President()
{
}


class Manager :public Employer {
public:
	Manager();
	~Manager();

	void Print() override {
		cout << "I`m Manager" << endl;
	};

};

Manager::Manager()
{
}
Manager::~Manager()
{
}


class Worker :public Employer {
public:
	Worker();
	~Worker();

	void Print() final {
		cout << "I`m Worker" << endl;
	};

};

Worker::Worker()
{
}
Worker::~Worker()
{
}



void main() {
	Employer *a = new President();
	Employer *b = new Manager();
	Employer *c = new Worker();

	a->Print();
	b->Print();
	c->Print();

	delete a;
	delete b;
	delete c;

}


