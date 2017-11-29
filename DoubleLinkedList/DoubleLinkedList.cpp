#include "DoubleLinkedList.h"
#include <iostream>

//реализация ф-ций класса двусвяный список
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
		last = first = new Node<T>(value); //если лист пуст создаем элемент и указываем и last и first на него
	}
	else {
		last->next = new Node<T>(value); //если лист НЕ пуст, то для  next создаем элемент
		last = last->next; //а last  указываем на него
	}

}

