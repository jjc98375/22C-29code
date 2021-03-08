#pragma once
#include "USD.h"

class BSTNode {
	BSTNode* left;
	BSTNode* right;
	USD data;

public:
	BSTNode();

	BSTNode* getLeft();
	BSTNode* getRight();
	USD getData();

	void setLeft(BSTNode* l);
	void setRight(BSTNode* r);
	void setData(USD d);

};