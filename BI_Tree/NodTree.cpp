#include "NodTree.h"
#include <iostream>

template<typename T>
NodTree::NodTree()
{
	left = right = NULL;
}

template<typename T>
NodTree<T>::NodTree(const T &value):NodTree()
{
	this->value = value;

}

template<typename T>
NodTree::~NodTree()
{


}
