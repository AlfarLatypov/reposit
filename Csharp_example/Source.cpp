#include <iostream>
#include <string>
using namespace  std;


//class A {
//public:
//	A() { cout << " A() " << endl; }
//	virtual ~A() { cout << " ~A() " << endl; }
//	virtual void say() { cout << " I`m A " << endl; }
//};
//
//class B:public A {
//public:
//	B() { cout << " B() " << endl; }
//	~B() { cout << " ~B() " << endl; }
//	void say() { cout << " I`m B " << endl; }
//};

//_____________________________________________________________________________________________________

//class IProgrammer {
//public:
//
//	IProgrammer(){}
//	virtual void usePC() = 0; // = 0 значит что нет реализации нигде
//	virtual string doReport() = 0;
//
//
//};
//
//class Woker:public IProgrammer {
//public:
//	Woker(){}
//	~Woker() {}
//	void usePC() {
//		cout << "I use PC" << endl;
//	}
//	string doReport() {
//		return "Job is done";
//	}
//};
//
//
//
//
//
//void main() {
//	IProgrammer *a = new Woker();
//
//
//
//
//
//	//A **a = new A*[2];
//	//a[0] = new B();
//	//a[1] = new A();
//	//for (int i = 0; i < 2; i++)
//	//	a[i]->say();
//	//
//	////A*b =new B();
//}

//_____________________________________________________________________________________________________



/*Создать базовый класс список.
Реализовать на базе списка стек и очередь
с виртуальными ф-циями вставки и вытаскивания.*/


//class List {
//public:
//	List() {}
//	virtual ~List() {}
//	virtual int remove() = 0;
//	virtual void add(const int &) = 0;
//};
//
//class Stack :public List {
//	int *stack;
//	const int size = 1048576;
//	int top;
//public:
//	Stack() {
//		stack = new int[size];
//		top = 0;
//	}
//	~Stack() {
//		delete[] stack;
//	}
//	void push(const int &value) {
//		if (top + 1 <= size) {
//			stack[++top] = value;
//		}
//	}
//	int pop() {
//		if (top > 0) {
//			top--;
//		}
//		return stack[top + 1];
//	}
//	void add(const int &value) {
//		push(value);
//	}
//	int remove() {
//		return pop();
//	}
//};
//
//class Queue :public List
//{
//	int *queue;
//	const int size = 1048576;
//	int first, last, cnt;
//public:
//	Queue() {
//		queue = new int[size];
//		first = last = cnt = 0;
//	}
//	~Queue() {
//		delete[] queue;
//	}
//	void enqueue(const int &value) {
//		if (cnt < size) {
//			queue[last++] = value;
//			++cnt;
//			if (last > size) {
//				last -= size + 1;
//			}
//		}
//	}
//	int dequeue() {
//		if (cnt > 0) {
//			int temp = queue[first++];
//			--cnt;
//			if (first > size) {
//				first -= size + 1;
//			}
//			return temp;
//		}
//	}
//	int remove() {
//		return dequeue();
//	}
//	void add(const int &value) {
//		enqueue(value);
//	}
//};
//int main()
//{
//	
//	List *stack = new Stack();
//	List *queue = new Queue();
//	stack->add(1);
//	stack->add(2);
//	cout << stack->remove() << endl;
//	cout << stack->remove() << endl;
//	queue->add(1);
//	queue->add(2);
//	cout << queue->remove() << endl;
//	cout << queue->remove() << endl;
//	delete stack;
//	delete queue;
//	return 0;
//}


class Pet {
public:
	string name, type;
	virtual void Sound() = 0;
	virtual void  Show() = 0;
	Pet(){}
	virtual~Pet() {}
};

class Dog: public Pet
{

public:
	Dog(string name, string type) {
		this->name = name;
		this->type = type;
	}
	~Dog(){}
	void  Sound() {
		cout << "Gav-gav!!!" << endl;
	}
	void  Show() {
		cout << name << " " << type << endl;
	}

};

class Cat : public Pet
{
public:
	Cat(string name, string type) {
		this->name = name;
		this->type = type;
	}
	~Cat() {}
	void  Sound() {
		cout << "Myau-Myau!!!" << endl;
	}
	void  Show() {
		cout << name << " " << type << endl;
	}

};

class Parrot : public Pet
{
public:
	Parrot(string name, string type) {
		this->name = name;
		this->type = type;
	}
	~Parrot() {}
	void  Sound() {
		cout << "Chirik-Chirik!!!" << endl;
	}
	void  Show() {
		cout << name << " " << type << endl;
	}

};


class Hamster : public Pet
{
public:
	Hamster(string name, string type) {
		this->name = name;
		this->type = type;
	}
	~Hamster() {}
	void  Sound() {
		cout << "Hom-Hom!!!" << endl;
	}
	void  Show() {
		cout << name << " " << type << endl;
	}

};
void main() {
	Pet *dog = new Dog("Tuzik", "Bolonka");
	dog->Sound();
	dog->Show();
	cout << endl;

	Pet *cat = new Cat("Catty", "Siamscaya");
	cat->Sound();
	cat->Show();
	cout << endl;

	Pet *parrot = new Parrot("Gosha", "Volnistuy");
	parrot->Sound();
	parrot->Show();
	cout << endl;

	Pet *hamster = new Hamster("Homma", "Russkii");
	hamster->Sound();
	hamster->Show();
	cout << endl;

	delete dog;
	delete cat; 
	delete parrot; 
	delete hamster;
	
}