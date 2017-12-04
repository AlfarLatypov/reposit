#include <iostream>
using namespace  std;

//-------------Классы в классах---------------------------------------------------------------------

//class List {
//public:
//	class Element {
//	public:
//		int value;
//		Element *next;
//		Element() {}
//		Element(const int value) {
//			this->value = value;
//			next = NULL;
//		}
//		~Element() {}
//		
//
//	};
//
//	Element *first;
//	
//	List() {
//		first = NULL;
//	}
//	~List() {}
//
//	void AddToList(const int &value) {
//			if (first == NULL) {
//				first = new Element(value);
//			}
//			else {
//				Element *temp = first;
//				while (temp->next != NULL) {//если не ноль
//					temp = temp->next;//переходим к следующему элементу
//				}
//				temp->next = new Element(value); //как вышли из цикла создаем новый элемент
//				
//			}
//		}
//
//	void show() {
//				int i = 0;
//				if (first == NULL) {
//					std::cout << "List is empty" << std::endl;
//				}
//				else {
//					std::cout << "\n";
//					for (Element * temp = first; temp != NULL; temp = temp->next, i++) {
//						std::cout << "\t" << i + 1 << " - " << temp->value << "\n";
//					}std::cout << "\n";
//				}
//			}
//	
//};
//
//
//
//void main() {
//	List  *a = new List;
//
//	a->AddToList(5);
//	a->AddToList(7);
//	a->AddToList(9);
//	a->AddToList(3);
//	a->show();
//}


//-------------Наследование---------------------------------------------------------------------

////базовый - base class
//class Student {
//public:
//	int x;
//
//	Student() {
//		cout << "Student()" << endl;
//	}
//
//	~Student() {
//		cout << "~Student()" << endl;
//	}
//	
//};
//
////дочерний - derived class
//class Master:public Student {
//public:
//	void show() { cout << x; }
//	Master() {
//		cout << "Master()" << endl;
//	}
//
//	~Master() {
//		cout << "~Master()" << endl;
//	}
//
//};
//
//
//void main() {
//	/*Student *a;
//	a = new Master();
//	delete a;*/
//	
//	Master *a;
//	a = new Master();
//	delete a;
//
//}

//-----------Одиночное наследование----------------------------------------------------------------------

//class Human {
//public:
//	
//	Human() {
//		cout << "Human()" << endl;
//	}
//
//	~Human() {
//		cout << "~Human()\n" << endl;
//	}
//
//};
//
//
//class Student:public Human {
//public:
//	
//	Student() {
//		cout << "Student()" << endl;
//	}
//
//	~Student() {
//		cout << "~Student()\n" << endl;
//	}
//
//};
//
//class Cop:public Human {
//public:
//
//	Cop() {
//		cout << "Cop()" << endl;
//	}
//
//	~Cop() {
//		cout << "~Cop()\n" << endl;
//	}
//
//};
//
//void main() {
//	
//
//	//Cop *c = new Cop();
//
//	//Student *s = new Student();
//
//	Human *h1 = new Student();
//
//	Human *h2 = new Cop();
//	
//
//	delete  h1, h2;
//
//}



//-----------Множественное наследование----------------------------------------------------------------------

class Mammal {
public:
	Mammal() {
		cout << "Mammal()" << endl;
	}
	~Mammal() {
		cout << "~Mammal()\n" << endl;
	}

	virtual void move() = 0; //все обязаны наследовать ф-цию мув, тут реализации нет, в другом классе реализация мува
};



class Human:public Mammal {
public:
	Human() {
		cout << "Human()" << endl;
	}
	~Human() {
		cout << "~Human()\n" << endl;
	}
	void move() {
		cout << "Human mooves\n";
	}
};


class Hourse : public Mammal {
public:
	Hourse() {
		cout << "Hourse()" << endl;
	}
	~Hourse() {
		cout << "~Hourse()\n" << endl;
	}
	void move() {
		cout << "horse mooves\n";
	}
};

class Centaur:public Human, public Hourse {
public:
	Centaur() {
		cout << "Centaur()" << endl;
	}
	~Centaur() {
		cout << "~Centaur()\n" << endl;
	}
};

void main() {
Centaur *h1 = new Centaur();
h1->Human::move();//явно указал чей мув использовать
delete  h1;

}


