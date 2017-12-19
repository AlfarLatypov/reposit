//HOME WORK

////#include "stdafx.h"
//#include<iostream>
//#include<fstream>
//#include<string>
//
///*Встреча №23
//Тема: ПросТрансТва Имен
//В рамках предыдущих самостоятельных и домашних зада-
//ний вы создали набор классов по работе со структурами данных
//(списки, деревья и т.д.).
//Разместите уже созданные классы в пространствах имен.
//Продумайте правильную структуру созданных пространств.
//Используя механизм пространств напишите код по-тестированию полученного решения.*/
//
//
//using namespace std;
////Разместите уже созданные классы в пространствах имен. 
//namespace Alfar
//{
//
//	template< typename T >
//	class Node
//	{
//	public:
//		int value;
//		Node *prev, *next;
//
//		Node() {}
//		Node(const T value) {
//			this->value = value;
//			prev = next = NULL;
//		}
//		~Node();
//
//	};
//
//}
//
//namespace Latypov
//{
//	template< typename T >
//	class DoubleLinkedList
//	{
//	public:
//		Alfar::Node<T>*first, *last; //используем Node пространства имен Alfar
//
//		DoubleLinkedList() {
//			first = last = NULL;
//		}
//
//		~DoubleLinkedList() {};
//
//		void AddToTail(const T &value) {
//			if (first == NULL) {
//				last = first = new Alfar::Node<T>(value);
//			}
//			else {
//				Alfar::Node<T> *temp = new Alfar::Node<T>(value);
//				last->next = temp;
//				temp->prev = last;
//				last = temp;
//			}
//		}
//
//		void DeleteFromTail() {
//			last->prev->next = NULL;
//			last = last->prev;
//		}
//
//		void AddToHead(const T & value) {
//			if (first == NULL) {
//				last = first = new Alfar::Node<T>(value);
//			}
//			else {
//				Alfar::Node<T> *temp = new Alfar::Node<T>(value);
//				first->prev = temp;
//				temp->next = first;
//				first = temp;
//			}
//
//		}
//
//		void DeleteFromHead() {
//			first = first->next;
//		}
//
//		void show() {
//			if (first == NULL) {
//				std::cout << "List is empty" << std::endl;
//			}
//			else {
//				for (Alfar::Node<T> * temp = first; temp != NULL; temp = temp->next)
//					std::cout << "\t" << temp->value << "\n";
//			}
//		}
//
//	};
//
//}
//
//
//
//void main() {
//
//	//Продумайте правильную структуру созданных пространств. 
//	Latypov::DoubleLinkedList<int> *a = new Latypov::DoubleLinkedList<int>();
//
//
//	//Используя механизм пространств напишите код по-тестированию полученного решения.
//	a->AddToTail(2);
//	a->AddToTail(3);
//	a->AddToTail(4);
//	a->AddToTail(5);
//	a->AddToTail(6);
//	a->AddToHead(1);
//	a->show();
//	a->DeleteFromTail();
//	cout << endl;
//	a->show();
//	cout << endl;
//
//	a->DeleteFromHead();
//	cout << endl;
//	a->show();
//	cout << endl;
//
//	delete a;
//
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
///*Задание №1
//Реализуйте программу, которая предоставляет функциональ-
//ность по работе с файлами.
//- Приложение получает у пользователя путь к файлу,
//после чего программа отображает интерфейс по анализу содержимого файла.
//Возможности интерфейса:
//¦ Поиск заданной строки (по итогам показывать статистику
//поиска строки по всему файлу);
//¦ Замена строки на новую строку (по итогам показать статисти-
//ку по замене строки);
//¦ Отображение файла на экран;
//¦ Переворот содержимого файла.
//Используйте для работы с файлами потоки, а для работы со
//строками класс string*/
//
//string menu() {
//	string path;
//	cout << "\n\t\t\t Please enter name file - ";
//	getline(cin, path);
//
//	return path;
//}
//
//
//
//void main()
//{
//
//	int choice;
//	string str, find, fpath = menu();
//	size_t pos;
//
//	while (true) {
//		system("cls");
//		cout << "\n\t--------------<< M E N U >>--------------\n";
//		cout << "\n\t[ 1 ] - Push 1 to display the file on the screen"; //¦ Отображение файла на экран
//		cout << "\n\t[ 2 ] - Push 2 to enter data into the file";  //¦ Замена строки на новую строку 
//		cout << "\n\t[ 3 ] - Push 3 to add into file";  //¦ Добписать строки в файл 
//		cout << "\n\t[ 4 ] - Push 4 to find in the file";  //¦ Поиск заданной строки
//		cout << "\n\t[ 5 ] - Push 5 to reverse the file";  //¦ Переворот содержимого файла
//		cout << "\n\t[ 0 ] - Push 0 to EXIT";  //¦ EXIT
//
//
//
//		cout << "\n\n\t     Your choice is - "; cin >> choice;
//
//		ifstream fin(fpath);
//		ofstream fout;
//
//		switch (choice)
//		{
//		case 1:
//			if (fin.is_open())
//				while (getline(fin, str)) { system("cls"); cout << endl << endl << "\t\t" << str << endl << endl << endl << endl; } //¦ Отображение файла на экран
//			else cout << "Ne otkruli";	 system("pause"); break;
//		case 2: fout.open(fpath); cin >> str;//getline(cin, str);                     //¦ Замена строки на новую строку 
//			if (fout.is_open()) { fout << str; }  break;
//		case 3: fout.open(fpath, ios::app); cin >> str;                              //¦ Добписать строки в файл 
//			if (fout.is_open()) { fout << str; }  break;
//		case 4: system("cls");                                                      //¦ Поиск заданной строки
//			cout << "\n\t\twhat to look for? - "; cin >> find;
//			pos = str.find(find);
//			while (getline(fin, str)) { system("cls"); cout << endl << endl << "\t\t" << str << endl; }
//			if (pos != string::npos) { cout << "\n\t\tFound at pos = " << pos + 1 << "\n"; system("pause"); }
//			else { std::cout << "\n\t\tNot found\n"; system("pause"); }
//			break;
//		case 5: system("cls"); cout << "\n\t\t";
//			for (int i = str.size() - 1; i >= 0; --i)
//				std::cout << str[i]; cout << "\n\n"; system("pause"); break;
//		case 0: fin.close(); fout.close(); return;
//
//		}
//	}
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
///*Задание №2
//Создайте приложение «Валидатор HTML-файлов».
//Приложение запрашивает у пользователя путь к файлу,
//после чего проверяет файл на валидность.
//Критерием валидности для вашего проекта являются правила:
//все открытые теги должны закрываться,
//если был знак < его должен закрыть знак >. По итогам валидации
//нужно отобразить результат проверки на экран.
//Используйте для работы с файлами потоки, а для работы со строками класс string.
//
//Примеры:
//Содержимое валидного файла
//<html>
//<body>To be or not to be</body>
//</html>
//Содержимое невалидного файла
//<html>
//<body To be or not to be</body>
//</html>*/
//
//string menu() { //пользователь вводит имя файла куда обращаться и проверять валидность
//	string path;
//	cout << "\n\t\t\t Please enter name file - ";
//	getline(cin, path);
//
//	return path;
//}
//
//
//void main() //задача №2
//{
//
//	int  open = 0, clouse = 0;
//	string str, fpath = menu();
//
//	ifstream fin(fpath); // открываем поток
//
//	if (fin.is_open()) {
//		cout << "\n\t";
//		while (!fin.eof()) { getline(fin, str); cout << str << endl; } //бежим до конца файла и считываем данные в str и выводим на экран
//		cout << "\n\t";
//	}
//	else cout << "Ne otkruli";
//
//
//	for (int i = 0; i < str.length(); i++) { //пробегаем опять по str и считаем теги
//		if (str[i] == '<')	open++;
//		if (str[i] == '>')	clouse++;
//	}
//
//	//если кол-во открытых тегов равно кол-ву закрытых, то всё ок, иначе не всё.
//	//конечно можно наворотить и сделать проверку на логику открытых тегов, и ввести условие что с ">" не может начинаться,
//	//а на "<" не может заканчиваться, но это совсем другая история.
//	(open == clouse) ? cout << "the Valid file. OK!\n\n" : cout << "NOT a Valid file. ERROR!" << endl;
//
//
//	ofstream fout; //на этом этапе можно ввести корректировки в файл, добавить не достающий тег, даже заменить все содержимое
//	fout.open(fpath, ios::app); cin >> str;
//	if (fout.is_open()) { fout << str; }
//
//	fin.close(); fout.close();
//
//}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stream

