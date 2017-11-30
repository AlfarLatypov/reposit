#pragma once
#include <iostream>

template<typename T>
class TREE
{
public:
	NodTree<T> *root;
	TREE();
	~TREE();
	void add(const T &, const NodTree<T> &);

};

