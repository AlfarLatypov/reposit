#pragma once
#include <iostream>
template<typename T>
class NodTree
{
public:
	T value;
	NodTree<T> *left, *right;
	
	NodTree();
		~NodTree();
		NodTree(const T &);
};

