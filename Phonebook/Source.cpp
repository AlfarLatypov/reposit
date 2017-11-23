#include <iostream>
#include <string>

using namespace std;

//class Test {
//	int x;
//	
//};
//
//
//class Integer {
//public:
//	int value;
//	//_______________________________________________________________________________________________
//    explicit Integer() {}
//	explicit Integer(int x) : value(x) {}//перегрузили присвоение  //явное делегирование  х(5)
//   //_______________________________________________________________________________________________
//	Integer& operator = (const int& x) // х = 5
//	{
//		value = x;                      //перегрузили присвоение 
//		return *this;
//	}
//	//_______________________________________________________________________________________________
//	//lvalue vs rvalue - &, &&
//	Integer& operator +(Integer& x) { //перегрузили плюс
//		Integer y(this->value + x.value); //a+b - у а вызвали ф-цию + и отправили (b)
//		return y;
//	}
//	//_______________________________________________________________________________________________
//	Integer& operator -(Integer& x) { //перегрузили минус
//		Integer y(this->value - x.value);
//		return y;
//	}
//	//_______________________________________________________________________________________________
//	//префикс
//	Integer& operator ++() {
//		++this->value;
//		return *this;
//	}
//	//постфикс
//	Integer& operator ++(int) {  //(int) - означает что мы испльзуем постфиксный 
//		Integer old(value);
//		++value;
//		return old;
//	}
//	//_______________________________________________________________________________________________
//
//	bool operator == (const Integer& x) {
//		return value == x.value;
//	}
//	bool operator != (const Integer& x) {
//		return value != x.value;
//	}
//	bool operator < (const Integer& x) {
//		return value < x.value;
//	}
//	bool operator > (const Integer& x) {
//		return value > x.value;
//	}
//	//_______________________________________________________________________________________________
//	//конструктор переноса (переносит значения в новый объект а старый удаляет)
//	/*explicit Integer(const Integer&& i) {
//		Integer(i);
//	}*/
//
//	////конструктор переноса (переносит значения в новый объект а старый удаляет)
//	// explicit Integer(const Integer&& i) {
//	//	value = move(i.value);
//
//	//}
//
//	//конструктор переноса
//	//&& -двойная ссылка - значит что объект передаваемый по ссылке будет уничтожен при выходе из ф-ции
//	/*explicit Integer(const Integer&& i) {
//		value = i.value;
//	}*/
//	//_______________________________________________________________________________________________
//	// explicit Integer() = delete;
//
//	 //_______________________________________________________________________________________________
//
//	 Integer& operator [] (int i) {}
//
//	 Integer& operator () (int i) {}
//	
//	 //_______________________________________________________________________________________________
//
//	 //перегрузка преобразования типов
//	 explicit operator double() {
//		 return value;
//	 }
//	 explicit operator int() {
//		 return value;
//	 }
//	 explicit operator char() {
//		 return value;
//	 }
//	 //_______________________________________________________________________________________________
//
//	 friend void print(Integer& i);
//	 friend void test(Integer& i);
//	 friend class Test;
//
//	 //_______________________________________________________________________________________________
//	 friend ostream& operator <<(ostream& os, Integer& x);
//
//
//
//};
//
//ostream& operator <<(ostream& os, Integer& x) {
//	os << x.value << endl;
//	return os;
//}
//
//
//void print(Integer& i) {
//	cout << i.value << endl;
//}
//
//void test(Integer& i) {
//	Integer &x = i + Integer(6);
//}
//
//
//
//
//
//class Progression {
//public:
//	int a1, d;
//
//	Progression(int a1, int d) {
//		this->a1 = a1;
//		this->d = d;
//	}
//
//	int operator [] (int i) {
//		return a1 + (i - 1) * d;
//	}
//	int  operator () (int i) {
//
//		return (2 * a1 + d * (i - 1)) * i / 2;
//	}
//
//};
//
//
////T(n^2) где Т это время, М(1) - это занимаемая память
////T(fib) -> O(n^2)
//int fibo1(int n) {  //Рекурсивный вызов функции f(n) = f(n-1) + f(n-2)
//	if (0 == n || 1 == n) return n;
//	else return fibo1(n - 1) + fibo1(n - 2);		
//}
//
////T(n) где Т это время, М(n) - это занимаемая память, больше чем у рекурсии, но время экономит
//int fibo2(const int n) {//Циклами f(n) = f(n-1) + f(n-2)
//	int *a = new int[n + 1];
//	a[0] = 1;
//	a[1] = 1;
//	for (int i = 2; i < n + 1; i++) {
//		a[i] = a[i - 1] + a[i - 2];
//	}
//	int res = a[n - 1];
//	delete a;
//	return res;
//}
//
////асимтотическое время работы прочесть
//
//int main() {
//
//	//Integer c, a(5), b(6);
//
//	//c = a + b; //Integer c =a.+(b)
//	//c = a - b;
//	//++c.value;
//	/*cout << c.value << endl;
//	cout << c++.value << endl;
//	cout << ++c.value << endl;
//	cout << c.value << endl;*/
//	//Integer c(6), a(5), b(5);
//	//cout << (a == b) << endl; //true
//	//cout << (a == c) << endl; //false
//	//return 0;
//
//	//for (int i = 0; i<20; i++) 
//	//	cout << "fibonacci " << i << " ==> " << fibo1(i) << '\n';	//нерекурсивный вызов fibo(i)
//		
//	//cout << fibo2(6)<<endl;
//
//	/*Integer a(1);
//	Integer b = move(a);*/
//
//	/*Progression p(5,2 );
//	cout << p[5] << endl;
//	cout << p(5) << endl;*/
//
//	//Integer a(5);
//	////double x;
//	////char x;
//	//int x;
// //     x = (double) a;
//	//cout << x << endl;
//
//	Integer x(5);
//	//print(x);
//	cout << x;
//
//
//}


//class Date {
//public:
//	int *day, *month, *year;
//
//	Date() {};
//	Date(int day, int month, int year) {
//		this->day = new int(day);
//		this->month = new int(month);
//		this->year = new int(year);
//	};
//
//	~Date() {
//		delete day, month, year;
//	}
//
//	void print() {
//		cout << *day << "/" << *month << "/" << *year << endl;
//
//	}
//
//	friend int operator - (const Date& d1, const Date& d2);
//
//};
//
//int operator - (const Date& d1, const Date& d2) {
//	return ((*d1.day) + ((*d1.month) * 30) + ((*d1.year) * 365)) - 
//		((*d2.day) + ((*d2.month) * 30) + ((*d2.year) * 365));
//}
//
//
//
//void main() {
//	Date d1(4, 6, 1981);
//	d1.print();
//	Date d2(22, 11, 2017);
//	d2.print();
//	cout << d2 - d1 << endl;
//
//}



class Circle {
public:
	int *R, *Len;
	Circle() {};
	Circle(int R, int Len) {
		this->R = new int (R);
		this->Len = new int (Len);
	}
	~Circle() {
			delete R, Len;
		}

	friend bool operator == (const Circle& d1, const Circle& d2);
	friend int operator > (const Circle& C1, const Circle& C2);

};

bool operator == (const Circle& C1, const Circle& C2) {
	if (*C1.R == *C2.R)  return true; 
	return false;
	}

int operator > (const Circle& C1, const Circle& C2) {
	if (C1.R > C2.R)  return 1;
	return 0;
}

void main(){
	Circle a(6, 25);
	Circle b(5, 25);
	cout << (a == b) << endl;
	cout << (b > a) << endl;
}

void main() {
}