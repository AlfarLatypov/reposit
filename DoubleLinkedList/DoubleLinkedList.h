#pragma once
#include "Node.h"
//описание класса двусвяный список и прототипы его ф-ций 


template< typename T > 
class DoubleLinkedList
{
public:
	Node<T> *first, *last; //списку надо знать первый и последний элемент всего списка

	//пустой конструктор для создания двусвязного списка
	
	DoubleLinkedList();

	~DoubleLinkedList();
	template<typename T>
	void addToLast(const T &);
	template<typename T>
	void addToFirst(const T &);
	//template<typename T>
	//void show();

};

