#include "TREE.h"
#include "NodTree.h"
#include <iostream>

template<typename T>
TREE<T>::TREE()
{

	root = NULL;

}

template<typename T>
TREE<T>::~TREE()
{


}

template<typename T>
void TREE<T>::add(const T &value, NodTree<T> &root = this root)
{
	if (root == NULL) {
		root = new NodTree<T>(value);
	}
	else {
		NodTree<T> *temp = root;
		if (root->value < value) {
			if (root->right == NULL) {
				root->right = new NodTree<T>(value);
			}
			else {
				add(value, root->right);
			}
		}
		else if(root->value >= value){
			if (root->left == NULL) {
				root->left = new NodTree<T>(value);
			}
			else add(value, root->left);
		}
	}

}
