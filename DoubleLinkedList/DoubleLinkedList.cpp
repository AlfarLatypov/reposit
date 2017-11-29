#include "DoubleLinkedList.h"
#include <iostream>

//���������� �-��� ������ ��������� ������
//template< typename T >
DoubleLinkedList::DoubleLinkedList()
{
	first = last = NULL;
}

//template< typename T >
DoubleLinkedList::~DoubleLinkedList()
{

}

//template<typename T>
void DoubleLinkedList::addToLast(const int &value)
{
	if (first == NULL) {
		last = first = new Node(value); //���� ���� ���� ������� ������� � ��������� � last � first �� ����
	}
	else {
		Node *temp = new Node(value);
		last->next = temp; //���� ���� �� ����, �� ���  next ������� �������
		temp->prev = last; //���� ������� ����� � ��������  
		last = temp; //� last  ��������� �� ����
	}

}

//template<typename T>
void DoubleLinkedList::addToFirst(const int & value)
{
	if (first == NULL) {
		last = first = new Node(value); //���� ���� ���� ������� ������� � ��������� � last � first �� ����
	}
	else {
		Node *temp = new Node(value);
		first->prev = temp; //���� ���� �� ����, �� ���  next ������� �������
		temp->next = first; //���� ������� ����� � ��������  
		first = temp; //� last  ��������� �� ����
	}
}

//template<typename T>
void DoubleLinkedList::show()
{
	if (first == NULL) {
		std::cout << "List is empty" << std::endl;
	}
	else {
		for(Node * temp = first; temp != NULL; temp = temp->next)
			std::cout << temp->value << "\n";


		/*Node<T> *temp = first;
		while (temp != NULL) {
			cout << temp->value << "\t";
			temp = temp->next;
		}*/
	}

}

