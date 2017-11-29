#include "Node.h"
#include <iostream>
//template< typename T >
Node::Node(){}

//template<typename T>
Node::Node(const int& value)
{
	this->value = value; //передаваемое значение
	prev = next = NULL ; //указатели на предыдущий и следущий элемент


}

//template< typename int >
Node::~Node()
{
}
