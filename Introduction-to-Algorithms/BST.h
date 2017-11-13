/*
 * TreeNode.h
 *
 *  Created on: 2017年5月11日
 *      Author: xiaoquan
 */

#ifndef BST_H_
#define BST_H_
#include<cstdlib>
using namespace std;

struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode * parents;
	TreeNode(int x) : val(x),left(NULL),right(NULL),parents(NULL){}
};
class BST{

public:
	void InorderTreeWark(TreeNode * root);//中序遍历
	void PreorderTreeWark(TreeNode * root);//前序遍历
	void PostorderTreeWark(TreeNode * root);//后序遍历

	/*给定指向数跟的指针和关键字k,过程TreeSearch返回指向包含关键字k的节点（如果存在的话）
	 * 指针;否则返回空指针NULL*/
	TreeNode * TreeSearch(TreeNode * root,int k);

//	上述递归实现
	TreeNode * ItearativeTreeSearch(TreeNode * root,int k);

	//返回查找二叉树中具有最小关键字的元素节点指针
	TreeNode * TreeMinimun(TreeNode * root);

	//返回查找二叉树中具有最大关键字的元素节点指针
	TreeNode * TreeMaximun(TreeNode * root);

	//返回查找二叉树中当前节点后继节点指针
	TreeNode * TreeSuccessor(TreeNode * root);

	//返回查找二叉树中当前节点前继节点指针
	TreeNode * TreePredecessor(TreeNode * root);

	//查找二叉树插入关键字为z的节点
	void TreeInsert(TreeNode * root,TreeNode * z);

	//查找二叉树删除关键字为z的节点
	TreeNode * TreeDelete(TreeNode * x,TreeNode * z);
};

#endif /* BST_H_ */
