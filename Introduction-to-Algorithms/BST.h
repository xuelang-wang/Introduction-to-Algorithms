/*
 * TreeNode.h
 *
 *  Created on: 2017��5��11��
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
	void InorderTreeWark(TreeNode * root);//�������
	void PreorderTreeWark(TreeNode * root);//ǰ�����
	void PostorderTreeWark(TreeNode * root);//�������

	/*����ָ��������ָ��͹ؼ���k,����TreeSearch����ָ������ؼ���k�Ľڵ㣨������ڵĻ���
	 * ָ��;���򷵻ؿ�ָ��NULL*/
	TreeNode * TreeSearch(TreeNode * root,int k);

//	�����ݹ�ʵ��
	TreeNode * ItearativeTreeSearch(TreeNode * root,int k);

	//���ز��Ҷ������о�����С�ؼ��ֵ�Ԫ�ؽڵ�ָ��
	TreeNode * TreeMinimun(TreeNode * root);

	//���ز��Ҷ������о������ؼ��ֵ�Ԫ�ؽڵ�ָ��
	TreeNode * TreeMaximun(TreeNode * root);

	//���ز��Ҷ������е�ǰ�ڵ��̽ڵ�ָ��
	TreeNode * TreeSuccessor(TreeNode * root);

	//���ز��Ҷ������е�ǰ�ڵ�ǰ�̽ڵ�ָ��
	TreeNode * TreePredecessor(TreeNode * root);

	//���Ҷ���������ؼ���Ϊz�Ľڵ�
	void TreeInsert(TreeNode * root,TreeNode * z);

	//���Ҷ�����ɾ���ؼ���Ϊz�Ľڵ�
	TreeNode * TreeDelete(TreeNode * x,TreeNode * z);
};

#endif /* BST_H_ */
