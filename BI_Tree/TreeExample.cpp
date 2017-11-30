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
///*������� ��� ��������������� ������:
//������� �1
//���������� ����� ����� ��� ������ � ��������� (���������� ����).       (+)
//--���� ������ ����� ������������� ������.                              (+)
//����� ���������� ����� �������� ��� ������ �� ������:                  (+)
//--��������� ������� � ����,                                            (+)
//--������������ ������� �� �����,                                       (+)
//--������� ���������� �������� � �����,
//--�������� ������ �� ����,
//--�������� ������ �� ����,
//--������� �����,
//--��������� ��� ������������ �������� ������� � �����.
//������� �2
//�������� ���� �� ������� ������� �� ������������ ���� �� ������������ (��� ��������
//���������� ����� ����� �������� ������ ����������� ������� ��� ������ ������).*/
//
////_________________________________________________________________________________________________________________+
//
//
//enum MENU { SHOW_ALL = 1, AUTO, ADD_ONE, SHOW_ONE, DELETE_ONE, DELETE_ALL };
//
//template <typename T> //��������� ���
//					  //Implement the stack class to work with characters (character stack).
//					  //���������� ����� ����� ��� ������ � ��������� (���������� ����).
//class Stack
//{
//	T* stack; //������������
//	int size = 5;  //The stack must have a fixed size. (���� ������ ����� ������������� ������.)
//				   //counting the chars in the stack
//	int top; //������� ���������� �������� � �����
//
//public:
//	Stack();
//	~Stack();
//
//	//-------- ����� �������� ��� ������ �� ������: ------------------------------------------------------------
//	//implement a set of operations for working with the stack:
//
//	//putting the char on the stack
//	void push(const T&); //The Push function takes an object from the class T(�-��� ��� ��������� � ���� ������ �� ������ �)
//						 //pushing a char out of the stack
//	T pop(); //�-��� Pop ����������� ������� ������ �� ������� ����(�������)
//
//	inline friend void showStack(T &);
//	//--------������� � �������------------------------------------------------------------------------------------
//	int getTop() { //��������� ���-�� ��������� �����
//		return top;
//	}
//	void setTop(int top) {
//		this->top = top;
//	}
//
//	int getSize() { //��������� ������� �����
//		return size;
//	}
//
//	void setSize(int size) { //����������� ������� �����
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
//		stack[++top] = element; //������������ ������ ���� ��������� �������� ���������� �,  ��� �������������
//	}
//}
//template <typename T>
//T Stack<T>::pop() { //�-��� Pop ����������� ������� ������ �� ������� ����(�������)
//	if (top > 0) {    //�������a ������ �� ����, �������a ������ �� ����
//		top--; //���������� �� ������� ����
//		return stack[top + 1]; //������ ������� ��������� �������, �� ���� ����� ��� �������� 2���
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
//	//���������� ������� � ����
//	for (int i = 0; i <t.getSize(); i++, element--)
//		t.push(element);
//
//}
//
//int Menu() {
//	cout << "\n\n\t\t------------<< M E N U >>---------------\n";
//	cout << "\n\t\tPress [1] to show show items in the stack"; //������� 1 ����� ������� �� ����� ���������� �����
//	cout << "\n\t\tPress [2] to automatically fill the stack"; //������� 2 ����� ������������� ��������� ����
//	cout << "\n\t\tPress [3] to add an item to the stack"; //������� 3 ����� �������� ������� � ����
//	cout << "\n\t\tPress [4] to to show the specific item in the stack"; //������� 4 ����� �������� ������������ ������� � �����
//	cout << "\n\t\tPress [5] to delete the item from the stack"; //������� 5 ����� ������� ������� �� �����
//	cout << "\n\t\tPress [6] to clear the stack"; //������� 6 ����� �������� ����
//	cout << "\n\t\tPress [0] to EXIT"; //����� �� ���������
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
//		case SHOW_ALL: system("cls"); showStack(stack); _getch(); system("cls"); break;//���� �� �����
//		case AUTO: system("cls"); addInStack(stack, chr); showStack(stack); _getch(); break;//���������� ������� � ����
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
//	Stack<char> stack; //���������� ����
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