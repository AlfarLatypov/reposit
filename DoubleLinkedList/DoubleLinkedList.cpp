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
void DoubleLinkedList<T>::addToLast(const T &value)
{
	if (first == NULL) {
		last = first = new Node<T>(value); //если лист пуст создаем элемент и указываем и last и first на него
	}
	else {
		T *temp = new Node<T>(value);
		last->next = temp; //если лист НЕ пуст, то для  next создаем элемент
		temp->prev = last; //ласт имеющий некст у которого  
		last = temp; //а last  указываем на него
	}

}

template<typename T>
void DoubleLinkedList<T>::addToFirst(const T & value)
{
	if (first == NULL) {
		last = first = new Node<T>(value); //если лист пуст создаем элемент и указываем и last и first на него
	}
	else {
		T *temp = new Node<T>(value);
		first->prev = temp; //если лист НЕ пуст, то для  next создаем элемент
		temp->next = first; //ласт имеющий некст у которого  
		first = temp; //а last  указываем на него
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

