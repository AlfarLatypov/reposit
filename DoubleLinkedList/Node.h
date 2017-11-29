#pragma once

//template< typename T >
class Node
{
public:
	int value;
	Node *prev, *next;

	
	Node();
	
	Node(const int&);

	
	~Node();
};

