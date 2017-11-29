#include <iostream>
#include <string>
#include <iomanip>
#include "DoubleLinkedList.h"
#include "Node.h"
using namespace std;




void main() {

	DoubleLinkedList<int> *a = new DoubleLinkedList<int>();
	a->addToLast(5);
	a->addToLast(6);
	a->addToFirst(4);
	//a->show();


	delete a;
	
}