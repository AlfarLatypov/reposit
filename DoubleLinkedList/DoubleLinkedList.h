#pragma once
#include "Node.h"
//�������� ������ ��������� ������ � ��������� ��� �-��� 


//template< typename T > 
class DoubleLinkedList
{
public:
	Node *first, *last; //������ ���� ����� ������ � ��������� ������� ����� ������

	//������ ����������� ��� �������� ����������� ������
	
	DoubleLinkedList();

	~DoubleLinkedList();
	//template<typename T>
	void addToLast(const int &);
	//template<typename T>
	void addToFirst(const int &);
	//template<typename T>
	void show();

};

