/*
 * TreeNode.cpp
 *
 *  Created on: 2017��5��11��
 *      Author: xiaoquan
 */
#include<iostream>
#include "BST.h"

void BST::InorderTreeWark(TreeNode * root){
	if(root != NULL){
		InorderTreeWark(root->left);
		cout << root->val << ", ";
		InorderTreeWark(root->right);
	}
}

void BST::PreorderTreeWark(TreeNode * root){
	if(root != NULL){
		cout << root->val << ", ";
		PreorderTreeWark(root->left);
		PreorderTreeWark(root->right);
	}
}

void BST::PostorderTreeWark(TreeNode * root){
	if(root != NULL){
		PostorderTreeWark(root->left);
		PostorderTreeWark(root->right);
		cout << root->val << ", ";
	}
}

TreeNode * BST::TreeSearch(TreeNode * root,int k){
	if(root == NULL || root->val == k)
		return root;
	if(k < root->val)
		return TreeSearch(root->left,k);
	else
		return TreeSearch(root->right,k);
}

TreeNode * BST::ItearativeTreeSearch(TreeNode * root,int k){
	while(root != NULL && root->val != k){
		if(root->val > k)
			root = root->left;
		else
			root = root->right;
	}
	return root;
}

//���ز��Ҷ������о�����С�ؼ��ֵ�Ԫ�ؽڵ�ָ��
TreeNode * BST::TreeMinimun(TreeNode * root){
	if(root != NULL)
		while(root->left != NULL)
			root = root->left;
	return root;
}
//���ز��Ҷ������о������ؼ��ֵ�Ԫ�ؽڵ�ָ��
TreeNode * BST::TreeMaximun(TreeNode * root){
	if(root != NULL)
		while(root->right != NULL)
			root = root->right;
	return root;
}


TreeNode * BST::TreeSuccessor(TreeNode * root){
	if(root->right != NULL)
		return TreeMinimun(root->right);
	TreeNode * p = root->parents;
	while(p != NULL && root == p->right){
		root = p;
		p = p->parents;
	}
	return p;
}

TreeNode * BST::TreePredecessor(TreeNode * root){
	if(root->left != NULL)
		return TreeMaximun(root->left);
	TreeNode * p = root->parents;
	while(p != NULL && root == p->left){
		root = p;
		p = p->parents;
	}
	return p;
}

void BST::TreeInsert(TreeNode * root,TreeNode * z){
	TreeNode * y = NULL;
	TreeNode * x = root;
	while(x != NULL){
		y = x;
		if(z->val < y->val)
			x = x->left;
		else
			x = x->right;
	}
	z->parents = y;
	if(y == NULL)
		root = z;
	else if(z->val < y->val)
		y->left = z;
	else
		y->right = z;

}

TreeNode * BST::TreeDelete(TreeNode * x,TreeNode * z){
	TreeNode * y;//Ҫɾ���Ľڵ�
	//���Ҫɾ���Ľڵ�
	if(z->left == NULL || z->right == NULL)
		y = z;
	else
		y = TreeSuccessor(z);

	//ɾ���Ľڵ�y����ֻ��һ�����ӣ�������
	if(y->left != NULL)
		x = y->left;
	else
		x = y->right;

	//ɾ������
	if(x != NULL)
		x->parents = y->parents;
	if(y == y->parents->left)
		y->parents->left = x;
	else
		y->parents->right = x;
	//��y�滻z
	if(y != z)
		z->val = y->val;
	return y;

}