//
//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
//
//class A {
//public:
//	int value;
//	friend std::ostream & operator << (std::ostream &stream, A& a);
//	friend std::istream & operator << (std::istream &stream, A& a);
//
//};
//
//std::ostream & operator << (std::ostream &stream, A& a)
//{
//	stream << a.value;
//	return stream;
//}
//
//std::istream & operator >> (std::istream &stream, A& a)
//{
//	stream >> a.value;
//	return stream;
//}
//
//int main() {
//	A a ;
//	/*a.value = 5;
//	std::ofstream fout;
//	fout.open("File.txt");
//	fout << a;
//	fout.close();*/
//
//	std::ifstream fin;
//	fin.open("File.txt");
//	fin >> a;
//	cout << a << endl;
//	fin.close();
//
//	return 0;
//}


//STRING

//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
//
//
//void main() {
//	string s, x ="123";
//	s += "hello"; //добавить в конец
//	swap(s, x);
//	reverse(s.begin(), s.end());
//	reverse(x.begin(), x.end());
//	cout << s << " " << x<<endl;
//
//
//}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//SMART POINTERS УМНЫЕ УКАЗАТЕЛИ

//R A I I - объявляем и одновременно инициализируем

/*auto_ptr – умный указатель, который управляет объектом, полученным с помощью оператора new и удаляет этот объект, 
когда auto_ptr будет уничтожен. Данный указатель может быть использован с целью обеспечения безопасности исключений 
для динамически создаваемых объектов, для передачи владения динамически созданными объектами в функции и для возвращения 
динамически созданных объектов из функций.
Копирование auto_ptr копирует указатель и передает владение объекту назначения: конструктор копирования и операция
присваивания копированием auto_ptr изменяют правый аргумент операции, таким образом "копия" становится не равной оригиналу. 
Из-за столь необычного подхода к копированию auto_ptr не может быть помещен в стандартные контейнеры. 
Для этих и других целей предпочтительнее использовать std::unique_ptr.*/


