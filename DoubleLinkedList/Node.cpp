#include "Node.h"
#include <iostream>
//template< typename T >
Node::Node(){}

//template<typename T>
Node::Node(const int& value)
{
	this->value = value; //������������ ��������
	prev = next = NULL ; //��������� �� ���������� � �������� �������


}

//template< typename int >
Node::~Node()
{
}
