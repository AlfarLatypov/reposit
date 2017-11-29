#include "DoubleLinkedList.h"
#include <iostream>

//реализация ф-ций класса двусвяный список
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
		last = first = new Node(value); //если лист пуст создаем элемент и указываем и last и first на него
	}
	else {
		Node *temp = new Node(value);
		last->next = temp; //если лист НЕ пуст, то для  next создаем элемент
		temp->prev = last; //ласт имеющий некст у которого  
		last = temp; //а last  указываем на него
	}

}

//template<typename T>
void DoubleLinkedList::addToFirst(const int & value)
{
	if (first == NULL) {
		last = first = new Node(value); //если лист пуст создаем элемент и указываем и last и first на него
	}
	else {
		Node *temp = new Node(value);
		first->prev = temp; //если лист НЕ пуст, то для  next создаем элемент
		temp->next = first; //ласт имеющий некст у которого  
		first = temp; //а last  указываем на него
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

