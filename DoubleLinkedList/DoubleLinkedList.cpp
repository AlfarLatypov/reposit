#include "DoubleLinkedList.h"
#include <iostream>

//���������� �-��� ������ ��������� ������
template< typename T >
DoubleLinkedList<T>::DoubleLinkedList()
{
	first = last = NULL;
}

template< typename T >
DoubleLinkedList<T>::~DoubleLinkedList()
{

}

template<typename T>
void DoubleLinkedList<T>::addToLast(const T &value)
{
	if (first == NULL) {
		last = first = new Node<T>(value); //���� ���� ���� ������� ������� � ��������� � last � first �� ����
	}
	else {
		T *temp = new Node<T>(value);
		last->next = temp; //���� ���� �� ����, �� ���  next ������� �������
		temp->prev = last; //���� ������� ����� � ��������  
		last = temp; //� last  ��������� �� ����
	}

}

template<typename T>
void DoubleLinkedList<T>::addToFirst(const T & value)
{
	if (first == NULL) {
		last = first = new Node<T>(value); //���� ���� ���� ������� ������� � ��������� � last � first �� ����
	}
	else {
		T *temp = new Node<T>(value);
		first->prev = temp; //���� ���� �� ����, �� ���  next ������� �������
		temp->next = first; //���� ������� ����� � ��������  
		first = temp; //� last  ��������� �� ����
	}
}

//template<typename T>
//void DoubleLinkedList<T>::show()
//{
//	if (first == NULL) {
//		cout << "List is empty" << endl;
//	}
//	else {
//		for(Node<T> * temp = first; temp != NULL; temp = temp->next; )
//			cout << temp->value << "\t";
//
//
//		/*Node<T> *temp = first;
//		while (temp != NULL) {
//			cout << temp->value << "\t";
//			temp = temp->next;
//		}*/
//	}
//
//}