/*std::shared_ptr – умный указатель, с разделяемым владением объектом через его указатель. 
Несколько указателей shared_ptr могут владеть одним и тем же объектом; объект будет уничтожен, когда последний shared_ptr,
указывающий на него, будет уничтожен или сброшен. Объект уничтожается с использованием delete-expression или с использованием
пользовательской функции удаления объекта, переданной в конструктор shared_ptr.

shared_ptr может не владеть ни одним объектом, в этом случае он называется пустым.
shared_ptr отвечает требованиям CopyConstructible и CopyAssignable.

Функции-члены
(конструктор)
создает новый shared_ptr
(public функция-член) [править]
(деструктор)
разрушает объект, которым владеет, если больше нет shared_ptrs ссылающихся на него
(public функция-член) [править]
operator=
задает значение shared_ptr
(public функция-член) [править]
Модификаторы
reset
заменяет объект, которым владеет
(public функция-член) [править]
swap
обмен содержимым
(public функция-член) [править]
Наблюдатели
get
возвращает указатель на управляемый объект


(public функция-член) [править]
operator*
operator->
разыменовывает указатель на управляемый объект


(public функция-член) [править]
use_count
возвращает количество объектов shared_ptr, которые ссылаются на тот же управляемый объект
(public функция-член) [править]
unique
проверяет, контролируется ли управляемый объект единственно текущим объектом shared_ptr
(public функция-член) [править]
operator bool
проверяет, указывает ли указатель на объект
(public функция-член) [править]
owner_before
предоставляет владельцу на основе упорядочения общих указателей


(public функция-член)
*/

