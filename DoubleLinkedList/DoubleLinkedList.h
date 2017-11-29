#pragma once
#include "Node.h"
//�������� ������ ��������� ������ � ��������� ��� �-��� 


template< typename T > 
class DoubleLinkedList
{
public:
	Node<T> *first, *last; //������ ���� ����� ������ � ��������� ������� ����� ������

	//������ ����������� ��� �������� ����������� ������
	DoubleLinkedList();
	~DoubleLinkedList();

	void add(const T &);

};

