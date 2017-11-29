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
void DoubleLinkedList<T>::add(const T &value)
{
	if (first == NULL) {
		last = first = new Node<T>(value); //���� ���� ���� ������� ������� � ��������� � last � first �� ����
	}
	else {
		last->next = new Node<T>(value); //���� ���� �� ����, �� ���  next ������� �������
		last = last->next; //� last  ��������� �� ����
	}

}

