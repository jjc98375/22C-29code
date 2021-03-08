#pragma once

#include "BSTNodeT.h"

template<class T>
BSTNode<T>::BSTNode()
{
	left = nullptr;
	right = nullptr;
	data = NULL;
}

template<class T>
BSTNode<T>* BSTNode<T>::getLeft()
{
	return left;
}

template<class T>
BSTNode<T>* BSTNode<T>::getRight()
{
	return right;
}

template<class T>
T BSTNode<T>::getData()
{
	return data;
}

template<class T>
void BSTNode<T>::setLeft(BSTNode* l)
{
	left = l;
}

template<class T>
void BSTNode<T>::setRight(BSTNode* r)
{
	right = r;
}

template<class T>
void BSTNode<T>::setData(T d)
{
	data = d;
}



//
//template<class T>
//BSTNode* BSTNode<T>::getLeft()
//{
//	return left;
//}
//
//BSTNode* BSTNode::getRight()
//{
//	return right;
//}
//
//template<class T>
//void BSTNode<T>::setLeft(BSTNode* l)
//{
//	left = l;
//}
