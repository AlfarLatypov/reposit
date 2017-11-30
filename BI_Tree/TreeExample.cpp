//// Latypov_Alfar.cpp : Defines the entry point for the console application.
////
//
////#include "stdafx.h"
//#include <stdio.h>
//#include <tchar.h>
//#include <iostream>
//#include <iomanip>
//#include <conio.h>
//
//
//using namespace std;
//
///*Задания для самостоятельной работы:
//Задание №1
//Реализуйте класс стека для работы с символами (символьный стек).       (+)
//--Стек должен иметь фиксированный размер.                              (+)
//Также реализуйте набор операций для работы со стеком:                  (+)
//--помещение символа в стек,                                            (+)
//--выталкивание символа из стека,                                       (+)
//--подсчет количества символов в стеке,
//--проверку пустой ли стек,
//--проверку полный ли стек,
//--очистку стека,
//--получение без выталкивания верхнего символа в стеке.
//Задание №2
//Измените стек из первого задания со статического типа на динамический (при нехватке
//свободного места нужно изменить размер внутреннего массива без потери данных).*/
//
////_________________________________________________________________________________________________________________+
//
//
//enum MENU { SHOW_ALL = 1, AUTO, ADD_ONE, SHOW_ONE, DELETE_ONE, DELETE_ALL };
//
//template <typename T> //шаблонный тип
//					  //Implement the stack class to work with characters (character stack).
//					  //Реализуйте класс стека для работы с символами (символьный стек).
//class Stack
//{
//	T* stack; //динамический
//	int size = 5;  //The stack must have a fixed size. (Стек должен иметь фиксированный размер.)
//				   //counting the chars in the stack
//	int top; //подсчет количества символов в стеке
//
//public:
//	Stack();
//	~Stack();
//
//	//-------- набор операций для работы со стеком: ------------------------------------------------------------
//	//implement a set of operations for working with the stack:
//
//	//putting the char on the stack
//	void push(const T&); //The Push function takes an object from the class T(ф-ция Пуш принимает в себя объект от класса Т)
//						 //pushing a char out of the stack
//	T pop(); //ф-ция Pop вытаскивает верхний объект из массива Стэк(удаляет)
//
//	inline friend void showStack(T &);
//	//--------Геттеры и Сетторы------------------------------------------------------------------------------------
//	int getTop() { //Инспектор кол-ва элементов стэка
//		return top;
//	}
//	void setTop(int top) {
//		this->top = top;
//	}
//
//	int getSize() { //Инспектор размера стэка
//		return size;
//	}
//
//	void setSize(int size) { //Модификатор размера стэка
//		this->size = size;
//	}
//	//-------------------------------------------------------------------------------------------------------------
//
//
//
//
//};
//
//template <typename T>
//Stack<T>::Stack() {
//	stack = new T[size];
//	top = 0;
//}
//template <typename T>
//Stack<T>::~Stack() {
//	delete[] stack;
//}
//template <typename T>
//void Stack<T>::push(const T &element) {
//	if (top + 1 <= size) {
//		stack[++top] = element; //динамический массив стэк принимает значение маленького т,  топ инкреминируем
//	}
//}
//template <typename T>
//T Stack<T>::pop() { //ф-ция Pop вытаскивает верхний объект из массива Стэк(удаляет)
//	if (top > 0) {    //проверкa пустой ли стек, проверкa полный ли стек
//		top--; //спускаемся на ступень ниже
//		return stack[top + 1]; //вернем верхний удаленный элемент, на этом этапе топ остается 2кой
//	}
//}
//
//template <typename T>
//void showStack(Stack<T> &stack) {
//	cout << "\n\n\t\t\tNumber in\tStack";
//	cout << "\n\t      Char\tthe Stack\tsize\n\t    ------------------------------------  \n";
//
//	for (int i = 0; i <stack.getSize(); i++)
//		cout << "\t\t" << stack.pop() << "\t     " << stack.getTop() << "\t\t " << stack.getSize() << endl;
//	cout << "\n\n";
//}
//
//template <typename T>
//void addInStack(Stack<T> &t, T &element) {
//	//отправляем символы в стэк
//	for (int i = 0; i <t.getSize(); i++, element--)
//		t.push(element);
//
//}
//
//int Menu() {
//	cout << "\n\n\t\t------------<< M E N U >>---------------\n";
//	cout << "\n\t\tPress [1] to show show items in the stack"; //нажмите 1 чтобы вывести на экран содержимое стэка
//	cout << "\n\t\tPress [2] to automatically fill the stack"; //нажмите 2 чтобы автоматически заполнить стэк
//	cout << "\n\t\tPress [3] to add an item to the stack"; //нажмите 3 чтобы добавить элемент в стэк
//	cout << "\n\t\tPress [4] to to show the specific item in the stack"; //нажмите 4 чтобы показать определенный элемент в стэка
//	cout << "\n\t\tPress [5] to delete the item from the stack"; //нажмите 5 чтобы удалить элемент из стэка
//	cout << "\n\t\tPress [6] to clear the stack"; //нажмите 6 чтобы очистить стэк
//	cout << "\n\t\tPress [0] to EXIT"; //выход из программы
//	cout << "\n\n\t\t----------------------------------------\n";
//	cout << "\n\n\t\tYour choice is - ";
//	int choice;
//	cin >> choice;
//	return choice;
//
//	system("cls");
//
//}
//
////enum MENU{SHOW_ALL=1, AUTO, ADD_ONE, SHOW_ONE, DELETE_ONE, DELETE_ALL};
//template <typename T>
//void StartProgramm(Stack<T> &stack, T &chr) {
//
//
//
//	while (true) {
//		system("cls");
//		switch (Menu()) {
//		case SHOW_ALL: system("cls"); showStack(stack); _getch(); system("cls"); break;//стек на экран
//		case AUTO: system("cls"); addInStack(stack, chr); showStack(stack); _getch(); break;//отправляем символы в стэк
//		case ADD_ONE: showStack(stack); cout << "\t\tEnter the symbol - "; cin >> chr;       stack.push(chr); showStack(stack); _getch(); break;
//		case SHOW_ONE: break;
//		case DELETE_ONE: break;
//		case DELETE_ALL: break;
//		case 0:  system("cls"); return;
//		}
//	}
//
//}
//
//void main() {
//
//	Stack<char> stack; //Символьный стэк
//	char chr = 'e';
//
//	StartProgramm(stack, chr);
//
//
//}


//____________________________________________________________________________________________________________________


#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "TREE.h"

using namespace std;






void main() {



}