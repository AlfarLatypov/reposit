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




#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string menu() {
	string path;
	cout << "\n\t\t\t Please enter name file - ";
	getline(cin, path);

	return path;
}



void main()
{

	int choice;
	string str, find, fpath = menu();
	size_t pos;

	while (true) {
		system("cls");
		cout << "\n\t--------------<< M E N U >>--------------\n";
		cout << "\n\t[ 1 ] - Push 1 to display the file on the screen"; //¦ Отображение файла на экран
		cout << "\n\t[ 2 ] - Push 2 to enter data into the file";  //¦ Замена строки на новую строку 
		cout << "\n\t[ 3 ] - Push 3 to add into file";  //¦ Добписать строки в файл 
		cout << "\n\t[ 4 ] - Push 4 to find in the file";  //¦ Поиск заданной строки
		cout << "\n\t[ 5 ] - Push 5 to reverse the file";  //¦ Переворот содержимого файла
		cout << "\n\t[ 0 ] - Push 0 to EXIT";  //¦ EXIT



		cout << "\n\n\t     Your choice is - "; cin >> choice;

		ifstream fin(fpath);
		ofstream fout;

		switch (choice)
		{
		case 1:
			if (fin.is_open())
				while (getline(fin, str)) { system("cls"); cout << endl << endl << "\t\t" << str << endl << endl << endl << endl; } //¦ Отображение файла на экран
			else cout << "Ne otkruli";	 system("pause"); break;
		case 2: fout.open(fpath); cin >> str;//getline(cin, str);                     //¦ Замена строки на новую строку 
			if (fout.is_open()) { fout << str; }  break;
		case 3: fout.open(fpath, ios::app); cin >> str;                              //¦ Добписать строки в файл 
			if (fout.is_open()) { fout << str; }  break;
		case 4: system("cls");                                                      //¦ Поиск заданной строки
			cout << "\n\t\twhat to look for? - "; cin >> find;
			pos = str.find(find);
			while (getline(fin, str)) { system("cls"); cout << endl << endl << "\t\t" << str << endl; }
			if (pos != string::npos) { cout << "\n\t\tFound at pos = " << pos + 1 << "\n"; system("pause"); }
			else { std::cout << "\n\t\tNot found\n"; system("pause"); }
			break;
		case 5: system("cls"); cout << "\n\t\t";
			for (int i = str.size() - 1; i >= 0; --i)
				std::cout << str[i]; cout << "\n\n"; system("pause"); break;
		case 0: fin.close(); fout.close(); return;

		}
	}
}