/*std::unique_ptr – умный указатель, который:

получает единоличное владение объектом через его указатель, и
разрушает объект через его указатель, когда unique_ptr выходит из области видимости.
unique_ptr не может быть скопирован или задан через операцию присвоения, два экземпляра unique_ptr не могут 
управлять одним и тем же объектом. Неконстантный unique_ptr может передать владение управляемым объектом другому 
указателю unique_ptr. const std::unique_ptr не может быть передан, ограничивая время жизни управляемого объекта областью,
в которой указатель был создан. Когда unique_ptr уничтожается, он удаляет объект с помощью Deleter.

Существует две версии std::unique_ptr:

1) управляет временем жизни одного объекта, например, созданного с помощью оператора new

2) управляет временем жизни массива, с длиной, определенной во время выполнения, созданного с помощью new[]

Типичные случаи применения std::unique_ptr включают:

обеспечение безопасности исключений для классов и функций, которые управляют объектами с динамическим временем жизни,
гарантируя удаление в случае нормального завершения и завершения по исключению
передача владения динамически созданным объектом в функции
получение владения динамически созданным объектом из функций
в качестве типа элемента в контейнерах, поддерживающих семантику перемещения, таких как std::vector, которые хранят 
указатели на динамически выделенные объекты (например, если желательно полиморфное поведение)*/



//#include<memory>
//#include<iostream>
//using namespace std;
//
// class A {
//	public:
//		A() { cout << "\n     CREATE - A()" << endl; }
//		~A() { cout << "     DELETE - ~A()" << endl << endl << endl; }
//		int value;
//		
//	
//	};
//
// //удаляется сразу как вышли из ф-ции
//void auto_pt() {
//
//	auto_ptr<A> a(new A());
//	a->value = 5;
//	auto_ptr<A> b = a; //не дает копировать, как только б стало равно а, А удаляется
//	cout << "\n\t" << b->value << endl << endl;
//}
//
////проверяет весь код и считает кол-во ссылок на указатель Х
//void shared_pt() {
//
//	shared_ptr<int> x(new int(5));
//	cout <<  "   Use pointer - "<<x.use_count() << endl << endl;
//	shared_ptr<int> y = x;
//	cout << "   Use pointer - " << y.use_count() << endl << endl;
//
//}
//
//
//void sum (shared_ptr<int> & x){
// cout << "   Use pointer - " << x.use_count() << endl << endl;
//}
//
//
//
//void unique_pt() {
//
//	unique_ptr<int> x(new int(5));
//	
//}
//
//void main() {
//	shared_ptr<int> bbb(new int(777));
//	auto_pt();
//	shared_pt();
//	sum(bbb);
//
//}


#include <algorithm>
#include <iostream>
#include <string>
#include <set>

//int main()
//{
//	std::string str = "apple";
//	std::sort(str.begin(), str.end());
//	std::cout <<"Povtoryaetsya bukva - "<< *std::unique(str.begin(), str.end());
//	std::cout << std::endl;
//}
//
//
int main() {
	std::string x = "1233";
	std::getline(std::cin, x);
	std::set<char> y;

	for (size_t i = 0; i < x.length(); ++i) {
		if (y.find(x[i]) != y.end()) {
			std::cout << "not unique" << std::endl;
			break;
		}
		else y.insert(x[i]);
	}
}


