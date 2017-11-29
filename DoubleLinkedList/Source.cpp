#include <iostream>
#include <string>
#include <iomanip>
#include "DoubleLinkedList.h"
#include "Node.h"
using namespace std;




void main() {

	DoubleLinkedList *a = new DoubleLinkedList();
	a->addToLast(5);
	a->addToLast(6);
	a->addToFirst(4);
	a->show();


	delete a;
	
}