#pragma once

template<class T>
class BSTNode {
	BSTNode* left;
	BSTNode* right;
	T data;

public:
	BSTNode();

	BSTNode* getLeft();
	BSTNode* getRight();
	T getData();

	void setLeft(BSTNode* l);
	void setRight(BSTNode* r);
	void setData(T d);


};


