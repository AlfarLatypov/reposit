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
	template<typename T>
	void addToLast(const T &);
	template<typename T>
	void addToFirst(const T &);
	//template<typename T>
	//void show();

};

