#include "Node.h"
#include <iostream>

template< typename T >
Node<T>::Node(){}

template<typename T>
Node<T>::Node(const T& value)
{
	this->value = value; //передаваемое значение
	prev = next = NULL ; //указатели на предыдущий и следущий элемент


}

template< typename T >
Node<T>::~Node()
{
}
