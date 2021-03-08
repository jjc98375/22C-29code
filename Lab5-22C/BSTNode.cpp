#pragma once

#include "BSTNode.h"

BSTNode::BSTNode()
{
	left = nullptr;
	right = nullptr;
	//data = NULL;
}


BSTNode* BSTNode::getLeft()
{
	return left;
}


BSTNode* BSTNode::getRight()
{
	return right;
}

USD BSTNode::getData()
{
	return data;
}

void BSTNode::setLeft(BSTNode* l)
{
	left = l;
}

void BSTNode::setRight(BSTNode* r)
{
	right = r;
}

void BSTNode::setData(USD d)
{
	data = d;
}


